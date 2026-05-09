# EEZ_Studio_CrowPanel_ESP32_S3_7.0

Professional EEZ Studio + LVGL + PlatformIO integration for the **ELECROW CrowPanel ESP32-S3 7.0 Inch HMI Display**.

This repository provides a clean and scalable development environment for building modern embedded GUI applications using **LVGL**, **EEZ Studio**, and **ESP32-S3**.

---

## Product Information

- **Board:** ELECROW CrowPanel ESP32-S3 7.0"
- **Display Resolution:** 800 × 480
- **Display Type:** RGB TFT LCD
- **Touch Support:** Capacitive Touch
- **MCU:** ESP32-S3

### Official Product Page

- https://www.elecrow.com/esp32-display-7-inch-hmi-display-rgb-tft-lcd-touch-screen-support-lvgl.html

---

# Features

- Integrated EEZ Studio Workflow
- LVGL Framework Support
- PlatformIO Project Structure
- ESP32-S3 Optimized Configuration
- 800×480 RGB Display Support
- Capacitive Touch Integration
- Beginner Friendly Setup
- Clean Modular Project Structure

---

# Software Requirements

Install the following tools before getting started:

| Tool | Purpose |
|---|---|
| VS Code | Development Environment |
| PlatformIO Extension | ESP32 Build & Flash |
| EEZ Studio | GUI Design & UI Generation |

---

# 1. Getting Started

## Clone the Repository

```bash
git clone https://github.com/Arvinth-Krishna/EEZ_Studio_CrowPanel_ESP32_S3_7.0.git
```

---

## Open the Project

1. Open **VS Code**
2. Open the cloned project folder
3. Wait for PlatformIO initialization

---

## Build the Firmware

### Using Terminal

```bash
pio run
```

### Using PlatformIO UI

- Open the **PlatformIO Sidebar**
- Click:
  - **Build**

---

# 2. Creating UI with EEZ Studio

## Create EEZ Flow Project

1. Open **EEZ Studio**
2. Create:
   - **EEZ Flow Project**

---

## Verify LVGL Version

The LVGL version used in:

- **EEZ Studio**
- **platformio.ini**

must match exactly.

### Example

```ini
lib_deps =
    lvgl/lvgl@8.3.11
```

> Version mismatch may cause build failures or runtime rendering issues.

---

## Configure UI Output Folder

Inside EEZ Studio:

1. Open:
   - `Build Settings`
2. Set:
   - `Destination Folder`

### Example

```text
YOUR_PROJECT/lib/ui
```

---

## Generate UI Source Files

- Click:
  - **Build**

EEZ Studio will automatically generate all required UI source files.

---

# 3. Flashing Firmware to ESP32-S3

## Connect the Board

Connect the CrowPanel display board to your PC using USB.

---

## Upload Firmware

### Using Terminal

```bash
pio run --target upload
```

### Using PlatformIO UI

- Open the **PlatformIO Sidebar**
- Click:
  - **Upload**

---

# Common Issue

## LVGL Version Mismatch

### Symptoms

- Build errors
- Blank display
- UI rendering problems
- Random crashes

### Solution

Ensure both versions match:

- EEZ Studio LVGL Version
- `platformio.ini` LVGL Version

---

# Recommended Workflow

```text
Design UI in EEZ Studio
            ↓
Generate UI Source Files
            ↓
Build using PlatformIO
            ↓
Flash Firmware to ESP32-S3
            ↓
Test and Iterate
```

---

# Project Structure

```text
.
├── lib/
│   └── ui/            # Generated EEZ Studio UI files
├── src/               # Application source files
├── include/           # Header files
├── platformio.ini     # PlatformIO configuration
└── README.md
```

---

# Credits

- EEZ Studio
- LVGL
- PlatformIO
- ELECROW
- ESP32 Community

---

# Support

If this repository helped you, consider giving it a ⭐ on GitHub.
