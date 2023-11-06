// #include <WiFi.h>
// #include <HTTPClient.h>

// const char WIFI_SSID[] = "sheila";
// const char WIFI_PASSWORD[] = "Jaskaran123";

// String HOST_NAME = "http://192.168.36.205"; // change to your PC's IP address
// String PATH_NAME   = "/get_chkin.php";
// String queryString = "?temperature=30.5";

// void setup() {
//   Serial.begin(115200); 

//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.println("Connecting");
//   while(WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("");
//   Serial.print("Connected to WiFi network with IP Address: ");
//   Serial.println(WiFi.localIP());
  
//   HTTPClient http;

//   http.begin(HOST_NAME + PATH_NAME ); //HTTP
//   int httpCode = http.GET();

//   // httpCode will be negative on error
//   if(httpCode > 0) {
//     // file found at server
//     if(httpCode == HTTP_CODE_OK) {
//       String payload = http.getString();
//       Serial.println(payload);
//     } else {
//       // HTTP header has been send and Server response header has been handled
//       Serial.printf("[HTTP] GET... code: %d\n", httpCode);
//     }
//   } else {
//     Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
//   }

//   http.end();
// }

// void loop() {

// }


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
