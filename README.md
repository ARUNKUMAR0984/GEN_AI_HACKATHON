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

---

## Installation

### Step 1: Clone the Repository

Start by cloning this repository to your local machine:

```bash
git clone https://github.com/yourusername/Traffic-Monitoring-System.git
cd Traffic-Monitoring-System
