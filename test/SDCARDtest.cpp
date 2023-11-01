#include "MySD.h"
#include <SPI.h>

// Define the SD card SS pin (CS pin)
#define SD_SS_PIN 5

// Create an instance of the MySD library
MySD sdCard;

unsigned long startTime;
unsigned long endTime;

void setup() {
    Serial.begin(115200);

    // Initialize the SD card
    if (sdCard.init(SD_SS_PIN)) {
        // Record the start time
        startTime = millis();

        // Create a file
        File dataFile = sdCard.openFile("test.csv", FILE_WRITE);
        if (dataFile) {
            // Write "Hello, World!" in CSV format to the file
            dataFile.print("Hello,");
            dataFile.print("World!");
            dataFile.println(); // Add a newline to separate rows
            dataFile.close();
            Serial.println("Data written to the file.");
        } else {
            Serial.println("Error creating the file.");
        }

        // Read and print the contents of the CSV file in tabular format
        dataFile = sdCard.openFile("test.csv", FILE_READ);
        if (dataFile) {
            while (dataFile.available()) {
                String line = dataFile.readStringUntil('\n');
                // Split the line into columns based on the comma delimiter
                int commaIndex = line.indexOf(',');
                String column1 = line.substring(0, commaIndex);
                String column2 = line.substring(commaIndex + 1);

                // Print in tabular format
                Serial.print(column1);
                Serial.print("\t"); // Tab delimiter
                Serial.println(column2);
            }
            dataFile.close();

            // Record the end time and calculate the elapsed time
            endTime = millis();
            Serial.print("Time taken (ms): ");
            Serial.println(endTime - startTime);
        } else {
            Serial.println("Error reading the file.");
        }
    } else {
        Serial.println("Error initializing SD card");
    }
}

void loop() {
    // Your loop code, if any
}
