# ESP32 SD Card and RFID Integration

This project demonstrates how to use an ESP32 microcontroller to integrate an SD card reader and an RFID module to read and write data to an SD card in CSV format.

## Table of Contents

- [Project Overview](#project-overview)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Setup](#setup)
- [Usage](#usage)
- [Example Code](#example-code)
- [Contributing](#contributing)
- [License](#license)

## Project Overview

This project combines an ESP32 microcontroller with an SD card reader and an RFID module to create a system for reading and writing data to an SD card in CSV format. It demonstrates how to write records to a CSV file, read data from the file, and handle RFID card scans for check-in and check-out records.

## Hardware Requirements

To replicate this project, you will need the following hardware components:

- ESP32 development board
- SD card module with compatible SD card
- RFID RC522 module
- Appropriate wiring and power supply for the hardware components

## Software Requirements

To develop and run this project, you will need the following software:

- PlatformIO for programming the ESP32
- Arduino libraries for the ESP32, SD card, and RFID modules

## Setup

1. Connect the hardware components as specified in the project code.
2. Install PlatformIO and the necessary libraries for the ESP32, SD card, and RFID modules.
3. Upload the project code to your ESP32.

## Usage

1. After uploading the code, open the Serial Monitor to view the system's output.
2. Tap an RFID card on the RFID module to simulate a check-in or check-out action.
3. Observe the output in the Serial Monitor, which should display RFID scans and data being written and read from the SD card.

## Example Code

The project code provided demonstrates how to interact with the SD card and RFID module, including writing and reading CSV data. Refer to the code in the `main.cpp` file for details.  

## Circuit Diagram
![Circuit Diagram](https://github.com/jaskaran-01/ESP32-AUTHORISED-GATE-SYSTEM/assets/59540918/a69fa80d-afd5-4b7d-8427-c4522eae1260) 

## Contributing

Feel free to contribute to this project by opening issues, suggesting improvements, or creating pull requests. We welcome your ideas and enhancements.

## License

This project is licensed under the [MIT License](LICENSE).
