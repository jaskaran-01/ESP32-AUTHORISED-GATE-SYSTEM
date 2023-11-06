#ifndef DBConn_h
#define DBConn_h

#include <Arduino.h>

class DBConn {
public:
  DBConn(); // Constructor

  // Connect to the database (you may need parameters like server, credentials, etc.)
  bool connectToDatabase();

  // Check-in a person by UID and update the CheckedIn and CheckinDateTime fields
  bool checkInPerson(const String &uid);

  // Get the name, CheckedIn status, and CheckinDateTime for a person by UID
  bool getPersonInfo(const String &uid, String &name, bool &checkedIn, String &checkinDateTime);

  // Other methods for modifying and querying the database

private:
  // Private members and methods for handling the database connection
};

#endif
