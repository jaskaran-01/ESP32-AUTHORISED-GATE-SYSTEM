#include "DBConn.h"

DBConn::DBConn() {
  // Constructor implementation
}

bool DBConn::connectToDatabase() {
  // Implement your code to connect to the database here
}

bool DBConn::checkInPerson(const String &uid) {
  // Implement your code to check in a person in the database
}

bool DBConn::getPersonInfo(const String &uid, String &name, bool &checkedIn, String &checkinDateTime) {
  // Implement your code to retrieve a person's info from the database
}
