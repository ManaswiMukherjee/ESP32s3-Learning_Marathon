# DAY-1 15/08/2026

## 1. Ran into build errors

Cannot use special characters for project names other wise.
`:` was treated as a file name in itself.
Hence naming convention for this project from now on is `Day_n-Project_Name`

## 2. Red squiggles appear in include lines in code.

 * Added the line ``CompilationDatabase: "build" `` in `.clangd` file
 * Modified the `"compileCommands":` line to `"compileCommands": "${workspaceFolder}/build/compile_commands.json",` as my system uses Microsoft C/C++ IntelliSense

## 3. Template code is too complex switching to simpler code.
--- 

# Esp32 ALWAYS runs on top of FreeRTOS
---
## 4. How to upload code?
idf.py -p PORT flash monitor

## 5. What is gpio_reset_pin()?
Removes any prior configurations that may have been used in the boot process. Just a safety measure.

# DAY-2 16/08/2026

## 1. What is the difference between oneshot and continuous mode in esp32 adc?
Oneshot mode - The adc takes one measurement and then stops. Next measurement must be manually triggered.

Continuous mode - The adc continuously takes measurements, the user can read whenever they want.

## 2. Simplified example code

## 3. What is thread safe?
One function or a piece of code can be used my multiple threads at a time without race conditions or corrupted data.

## 4. Why add calibration drivers seperately?
During manufacturing the calibration error is etched into chip seperately, this calibration driver allows one to calibrate data to voltage without any errors as compared to converting the data by oneself. Reference voltage for each chip is different due to manufacturing process.

## 5. What are they deletion functions in the user guide just after adc handle creations?
They are teardown/cleanup functions that are used when the handle is no longer used.

## 6. ADC handle and Calibration handle are 2 different things

## 7. Why is it necessary to use NULL for the callibration handle?
If by chance cali_handle fails to initialize for some reason then there will be a pointer runtime error. So play safe will NULL.