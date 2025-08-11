# ACS758_testing
# ACS758 Current Sensor Testing

This repository contains an Arduino sketch for testing and calibrating the **ACS758 Hall-effect current sensor**. The code reads the analog voltage output from the sensor, converts it to the corresponding current value, and prints it to the Serial Monitor for real-time monitoring.

## Features
- Reads analog output from ACS758 sensor
- Converts ADC readings to voltage
- Calculates current using sensor sensitivity
- Adjustable offset for calibration
- Serial output for easy debugging

## Hardware Requirements
- **Arduino UNO/Nano/compatible board**
- **ACS758 Current Sensor** (adjust sensitivity in code for your specific model)
- Jumper wires
- Load for current measurement

## Wiring
| ACS758 Pin | Arduino Pin |
|------------|-------------|
| Vcc        | 5V          |
| GND        | GND         |
| OUT        | A0          |

## Code Explanation
- **Voltage Conversion:**  
  ```cpp
  voltage = analogValue * (5.0 / 1023.0);
current = (voltage - 2.4935) / 0.066;
Converts raw ADC readings to voltage.

Current Calculation:

cpp
Copy
Edit
current = (voltage - 2.4935) / 0.066;
Subtracts the offset voltage (calibration point) and divides by sensitivity (V/A).

Note: For ACS758 models, sensitivity varies by variant:

ACS758-050B → 40 mV/A

ACS758-100B → 20 mV/A

ACS758-200B → 10 mV/A
Update the 0.066 value according to your sensor's datasheet.

Usage
Connect the ACS758 to your Arduino as per the wiring table.

Upload the code from ACS758_TESTING.ino.

Open the Serial Monitor (9600 baud) to view live current readings.

Adjust the offset voltage in the code for accurate zero-current calibration.

Example Output
makefile
Copy
Edit
Current: 0.15 A
Current: 0.17 A
Current: 0.16 A
Calibration
With no load connected, note the voltage output from the sensor.

Replace 2.4935 in the code with your measured zero-current voltage.
