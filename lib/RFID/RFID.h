#ifndef RFID_h
#define RFID_h

#include <SPI.h>
#include <MFRC522.h>

class RFID {
public:
    RFID(uint8_t ssPin, uint8_t rstPin);
    void init();
    String readCardUID();
    // Add any other functions or variables you need here
private:
    MFRC522 mfrc522;
};

#endif
