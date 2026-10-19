# HalfLife Drone
This is the project for week one and two of **Half Life**

It's an extension for an ESP32 S3 that allows it to safely control 4 coreless DC motors and get data from an IMU and Barometer units. Meaning it's prepared to be used in a quadcopter. And a frame for the drone itself.

Here's a nice render of the PCB.
![img](/Screenshot_20261011_232057.png)

And here's a nice render of the frame.
![img](/cover_image_week_2.png)

## Structure
 - `esp_extension/` - KiCad files (including production files under `esp_extension/production`)
 - `motor_test/` - A quick test with an AI generated script for driving the coreless motor
- `frame/` - Files for week 2
