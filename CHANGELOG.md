# DAY-1 15/08/2026

## 1. Ran into build errors

Cannot use special characters for project names other wise.
`:` was treated as a file name in itself.
Hence naming convention for this project from now on is `Day_n-Project_Name`

## 2. Red squiggles appear in include lines in code.

 * Added the line ``CompilationDatabase: "build" `` in `.clangd` file
 * Modified the `"compileCommands":` line to `"compileCommands": "${workspaceFolder}/build/compile_commands.json",` as my system uses Microsoft C/C++ IntelliSense

## 3. Template code is too complex switching to simpler code.

# Esp32 ALWAYS runs on top of FreeRTOS

## 4. How to upload code?
idf.py -p PORT flash monitor

## 5. What is gpio_reset_pin()?
Removes any prior configurations that may have been used in the boot process. Just a safety measure.
---
---
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
---
---
# DAY-3 17/08/2026

## 1. There is a definition given at the top of the code. when i hover my cursor over the config i2c master scl, then it shows 4, where is the 4 written? is it in a header file? where is it?
It is the idf's kconfig system, editable by running `idf.py menuconfig`

## 2. NACK is not being answered
Checking wiring - Wiring was loose

## 3. Every acceleration value is showing as 112g.
Copy paste bug

### Data is 16 bit's compliment so use int.
### Created seperate variables for raw values and acceleration data

---
---
# DAY-4 18/08/2026

## 1. What is NVS?
NVS stands for non volatile storage. It stores wifi data and other metadata to connect to wifi fast

## 2. What is `ESP_ERR_NVS_NO_FREE_PAGES` and `ESP_ERR_NVS_NEW_VERSION_FOUND`?
* ESP_ERR_NVS_NO_FREE_PAGES - The nvs partition is full
* ESP_ERR_NVS_NEW_VERSION_FOUND - The nvs data format changed

Both lead to the nvs being unusable so the fix is erase the data and reinit the nvs with new data

# DAY-5 19/08/2026
## This example is a model trained to predict the value of `sin` at a particular point

## 1. Environment was not getting activated
Activated the environment through bottom left option of `ESP-IDF vx.x`

## 2. Red squiggles appeared again
* Shifted to clangd
* Ran `idf.py reconfigure` to generate build directory
* Changed the line from `  "C_Cpp.intelliSenseEngine": "default",` to `  "C_Cpp.intelliSenseEngine": "disabled",`

## 3. Why are all the files with an extension `.cc` instead of `.c`
The tflite-micro is written in cpp and one of the was to store cpp files is through `.cc` extension.

## 4. Work of all the files in `main` folder
* main.cc - The actual entry point to `app_main()`, it is intentionaly tiny, with just a `setup()` and `loop()` function so as the arduino ide code looks similar to this.
* model.h/model.cc - Contains the weights of the pretrained model. Mostly data.
* main_functions.h/main_functions.cc - Contains the actual logic split into two parts\
`setup()` - Loads the model from the byte array in model.cc, allocated continuous memory for execution of the model and handles input/output pointers.\
`loop()` - Just increments x and takes outputs of y for each x continuously
* output_handler.cc/output_handler.h - Controls how the output of the model is displayed through LED or some other means

### * Trying to make the LED breathe now