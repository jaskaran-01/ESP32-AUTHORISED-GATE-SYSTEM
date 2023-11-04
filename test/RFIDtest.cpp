#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 22     // Define the RST_PIN for the RFID reader (can be any GPIO pin)
#define SS_PIN 21      // Define the SS_PIN for the RFID reader (can be any GPIO pin)

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(115200);
  SPI.begin();     // Initialize SPI communication
  mfrc522.PCD_Init();  // Initialize the RFID reader

  Serial.println("Place an RFID card near the reader...");
}

void loop() {
  // Look for new RFID cards
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Print the UID of the card
    Serial.print("Card UID: ");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
    
    // Halt PICC and stop communication
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}
