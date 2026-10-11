// Single motor breadboard test (design_notes.md section 9), Arduino Uno / Nano (ATmega328P).
//
// Wiring:
//   Pin 9 -> 100-220 Ohm -> MOSFET gate, 10 kOhm gate -> source
//   Arduino GND -> MOSFET source (= battery -)
//   Arduino powered from USB only, battery + never touches the Arduino
//
// Serial monitor at 115200 baud, line ending "Newline":
//   0..MAX_DUTY_PERCENT  set target duty in %, ramps up slowly
//   s (or empty line)    stop immediately
//
// The motor also stops by itself after RUN_LIMIT_MS, send a duty again to continue.

const uint8_t MOTOR_PIN = 9;          // OC1A, Timer1
const uint16_t PWM_TOP = 400;         // 16 MHz / (2 * 400) = 20 kHz, phase-correct
const uint8_t MAX_DUTY_PERCENT = 20;  // hard clamp, nothing above this is ever written
const uint16_t RAMP_STEP_MS = 5;      // 1 count per 5 ms -> 0 to 20% in about 0.4 s
const uint32_t RUN_LIMIT_MS = 30000;  // auto-stop after 30 s

const uint16_t MAX_COUNTS = (uint32_t)PWM_TOP * MAX_DUTY_PERCENT / 100;

uint16_t currentCounts = 0;
uint16_t targetCounts = 0;
uint32_t lastRampMs = 0;
uint32_t runStartMs = 0;

char lineBuf[16];
uint8_t lineLen = 0;

void writeDuty(uint16_t counts) {
  if (counts > MAX_COUNTS) counts = MAX_COUNTS;
  OCR1A = counts;
  currentCounts = counts;
}

void stopMotor(const __FlashStringHelper *reason) {
  targetCounts = 0;
  writeDuty(0);
  Serial.print(F("STOP: "));
  Serial.println(reason);
}

void setupPwm() {
  // Phase-correct PWM, TOP = ICR1 (mode 10), non-inverting on OC1A, no prescaler.
  // OCR1A = 0 keeps the output constantly low.
  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 0;
  ICR1 = PWM_TOP;
  TCCR1A = _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(WGM13) | _BV(CS10);
}

void handleLine(char *line) {
  if (line[0] == '\0' || line[0] == 's' || line[0] == 'S') {
    stopMotor(F("command"));
    return;
  }

  for (char *p = line; *p; p++) {
    if (*p < '0' || *p > '9') {
      stopMotor(F("not a number"));
      return;
    }
  }

  int percent = atoi(line);
  if (percent > MAX_DUTY_PERCENT) {
    Serial.print(F("Clamped to "));
    Serial.print(MAX_DUTY_PERCENT);
    Serial.println(F("%"));
    percent = MAX_DUTY_PERCENT;
  }

  if (percent == 0) {
    stopMotor(F("command"));
    return;
  }

  targetCounts = (uint32_t)PWM_TOP * percent / 100;
  runStartMs = millis();
  Serial.print(F("Target "));
  Serial.print(percent);
  Serial.println(F("%"));
}

void readSerial() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\r') continue;
    if (c == '\n') {
      lineBuf[lineLen] = '\0';
      handleLine(lineBuf);
      lineLen = 0;
    } else if (lineLen < sizeof(lineBuf) - 1) {
      lineBuf[lineLen++] = c;
    }
  }
}

void setup() {
  // Drive the gate low before anything else.
  digitalWrite(MOTOR_PIN, LOW);
  pinMode(MOTOR_PIN, OUTPUT);
  setupPwm();

  Serial.begin(115200);
  Serial.println(F("Motor test ready. Send 0-20 (duty %), 's' to stop."));
}

void loop() {
  readSerial();

  if (targetCounts > 0 && millis() - runStartMs > RUN_LIMIT_MS) {
    stopMotor(F("run time limit"));
  }

  // Ramp up slowly, go down immediately.
  if (targetCounts < currentCounts) {
    writeDuty(targetCounts);
  } else if (targetCounts > currentCounts && millis() - lastRampMs >= RAMP_STEP_MS) {
    lastRampMs = millis();
    writeDuty(currentCounts + 1);
  }
}
