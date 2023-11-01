#include "MySD.h"
#include "RFID.h"
#include <SPI.h>

// Define RFID and SD card pins
#define RFID_SS_PIN 15  // SS (CS) pin for RFID (HSPI)
#define RFID_RST_PIN 16  // Reset pin for RFID (HSPI)
#define SD_SS_PIN 5  // SS (CS) pin for SD card (VSPI)

// Create instances of RFID and SD card
RFID rfidModule(RFID_SS_PIN, RFID_RST_PIN);
MySD sdCard;
File dataFile;

// Maintain a data structure to store the status of individuals
struct PersonStatus {
    String name;
    String regNo;
    bool checkedIn;
    String lastRecord;
};

PersonStatus personStatus;

void setup() {
    Serial.begin(115200);

    // RFID SPI (HSPI)
    SPI.begin(HSPI, 4000000U, MSBFIRST, SPI_MODE0);

    // SD Card SPI (VSPI)
    SPI.begin(VSPI, 20000000U, MSBFIRST, SPI_MODE0);

    // Initialize the RFID module
    rfidModule.init();

    if (sdCard.init(SD_SS_PIN)) {
        // Create or open your CSV file and write the header if necessary
        dataFile = sdCard.openFile("/data.csv", FILE_WRITE);
        if (dataFile) {
            dataFile.println("name,reg-no,intime,outtime,rfid");
            dataFile.close();
        }
    } else {
        Serial.println("Error initializing SD card");
    }
}

void loop() {
    String rfid = rfidModule.readCardUID();
    if (!rfid.isEmpty()) {
        // Check the status of the person
        if (!personStatus.checkedIn) {
            // Person is checking in
            personStatus.name = "John Doe";  // Replace with actual data
            personStatus.regNo = "12345";    // Replace with actual data
            personStatus.checkedIn = true;
            personStatus.lastRecord = "2023-11-01 10:00:00";
        } else {
            // Person is checking out
            personStatus.checkedIn = false;
            personStatus.lastRecord = "2023-11-01 16:30:00";  // Replace with actual checkout time
        }

        // Prepare the record
        String record = personStatus.name + "," + personStatus.regNo + "," + personStatus.lastRecord + ",";
        if (personStatus.checkedIn) {
            record += ",";
        } else {
            record += "2023-11-01 16:30:00,"; // Replace with actual checkout time
        }
        record += rfid;

        // Open the CSV file and append the record
        dataFile = sdCard.openFile("data.csv", FILE_WRITE);
        if (dataFile) {
            sdCard.appendCSVRecord(dataFile, record);
            dataFile.close();
        } else {
            Serial.println("Error opening data.csv");
        }
    }
}
