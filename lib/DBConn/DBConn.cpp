#include "DBConn.h"

DBConn::DBConn() {
  // Constructor implementation
}

bool DBConn::connectToDatabase() {
  // Initialize the database connection
  if (database.connect("server_address", "username", "password")) {
    // Connection successful
    return true;
  } else {
    // Connection failed
    return false;
  }
}

bool DBConn::checkInPerson(const String &uid) {
  // Construct an SQL query to update the CheckedIn and CheckinDateTime fields for the specified UID
  String query = "UPDATE people SET CheckedIn = true, CheckinDateTime = NOW() WHERE UID = '" + uid + "'";

  // Execute the query
  if (database.execute(query)) {
    // Update successful
    return true;
  } else {
    // Update failed
    return false;
  }
}

bool DBConn::getPersonInfo(const String &uid, String &name, bool &checkedIn, String &checkinDateTime) {
  // Construct an SQL query to retrieve information for the specified UID
  String query = "SELECT Name, CheckedIn, CheckinDateTime FROM people WHERE UID = '" + uid + "'";

  // Execute the query and retrieve the results
  if (database.execute(query)) {
    if (database.resultsAvailable()) {
      // Fetch the results
      name = database.getString(0);
      checkedIn = database.getBoolean(1);
      checkinDateTime = database.getString(2);
      return true;
    }
  }
  // Query or data retrieval failed
  return false;
}
