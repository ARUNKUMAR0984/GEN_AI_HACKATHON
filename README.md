# GEN_AI_HACKATHON

# Traffic Monitoring System with Video Processing and Arduino OV7670 Camera

This project implements a system that performs traffic video processing and real-time image capture using an OV7670 camera connected to an Arduino. It includes code to process both single and multiple videos, capture images in real-time, and process stored images one by one.

## Table of Contents
1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Hardware Requirements](#hardware-requirements)
4. [Software Requirements](#software-requirements)
5. [Installation](#installation)
6. [Usage](#usage)
    - [Processing Single Video](#processing-single-video)
    - [Processing Multiple Videos](#processing-multiple-videos)
    - [Real-time Image Capture using Arduino](#real-time-image-capture-using-arduino)
    - [Processing Stored Images](#processing-stored-images)
7. [Project Structure](#project-structure)
8. [Contributing](#contributing)
9. [License](#license)

---

## Project Overview

The Traffic Monitoring System leverages video and image processing techniques for object detection and counting in traffic videos. It supports both **single video** and **multiple video** processing and captures real-time images using the **Arduino OV7670 camera module**. This system can also process images stored in a local directory one by one. The key use cases include:
- **Monitoring traffic density** through object detection.
- **Counting cars, trucks, and pedestrians** in videos.
- **Real-time traffic monitoring** with Arduino.

---

## Features

1. **Single Video Processing**: Analyze a single video to detect and count cars, trucks, and people.
2. **Multiple Video Processing**: Process multiple videos simultaneously to handle large-scale traffic data.
3. **Real-time Image Capture using Arduino**: Capture images using the OV7670 camera connected to Arduino and store them locally.
4. **Image Processing from Local Directory**: Detect and count objects in images stored in a local directory.

---

## Hardware Requirements

- **Arduino Uno** (or compatible microcontroller)
- **OV7670 Camera Module** (for real-time image capture)
- **LCD Module** (for displaying real-time information)
- **Breadboard and Jumper Wires** (for connections)
- **Computer** with Python installed for video processing
- **Power supply** or USB cable for Arduino

---

## Software Requirements

- **Python 3.6 or higher**
- Required Python libraries:
  - **OpenCV** (`cv2`) - For video and image processing.
  - **CVLib** (`cvlib`) - For object detection using pre-trained YOLO models.
  - **NumPy** - For numerical operations.
  - **OS** - For file handling and directory operations.

### Arduino Dependencies

- **Arduino IDE** for uploading code to the Arduino.
- **[OV7670 Library](https://github.com/indrekluuk/LiveOV7670)** for the Arduino camera module.
- **LiquidCrystal_I2C** for the LCD module.
  ## OV7670 to Arduino Wiring

Below is the pin configuration for connecting the OV7670 camera module to an Arduino Uno or Nano:

### OV7670 to Arduino Connections:

| **OV7670 Pin** | **Arduino Pin**  | **Description**                                   |
|----------------|------------------|---------------------------------------------------|
| **VSYNC**      | **PIN 2**         | Vertical Sync Signal                              |
| **XCLCK**      | **PIN 3**         | External Clock (Must be level shifted to 3.3V)    |
| **PCLCK**      | **PIN 12**        | Pixel Clock Signal                                |
| **SIOD**       | **A4**            | I2C Data Line (Requires 10K pull-up to 3.3V)      |
| **SIOC**       | **A5**            | I2C Clock Line (Requires 10K pull-up to 3.3V)     |
| **D0**         | **A0**            | Pixel Data Bit 0                                  |
| **D1**         | **A1**            | Pixel Data Bit 1                                  |
| **D2**         | **A2**            | Pixel Data Bit 2                                  |
| **D3**         | **A3**            | Pixel Data Bit 3                                  |
| **D4**         | **PIN 4**         | Pixel Data Bit 4                                  |
| **D5**         | **PIN 5**         | Pixel Data Bit 5                                  |
| **D6**         | **PIN 6**         | Pixel Data Bit 6                                  |
| **D7**         | **PIN 7**         | Pixel Data Bit 7                                  |
| **3.3V**       | **3.3V**          | Power Supply to OV7670                            |
| **RESET**      | **3.3V**          | Reset Pin                                         |
| **PWDN**       | **GND**           | Power Down                                        |
| **GND**        | **GND**           | Ground                                            |

**Note:**
- The **XCLCK** pin needs a level shifter as it works at 3.3V while Arduino operates at 5V.
- Both **SIOD** and **SIOC** require **10K pull-up resistors** to 3.3V for I2C communication.


---

## Installation


### 1. Clone the Repository

First, clone the repository to your local machine:

```bash
git clone https://github.com/ARUNKUMAR0984/GEN_AI_HACKATHON.git
cd GEN_AI_HACKATHON
