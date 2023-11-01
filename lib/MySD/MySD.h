#ifndef MySD_H_
#define MySD_H_

#include <Arduino.h>
#include <SD.h>

class MySD {
public:
    MySD();
    bool init(uint8_t ssPin);
    File openFile(const char* fileName, const char* mode);
    bool writeCSVRecord(File file, const String& record);
    bool appendCSVRecord(File file, const String& record);
    String readCSVRecord(File file, int recordNumber);
private:
    bool isInitialized;
};

#endif
