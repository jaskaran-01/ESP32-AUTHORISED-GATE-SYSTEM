#include "MySD.h"

MySD::MySD() {
    isInitialized = false;
}

bool MySD::init(uint8_t ssPin) {
    if (!isInitialized) {
        if (SD.begin(ssPin)) {  // Initialize with the provided SS pin
            isInitialized = true;
            return true;
        }
    }
    return false;
}

File MySD::openFile(const char* fileName, const char* mode) {
    if (isInitialized) {
        return SD.open(fileName, mode);
    }
    return File();
}

bool MySD::writeCSVRecord(File file, const String& record) {
    if (file) {
        file.println(record);
        return true;
    }
    return false;
}

bool MySD::appendCSVRecord(File file, const String& record) {
    if (file) {
        file.seek(file.size());
        file.println(record);
        return true;
    }
    return false;
}

String MySD::readCSVRecord(File file, int recordNumber) {
    if (file) {
        while (file.available()) {
            String line = file.readStringUntil('\n');
            if (recordNumber == 0) {
                return line;
            }
            recordNumber--;
        }
        file.close();
    }
    return "";
}

bool MySD::deleteFile(const String& path) {
    return SD.remove(path);
}