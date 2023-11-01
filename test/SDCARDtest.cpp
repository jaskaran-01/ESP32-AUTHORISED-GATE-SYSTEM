#include "MySD.h"
#include <SPI.h>
#include <sstream>
#include <string>

// Define the SD card SS pin (CS pin)
#define SD_SS_PIN 5

// Create an instance of the MySD library
MySD sdCard;

void setup() {
    Serial.begin(115200);

    // Initialize the SD card
    if (sdCard.init(SD_SS_PIN)) {
        Serial.println("SD card initialized.");

        // Wait for user input from the Serial Monitor
        Serial.println("Enter a single line string:");
        while (!Serial.available()) {
            // Wait for input
        }
        
        // Read the input string
        String inputString = Serial.readStringUntil('\n');
        
        // Create a new file
        if (sdCard.createFile("/test.csv")) {
            Serial.println("File created successfully.");
            File dataFile = sdCard.openFile("/test.csv", FILE_WRITE);

            // Split the input into words and write to the file in CSV format
            String new_str="";
            int spaceIndex = 0;
            do {
                spaceIndex = inputString.indexOf(' ');
                if (spaceIndex != -1) {
                    String word = inputString.substring(0, spaceIndex);
                    inputString = inputString.substring(spaceIndex + 1);
                    new_str+=word+",";
                }
            }while (spaceIndex != -1);
            new_str+=inputString;
            Serial.println(new_str);
            sdCard.appendCSVRecord(dataFile,new_str);
            dataFile.close();
            Serial.println("CSV records written to the file.");
        } else {
            Serial.println("Error creating the file.");
        }

        // Read and print the contents of the CSV file in tabular format
        File dataFile = sdCard.openFile("/test.csv", FILE_READ);
        if (dataFile) {
            while (dataFile.available()) {
                String line = sdCard.readCSVRecord(dataFile, 0);
                Serial.println(line);
            }
            dataFile.close();
        if(sdCard.deleteFile("/test.csv")){
            Serial.println("file deleted");
        }
        else{
            Serial.println("Error in file deletion");
        }
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