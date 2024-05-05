#include "HardwareSerial.h"

#define RXD2 16
#define TXD2 17

void setup() {
  // Initialize Serial1 at 115200 baud for debug output
  Serial.begin(115200);
  
  // Configure Serial2: Use default pins (RX2 = 16, TX2 = 17), or specify your own
  // Initialize Serial2 at 9600 baud, 8N1 format is default
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

  /*Serial.println("Flashing LED!");
  for(int i = 0; i < 2000; i++) {
    Serial2.write(0x55);
    delay(1);
  }*/

  
  Serial.println("setup done!");
}

int byteCount = 0;
void loop() {
  // Check if data is available on Serial2
  while (Serial2.available() > 0) {
    // Read a byte from Serial2
    int byteRead = Serial2.read();

    // Check for a successful read
    if (byteRead != -1) {
      // Convert the byte to a hexadecimal string and print to Serial1
      // Add a space for readability
      Serial.print(String(byteRead, HEX)); 
      Serial.print(" ");

      byteCount += 1;
      if(byteCount >= 16) {
        Serial.println("");
        byteCount = 0;
      }
    }
  }

  delay(1);
}
