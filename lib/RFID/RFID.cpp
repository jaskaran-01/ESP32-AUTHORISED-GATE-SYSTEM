#include "RFID.h"

RFID::RFID(uint8_t ssPin, uint8_t rstPin) : mfrc522(ssPin, rstPin) {}

void RFID::init() {
    SPI.begin();
    mfrc522.PCD_Init();
}

String RFID::readCardUID() {
    String rfid = "";
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
        for (byte i = 0; i < mfrc522.uid.size; i++) {
            rfid += String(mfrc522.uid.uidByte[i], HEX);
        }
        rfid.toUpperCase();
    }
    return rfid;
}
