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