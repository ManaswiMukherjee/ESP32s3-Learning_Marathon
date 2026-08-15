# Environment Setup

This document is for replicating the exact environment this repo was built and tested with — separate from the day-by-day README, which covers what each project does.

## Toolchain

- **ESP-IDF version: v6.0.2** — pin this specifically, not "latest." APIs used here (e.g. `led_strip`, ADC oneshot calibration) can shift between IDF versions, and a newer version isn't guaranteed to build these projects unmodified.
- **Target chip: `esp32s3`**
- Install via Espressif's official installer for your OS: https://docs.espressif.com/projects/esp-idf/en/stable/esp32s3/get-started/index.html
- When the installer asks which ESP-IDF version to install, select **v6.0.2** explicitly.

## Activating the environment

ESP-IDF is not on your shell's PATH by default — it has to be activated every new terminal session, it doesn't persist.

**Linux / macOS**, from a plain terminal:
```
. $HOME/esp/esp-idf/export.sh
```
(adjust the path to wherever ESP-IDF actually got installed on your machine)

Optional convenience — add to `~/.bashrc`:
```
alias get_idf='. $HOME/esp/esp-idf/export.sh'
```
Then just run `get_idf` in any new terminal.

**In VS Code**, with the official "ESP-IDF" extension installed: Command Palette (`Ctrl+Shift+P`) → `ESP-IDF: Open ESP-IDF Terminal`. This activates the environment automatically — use this instead of a plain integrated terminal for anything in this repo.

## Linux: serial port permissions

Flashing over USB requires your user to be in the `dialout` group:
```
sudo usermod -aG dialout $USER
```
Log out and back in (or reboot) for it to take effect. Without this, `idf.py flash` will fail with a permissions error on `/dev/ttyUSB0` (or similar).

## Building any project in this repo

Each `dayN_*` folder is a self-contained ESP-IDF project. From inside one:
```
idf.py set-target esp32s3
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
```
(replace the port with whatever shows up under `ls /dev/tty*` when your board is plugged in — `/dev/cu.usbserial-*` on macOS)

Note: `sdkconfig` is intentionally not committed to this repo. Running `set-target` regenerates it from `sdkconfig.defaults` + `sdkconfig.defaults.esp32s3`, so this step is required on a fresh clone — it's not optional boilerplate.

## Board-specific note

ESP32-S3 dev boards differ on whether the onboard LED is a plain GPIO LED or an addressable WS2812 RGB LED. If Day 1's blink doesn't light anything after flashing:
```
idf.py menuconfig
```
→ Example Configuration → check the LED type and GPIO number match your specific board (check its schematic or silkscreen for the actual pin).

## Naming convention

Folder names and CMake project names in this repo use only letters, digits, and underscores — no spaces, colons, or `&`. ESP-IDF's CMake/Ninja build breaks on these characters in the project path, so keep any new folders you add to the same convention.