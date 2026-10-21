# HalfLife Drone
This is the project for week one and two of **Half Life**

It's an extension for an ESP32 S3 that allows it to safely control 4 coreless DC motors and get data from an IMU and Barometer units. Meaning it's prepared to be used in a quadcopter. And a frame for the drone itself.

Here's a nice render of the PCB.
![img](/Screenshot_20261011_232057.png)

And here's a nice render of the frame.
![img](/cover_image_week_2.png)


## BOM for week 1

### Assembled by JLCPCB (2 boards)

| Designator | Value | Footprint | Qty / board | Part # | Qty ordered* | Price | Source | Funded by |
| - | - | - | - | - | - | - | - | - |
| C1-C3, C8, C13 | 22u | 0805 | 5 | [C45783](https://www.lcsc.com/product-detail/C45783.html) | 10 | $2.21 | JLCPCB Assembly | Grant |
| C4, C5, C7, C9-C11, C14 | 100n | 0603 | 7 | [C14663](https://www.lcsc.com/product-detail/C14663.html) | 14 | $0.20 | JLCPCB Assembly | Grant |
| D1-D4 | SS34 | SMA | 4 | [C8678](https://www.lcsc.com/product-detail/C8678.html) | 8 | $0.28 | JLCPCB Assembly | Grant |
| D5 | SMBJ5.0A | SMB | 1 | [C19077558](https://www.lcsc.com/product-detail/C19077558.html) | 5 | $0.24 | JLCPCB Assembly | Grant |
| D6 | B5819W | SOD-123 | 1 | [C8598](https://www.lcsc.com/product-detail/C8598.html) | 2 | $0.06 | JLCPCB Assembly | Grant |
| D7, D8 | Red LED | 0603 | 2 | [C2286](https://www.lcsc.com/product-detail/C2286.html) | 4 | $0.03 | JLCPCB Assembly | Grant |
| L1 | 0.47 µH | 2016 | 1 | [C668312](https://www.lcsc.com/product-detail/C668312.html) | 5 | $0.89 | JLCPCB Assembly | Grant |
| Q1-Q4 | AO3400A | SOT-23 | 4 | [C20917](https://www.lcsc.com/product-detail/C20917.html) | 8 | $0.71 | JLCPCB Assembly | Grant |
| R1, R2, R10, R11 | 100 | 0603 | 4 | [C22775](https://www.lcsc.com/product-detail/C22775.html) | 8 | $0.02 | JLCPCB Assembly | Grant |
| R3, R4, R7, R13-R16 | 10k | 0603 | 7 | [C25804](https://www.lcsc.com/product-detail/C25804.html) | 14 | $0.03 | JLCPCB Assembly | Grant |
| R5, R8, R9 | 100k | 0603 | 3 | [C25803](https://www.lcsc.com/product-detail/C25803.html) | 6 | $0.02 | JLCPCB Assembly | Grant |
| R6 | 56k | 0603 | 1 | [C23206](https://www.lcsc.com/product-detail/C23206.html) | 2 | $0.01 | JLCPCB Assembly | Grant |
| R17, R18 | 1k | 0603 | 2 | [C21190](https://www.lcsc.com/product-detail/C21190.html) | 4 | $0.01 | JLCPCB Assembly | Grant |
| U2 | TPS63802DLAR | VSON-10 | 1 | [C2845237](https://www.lcsc.com/product-detail/C2845237.html) | 2 | $1.81 | JLCPCB Assembly | Grant |
| U3 | MS5611-01BA | LGA-8 | 1 | [C15639](https://www.lcsc.com/product-detail/C15639.html) | 2 | $13.43 | JLCPCB Assembly | Grant |
| | | | | | | **$19.94** | | |

- `*` Some parts have a minimum order quantity amount (like the L1), that's why there's more ordered then I need

### Hand-soldered (bought by me)


| Designator | Value | Footprint | Qty / board | URL | Price | Source | Funded by |
| - | - | - | - | - | - | - | - |
| C6 | 220u 16V electrolytic | Radial D6.3 mm, 2.5 mm pitch | 1 | [Radiokus](https://www.radiokus.cz/220uF-16V-elektrolyticky-radialni-kondenzator-d2327.htm) | 3 Kč | Self-sourced | Me |
| SW1 | S103mini SPDT slide switch | 3 pin, 2.54 mm | 1 | [Radiokus](https://www.radiokus.cz/Posuvny-prepinac-jednoduchy-do-DPS-d4843.htm) | 7 Kč | Self-sourced | Me |
| J5, J7, J10 | Female header 1x40, cut to 1x22 + 1x22 + 1x08 | 2.54 mm | 2 strips | [Radiokus](https://www.radiokus.cz/zasuvka-1-x-40-pinu-do-dps-prima-rastr-2-54mm) | 50 Kč | Self-sourced | Me |
| J8, J9 | Male header 1x11, cut to 1x04 + 1x06 | 2.54 mm | 1 strip | [Radiokus](https://www.radiokus.cz/Vidlice-1-x-11-pinu-do-DPS-prima-rastr-2-54mm-d3864.htm) | 8 Kč | Self-sourced | Me |

### Funding request (JLCPCB order)

| Item | Price |
| - | - |
| PCB (5 pcs, 4 layer) | $8.00 |
| Assembly setup fee | $8.24 |
| Components | $19.94 |
| Extended components fee | $9.27 |
| SMT assembly | $0.38 |
| Confirm parts placement | $0.45 |
| Other order options | $2.41 |
| Shipping | $9.32 |
| Customs duties & taxes | $17.07 |
| Discount coupon | -$10.00 |
| **Total** | **$65.08** |


Here's the BOM as a csv: [BOM.csv](/BOM.csv)

## Structure
 - `esp_extension/` - KiCad files (including production files under `esp_extension/production`)
 - `motor_test/` - A quick test with an AI generated script for driving the coreless motor
- `frame/` - Files for week 2
