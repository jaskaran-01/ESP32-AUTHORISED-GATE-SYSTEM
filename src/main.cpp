

#include "MySD.h"
#include <SPI.h>
#include <sstream>
#include <string>
#include <MFRC522.h>

#define HSPI_MISO   27
#define HSPI_MOSI   13
#define HSPI_SCLK   14
#define HSPI_SS     15
SPIClass * hspi = new SPIClass();

 void csvAppend(String str);
 String csvRead(int recNum);

#define RFID_MOSI     23
#define RFID_MISO     19
#define RFID_SS       5
#define RFID_SCLK     18
#define RFID_RST      21     // Define the RST_PIN for the RFID reader (can be any GPIO pin)

MFRC522 mfrc522(RFID_SS,RFID_RST);  // Create MFRC522 instance
MySD sdCard;
void setup() {
  hspi->begin(HSPI_SCLK,HSPI_MISO,HSPI_MOSI,HSPI_SS);
  Serial.begin(115200);
  SPI.begin(RFID_SCLK,RFID_MISO,RFID_MOSI,RFID_SS);     // Initialize SPI communication
  mfrc522.PCD_Init();  // Initialize the RFID reader
  if (sdCard.init(HSPI_SS,*hspi)) Serial.println("SD card initialised !!");
  else Serial.println("SD card failed :(!!");
  Serial.println("Place an RFID card near the reader...");
}
int count=0;
void loop() {
  String fetch_id;
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Print the UID of the card
    Serial.print("Card UID: ");
    count++;
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      Serial.print(" ");
      fetch_id+=String(mfrc522.uid.uidByte[i], HEX);

    }
    Serial.println(fetch_id);
    csvAppend(fetch_id);
    Serial.println();
    
    // Halt PICC and stop communication
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    Serial.println(csvRead(count));
  }// Look for new RFID cards
 
}
void csvAppend(String str){
  File dataFile = sdCard.openFile("/data.csv", FILE_WRITE);
  sdCard.writeCSVRecord(dataFile,str);
  dataFile.close();
}
String csvRead(int recNum){
  File dataFile = sdCard.openFile("/data.csv", FILE_READ);
  dataFile.close();
  return(sdCard.readCSVRecord(dataFile, recNum));
}