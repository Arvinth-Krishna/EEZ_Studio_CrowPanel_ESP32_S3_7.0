# EEZ_Studio_CrowPanel_ESP32_S3_7.0

EEZ Studio + LVGL + PlatformIO integration for the ELECROW ESP32-S3 7.0 Inch HMI Display (800x480 RGB TFT LCD Touch Screen).

Simple and beginner-friendly setup for building embedded GUI applications on ESP32-S3.

Product Link: https://www.elecrow.com/esp32-display-7-inch-hmi-display-rgb-tft-lcd-touch-screen-support-lvgl.html?srsltid=AfmBOoo0fakNLm7ErZvLYBqXlPKS8sv678TugMUJV9_ufwB0YE1CkzPy

---

# Features

- EEZ Studio Integration
- LVGL Support
- PlatformIO Ready
- ESP32-S3 Compatible
- 800x480 RGB Display Support
- Touchscreen Support

---

# Hardware

- ELECROW CrowPanel ESP32-S3 7.0"
  - RGB TFT LCD
  - Capacitive Touch
  - 800x480 Resolution

---

# Requirements

Install the following before starting:

- VS Code
- PlatformIO Extension
- EEZ Studio

---

# 1) Getting Started

## 1. Clone the Repository

```bash
git clone https://github.com/Arvinth-Krishna/EEZ_Studio_CrowPanel_ESP32_S3_7.0.git
```


## 2. Open in VS Code

- Open VS Code
- Open the project folder
- Wait for PlatformIO initialization


## 3. Build the Project

### Using Terminal

```bash
pio run
```

### Using PlatformIO

- Open PlatformIO Sidebar
- Click:
  - **Build**

---

# 2) Creating UI with EEZ Studio

## 1. Create EEZ Flow Project

- Open EEZ Studio
- Create:
  - **EEZ Flow Project**


## 2. Match LVGL Version

Ensure the LVGL version matches in:

- EEZ Studio
- `platformio.ini`

Example:

```ini
lib_deps =
    lvgl/lvgl@8.3.11
```


## 3. Configure Build Output

In EEZ Studio:

- Go to:
  - `Build Settings`
- Set:
  - `Destination Folder`

Example:

```text
YOUR_PROJECT/lib/ui
```


## 4. Generate UI Files

- Click:
  - **Build**

EEZ Studio will generate the UI source files automatically.

---

# 3) Flashing Firmware to ESP32-S3

## 1. Connect the Display

- Connect the CrowPanel display using USB


## 2. Upload Firmware

### Using Terminal

```bash
pio run --target upload
```

### Using PlatformIO

- Open PlatformIO Sidebar
- Click:
  - **Upload**

---

# Common Issue

## LVGL Version Mismatch

If you face:

- Build errors
- UI crashes
- Rendering issues

Make sure the LVGL versions match in:

- EEZ Studio
- `platformio.ini`

---

# Workflow

```text
EEZ Studio UI Design
        ↓
Generate UI Files
        ↓
PlatformIO Build
        ↓
Upload to ESP32-S3
```

---

# Credits

- EEZ Studio
- LVGL
- PlatformIO
- ELECROW
- ESP32 Community

---

⭐ Star the repository if this project helped you.
