# HamShield Radio

> Embedded radio development platform based on the **RDA1846** transceiver.

HamShield Radio is a low-level embedded project focused on developing a software interface for the **RDA1846** radio transceiver IC.

The project is being developed incrementally, starting with the communication layer and basic register access before moving toward complete radio configuration and operation.

---

## ✨ Current Focus

The current stage of the project is intentionally small:

- Build the firmware using **PlatformIO**
- Upload firmware entirely from the command line
- Establish serial communication at **9600 baud**
- Develop the RDA1846 register communication layer
- Begin testing register-level communication

> **Development principle:** build and verify one communication layer at a time before adding higher-level radio functionality.

---

## 📁 Project Structure

```text
HamShield_Radio/
├── compile_commands.json
├── include/
│   ├── HamShield_comms.h
│   └── README
├── lib/
│   └── README
├── platformio.ini
├── src/
│   ├── HamShield_comms.c
│   └── main.cpp
└── test/
    └── README
```

### Directory Overview

| Path | Purpose |
| --- | --- |
| `src/` | Application and communication source code |
| `include/` | Project header files |
| `lib/` | Project-specific libraries |
| `test/` | Test code |
| `platformio.ini` | PlatformIO project configuration |
| `compile_commands.json` | Compilation database for development tools |

### Core Source Files

#### `src/main.cpp`

Contains the main firmware entry point and the current application-level testing code.

#### `src/HamShield_comms.c`

Contains the low-level communication implementation used to communicate with the RDA1846.

#### `include/HamShield_comms.h`

Defines the public communication API used by the application.

---

# 📻 RDA1846

The **RDA1846** is the radio transceiver IC at the center of the HamShield Radio project.

The purpose of this project is to build a low-level software interface that allows the microcontroller to communicate with the RDA1846 and configure its internal registers.

The communication layer is being developed around register-level access, providing operations such as:

```text
Read Register
Write Register
Read Bit
Write Bit
Read Bit Field
Write Bit Field
```

The initial hardware interface uses three signals:

```text
┌───────────────┐
│   Controller  │
│               │
│     nSEN ──────────► Serial Enable
│     CLK  ──────────► Clock
│     DAT  ◄─────────► Data
│               │
└───────────────┘
         │
         ▼
   ┌────────────┐
   │  RDA1846   │
   │ Transceiver│
   └────────────┘
```

The exact register configuration and radio functionality will be developed progressively as the communication layer is verified.

---

# 🔌 Communication API

The current public API is provided by:

```text
include/HamShield_comms.h
```

The main operations are:

```cpp
HSreadBitW()
HSreadBitsW()
HSreadWord()

HSwriteBitW()
HSwriteBitsW()
HSwriteWord()
```

For example, a complete 16-bit register read is performed through:

```cpp
uint16_t data;

HSreadWord(nSEN, 0x30, &data);
```

This allows the application layer to work with the RDA1846 without directly implementing the communication sequence each time.

---

# 🛠️ Build Environment

The project uses **PlatformIO** as its build system.

The project can be built entirely from the terminal.

No IDE-specific workflow is required.

## Requirements

Install:

- PlatformIO
- A supported PlatformIO development environment
- The appropriate USB/serial permissions for the target board

Verify PlatformIO:

```bash
pio --version
```

---

# 🔨 Building the Project

Enter the project directory:

```bash
cd ~/Project_Workspace/platformio/HamShield_Radio
```

Build the firmware:

```bash
pio run
```

PlatformIO will compile the source files and generate the build output under:

```text
.pio/
```

A successful build should finish with a message similar to:

```text
========================= [SUCCESS] =========================
```

---

# 🚀 Uploading Firmware

Connect the development board to the computer.

First, identify the available serial devices:

```bash
pio device list
```

You can also check directly:

```bash
ls /dev/ttyUSB*
```

or:

```bash
ls /dev/ttyACM*
```

Once the correct device is identified, upload the firmware:

```bash
pio run -t upload
```

If the system has multiple serial devices connected, explicitly specify the upload port:

```bash
pio run -t upload --upload-port /dev/ttyUSB0
```

Replace `/dev/ttyUSB0` with the actual device associated with the development board.

### Build + Upload

The normal development cycle can therefore be reduced to:

```bash
pio run -t upload
```

No VS Code or graphical PlatformIO interface is required.

---

# 📡 Serial Output

The firmware currently uses:

```cpp
Serial.begin(9600);
```

Therefore, the serial terminal must be configured for:

| Setting | Value |
| --- | --- |
| Baud rate | `9600` |
| Data bits | `8` |
| Parity | None |
| Stop bits | `1` |

The serial output is viewed using **CuteCom**.

Launch CuteCom:

```bash
cutecom
```

Select the serial device connected to the development board, for example:

```text
/dev/ttyUSB0
```

Configure the baud rate:

```text
9600
```

Then open the serial connection to view the firmware output.

---

# 🔄 Development Workflow

The current development workflow is intentionally command-line based:

```text
             ┌──────────────────┐
             │  Edit Source Code│
             └────────┬─────────┘
                      │
                      ▼
             ┌──────────────────┐
             │     pio run      │
             │      Build       │
             └────────┬─────────┘
                      │
                      ▼
             ┌──────────────────┐
             │ pio run -t upload│
             │      Upload      │
             └────────┬─────────┘
                      │
                      ▼
             ┌──────────────────┐
             │     CuteCom      │
             │  Serial @ 9600   │
             └────────┬─────────┘
                      │
                      ▼
             ┌──────────────────┐
             │  Observe / Test  │
             │     RDA1846      │
             └──────────────────┘
```

---

# 🧭 Development Roadmap

The project will be developed in small, verifiable stages:

```text
PlatformIO Project
       │
       ▼
Build & Upload
       │
       ▼
Serial Communication
       │
       ▼
Three-Wire Communication
       │
       ▼
Register Read
       │
       ▼
Register Write
       │
       ▼
Register Bit/Field Operations
       │
       ▼
RDA1846 Configuration
       │
       ▼
Radio Functionality
```

Each layer will be tested before moving to the next.

---

## 📌 Current Status

**Stage:** Initial communication development

Currently established:

- [x] PlatformIO project structure
- [x] Command-line build
- [x] Command-line firmware upload
- [x] Serial output at `9600` baud
- [x] RDA1846 communication API structure
- [ ] Verified register read
- [ ] Verified register write
- [ ] RDA1846 initialization
- [ ] Radio configuration
- [ ] Transmit/receive operation

---

## 📄 License

This project contains code derived from the
[EnhancedRadioDevices/HamShield](https://github.com/EnhancedRadioDevices/HamShield)
library.

The licensing and copyright terms of the original source code remain applicable
to the portions derived from that project.

Additional original work in this project will be licensed separately.
