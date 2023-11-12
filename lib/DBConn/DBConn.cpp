#include "DBConn.h"

DBConn::DBConn(String serverAddress) : serverAddress(serverAddress) {}

bool DBConn::checkUIDPresence(String UID) {
    HTTPClient http;
    String url = serverAddress + "/chk-uid.php?UID=" + UID;

    if (http.begin(url)) {
        int httpCode = http.GET();
        http.end();

        return httpCode == HTTP_CODE_OK;
    }
    return false;
}

bool DBConn::getAndToggleChkin(String UID, bool& chkinValue) {
    HTTPClient http;

    // Check if the UID is present
    if (checkUIDPresence(UID)) {
        // Get the Chkin value and toggle it
        String url = serverAddress + "/get-and-toggle-chkin.php?UID=" + UID;
        if (http.begin(url)) {
            int httpCode = http.GET();
            if (httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                http.end();

                DynamicJsonDocument jsonDoc(256);
                deserializeJson(jsonDoc, payload);

                if (jsonDoc.containsKey("Chkin")) {
                    chkinValue = jsonDoc["Chkin"];
                    return true;
                }
            }
        }
    }
    
    return false; // UID not found or error
}
