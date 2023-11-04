/*
#include "MySD.h"
#include <SPI.h>
#include <sstream>
#include <string>
#include "MFRC522.h"


// Define the SD card pins
  #define HSPI_MISO   27
  #define HSPI_MOSI   13
  #define HSPI_SCLK   14
  #define HSPI_SS     15
  SPIClass * hspi = NULL;
// Create an instance of the MySD library
MySD sdCard;
#define RFID_MOSI     23
#define RFID_MISO     19
#define RFID_SS       15
#define RFID_SCLK     18
#define RFID_RST      22     // Define the RST_PIN for the RFID reader (can be any GPIO pin)

MFRC522 mfrc522(RFID_SS,RFID_RST);  // Create MFRC522 instance



void setup() {
    Serial.begin(115200);
    delay(1000);
    hspi = new SPIClass();
    hspi->begin(HSPI_SCLK,HSPI_MISO,HSPI_MOSI,HSPI_SS);
    SPI.begin(RFID_SCLK,RFID_MISO,RFID_MOSI,RFID_SS);     // Initialize SPI communication
    mfrc522.PCD_Init();  // Initialize the RFID reader
    Serial.println("Place an RFID card near the reader...");
    // Initialize the SD card


}

void loop(){
    String inputString;
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
        // Print the UID of the card
        Serial.print("Card UID: ");
        for (byte i = 0; i < mfrc522.uid.size; i++) {
        inputString=String(mfrc522.uid.uidByte[i], HEX);
        Serial.print(inputString);
        Serial.print(" ");
        }
        Serial.println();
        
        // Halt PICC and stop communication
        mfrc522.PICC_HaltA();
        mfrc522.PCD_StopCrypto1();
    
        // Read the input string

    sdCard.init(HSPI_SS,*hspi);
    // Create a new file
    if (sdCard.createFile("/data.csv")) {
        Serial.println("File created successfully.");
        File dataFile = sdCard.openFile("/data.csv", FILE_WRITE);
        sdCard.appendCSVRecord(dataFile,inputString);
        dataFile.close();
    } else {
        Serial.println("Error creating the file.");
    }

    // Read and print the contents of the CSV file in tabular format
    File dataFile = sdCard.openFile("/data.csv", FILE_READ);
    if (inputString!="") {
        while (dataFile.available()) {
            String line = sdCard.readCSVRecord(dataFile, 0);
            Serial.println(line);
        }
        dataFile.close();
    } else {
        Serial.println("Error ");
    }}
    delay(600);
 // Your loop code, if any
}*/
#include "MySD.h"
#include <SPI.h>
#include <sstream>
#include <string>
#include <MFRC522.h>

#define HSPI_MISO   27
#define HSPI_MOSI   13
#define HSPI_SCLK   14
#define HSPI_SS     15
//SPIClass * hspi = new SPIClass();

// void csvAppend(String str);
// String csvRead();

#define RFID_MOSI     23
#define RFID_MISO     19
#define RFID_SS       5
#define RFID_SCLK     18
#define RFID_RST      21     // Define the RST_PIN for the RFID reader (can be any GPIO pin)

MFRC522 mfrc522(RFID_SS,RFID_RST);  // Create MFRC522 instance
//MySD sdCard;
void setup() {
 // hspi->begin(HSPI_SCLK,HSPI_MISO,HSPI_MOSI,HSPI_SS);
  Serial.begin(115200);
  SPI.begin();     // Initialize SPI communication
  mfrc522.PCD_Init();  // Initialize the RFID reader

  Serial.println("Place an RFID card near the reader...");
}

void loop() {
  String fetch_id;
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Print the UID of the card
    Serial.print("Card UID: ");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      Serial.print(" ");
      fetch_id=String(mfrc522.uid.uidByte[i], HEX);
      // csvAppend(fetch_id);
    }
    Serial.println();
    
    // Halt PICC and stop communication
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    // Serial.println(csvRead());
  }// Look for new RFID cards
 
}
// void csvAppend(String str){
//   File dataFile = sdCard.openFile("/data.csv", FILE_WRITE);
//   sdCard.init(HSPI_SS,*hspi);
//   sdCard.writeCSVRecord(dataFile,str);
// }
// String csvRead(){
//   File dataFile = sdCard.openFile("/data.csv", FILE_WRITE);
//   sdCard.init(HSPI_SS,*hspi);
//   return(sdCard.readCSVRecord(dataFile, 0));
// }