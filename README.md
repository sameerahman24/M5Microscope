# M5Microscope

**M5Microscope** transforms the M5TimerCam into a digital microscope by coupling it with an external microscope lens. Once configured, the device creates its own WiFi access point so you can instantly view a live microscope feed by connecting to [http://192.168.4.1/](http://192.168.4.1/).

## Demo
<img src="https://i.ibb.co/prsz32LM/IMG-9326.png" alt="IMG-9326" border="0">
<img src="https://i.ibb.co/N6jNQpyQ/IMG-9325.png" alt="IMG-9325" border="0">
<img src="https://i.ibb.co/FbsbsqL0/IMG-9323.png" alt="IMG-9323" border="0">
<img src="https://i.ibb.co/n8RWp50p/IMG-9324.png" alt="IMG-9324" border="0">

## Overview

This project leverages the M5TimerCam and an external microscope lens to create a compact, wireless digital microscope. It’s an excellent solution for educational demonstrations, DIY microscopy experiments, or even field applications where portability is key.

## Features

- **Wireless Access Point:** Automatically creates a WiFi hotspot to connect and stream the microscope feed.
- **Live Streaming:** View captured pictures by navigating to [http://192.168.4.1/](http://192.168.4.1/).
- **Open Source:** Easily customizable codebase for further experimentation and enhancements.
- **Portable Design:** Compact and efficient for on-the-go microscopy.

## Getting Started

### Prerequisites

- **Hardware:**
  - M5TimerCam
  - External microscope lens compatible with the M5TimerCam setup
  - USB cable for programming the device

- **Software:**
  - [Arduino IDE](https://www.arduino.cc/en/software) or an equivalent ESP32 development environment like [PlatformIO](https://platformio.org/)
  - Required libraries as noted in the source code

### Installation

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/sameerahman24/M5Microscope.git
   cd M5Microscope
   ```

2. **Configure Your Development Environment:**
   - Open the project in your preferred Arduino IDE.
   - Verify that all necessary libraries (e.g., for ESP32 and camera functionality) are installed. Check the source code in the repository for specific dependencies.

3. **Upload the Code:**
   - Connect your M5TimerCam to your computer.
   - In the Arduino IDE, select the correct board and port.
   - Upload the firmware to your device.

### Usage

1. **Power Up and Connect:**
   - Once the code is uploaded, power your M5TimerCam.
   - The device will broadcast its own WiFi network. Connect your smartphone or laptop to this network.

2. **Access the Microscope Interface:**
   - Open your web browser and navigate to [http://192.168.4.1/](http://192.168.4.1/).
   - You should now see the live feed from the camera after clicking capture.

## Repository Structure

- **src/**: Contains the main firmware code for the M5Microscope.
- **README.md**: This file, outlining the project details and usage.
- Additional folders or files may include configuration files and hardware-specific documentation.


## License


## Acknowledgements

- Special thanks to all contributors and open-source projects that provided inspiration and components for the M5Microscope, especially [Timer-CAM Library
](https://github.com/m5stack/TimerCam-arduino)

