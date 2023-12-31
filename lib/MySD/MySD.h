#ifndef MySD_H_
#define MySD_H_

#include <Arduino.h>
#include <SD.h>

class MySD {
public:
    MySD();
    bool init(uint8_t ssPin,SPIClass &spi);
    File openFile(const char* fileName, const char* mode);
    bool writeCSVRecord(File file, const String& record);
    bool appendCSVRecord(File file, const String& record);
    bool deleteFile(const String& path); 
    bool createFile(const String& path);
    String readCSVRecord(File file, int recordNumber);
private:
    bool isInitialized;
};

#endif
