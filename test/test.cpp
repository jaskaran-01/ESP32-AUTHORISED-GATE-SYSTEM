#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "DBConn.h"

// Replace with your network credentials
const char* ssid = "sheila";
const char* password = "Jaskaran123";

// Replace with your ESP32's IP address
const char* servIP = "http://192.168.36.205"; // Change to your ESP32's actual IP

// Create an instance of the DBConn library
DBConn DBConn(servIP);

void setup() {
    Serial.begin(115200);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    bool chkinValue;

    // Test the checkUIDPresence method
    Serial.println("Checking UID presence...");
    if (DBConn.checkUIDPresence("8e26d873")) {
        Serial.println("UID is present in the database.");
    } else {
        Serial.println("UID is not present in the database.");
    }

    // Test the getAndToggleChkin method
    Serial.println("Getting and toggling Chkin value...");
    if (DBConn.getAndToggleChkin("8e26d873", chkinValue)) {
        if (chkinValue) {
            Serial.println("Chkin value is now 1.");
        } else {
            Serial.println("Chkin value is now 0.");
        }
    } else {
        Serial.println("Failed to get and toggle Chkin value.");
    }
}

void loop() {
    // Your loop code here
}
