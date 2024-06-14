/*
    Project name : IR Receiver Module
    Modified Date: 13-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-ir-receiver-module
*/

#include <IRremote.h>

// Define the pin where the IR receiver is connected
const int irReceiverPin = 2;

IRrecv irrecv(irReceiverPin); // Create an IRrecv object
decode_results results;       // Create a decode_results object

void setup() {
  Serial.begin(9600); // Initialize serial communication
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("IR Code Received: ");
    Serial.println(results.value, HEX); // Print the received IR code in hexadecimal format
    
    // Call custom function to handle the IR code
    handleIRCode(results.value);

    irrecv.resume(); // Receive the next value
  }
}

void handleIRCode(unsigned long irCode) {
  // Example: Add custom actions based on received IR code
  switch (irCode) {
    case 0xFFA25D: // Replace with your IR remote's button code
      Serial.println("Power button pressed");
      // Add custom action for Power button
      break;
    case 0xFF629D: // Replace with your IR remote's button code
      Serial.println("Volume Up button pressed");
      // Add custom action for Volume Up button
      break;
    // Add more cases for other buttons
    default:
      Serial.println("Unknown button pressed");
      break;
  }
}
