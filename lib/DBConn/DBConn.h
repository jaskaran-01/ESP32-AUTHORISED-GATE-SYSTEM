#ifndef DBConn_h
#define DBConn_h

#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

class DBConn {
public:
    DBConn(String serverAddress);

    bool checkUIDPresence(String UID);
    bool getAndToggleChkin(String UID, bool& chkinValue);

private:
    String serverAddress;
};

#endif
