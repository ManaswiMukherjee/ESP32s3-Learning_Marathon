# ADC Single Read Example

This example demonstrates the following:

- How to obtain a oneshot ADC reading from a GPIO pin using the ADC oneshot mode driver
- How to use the ADC Calibration functions to obtain a calibrated result (in mV)

## How to use example

### Hardware Required

* A development board with ESP SoC
* A USB cable for power supply and programming
* A potentiometer
* Connecting wires

### Build and Flash

Build the project and flash it to the board, then run monitor tool to view serial output:

```
idf.py -p PORT flash monitor
```

(To exit the serial monitor, type ``Ctrl-]``.)