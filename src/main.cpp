#include <DBConn.h>

DBConn db;

void setup() {
  Serial.begin(9600);
  if (db.connectToDatabase()) {
    Serial.println("Connected to the database.");
    // Use other DBConn methods here
  } else {
    Serial.println("Failed to connect to the database.");
  }
}

void loop() {
  // Your main program loop
}