#include <Arduino.h>
#include <rdm6300.h>
#include <Servo.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>

// String ssid = "TP-Link_CEA8";
// String password = "18926972";
String ssid = "Imti";
String password = "imti1999";
String iftttWebhookKey = "iAxCUZNLtbnSXSQAieiAqD6gSlV3K4RN2XHMAbGN-wE";

#define RDM6300_RX_PIN 4
#define Buzzer 15
Servo myservo;
const int servoPin = 14;
Rdm6300 rdm6300;

// Define a structure to associate card IDs with names
struct Card {
  const char* id;
  const char* name;
};

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// Define allowed card IDs with associated names
Card allowedCards[] = {
  {"7517b6", "2017338001"},
  {"333bcd", "2019338038"},
  {"32c194", "2019338052"},
  {"32a1f6", "2019338053"},
  {"32c477", "2019338054"},
};

int numAllowedCards = sizeof(allowedCards) / sizeof(allowedCards[0]);

void setup() {
  myservo.attach(servoPin);
  Wire.begin(21, 22);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);
  digitalWrite(Buzzer, LOW);
  rdm6300.begin(RDM6300_RX_PIN);
  Serial.println("\nPlace RFID tag near the RDM6300...");
  clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  text(0,10,"   Hello  ");
  text(0,26," Everyone ");
}

void loop() {
  if (rdm6300.get_new_tag_id()) {
    String cardID = String(rdm6300.get_tag_id(),HEX);
    String cardName = findCardName(cardID);
    
    if (cardName != "") {
      unlockDoor();
      Serial.print("Access granted for: ");
      Serial.println(cardName);
      clearDisplay();
      text(0, 0, "  Access  ");
      text(0, 18," Granted  ");
      text(0, 40, cardName);
      delay(3000); // Unlock the door for 3 seconds.
      lockDoor();
      clearDisplay();
      if (sendDataToIFTTT(cardName, " "," ")) {
        Serial.println("Data sent to IFTTT successfully");
      }
    } else {
      Serial.println(cardID);
      Serial.println("Access denied.");
      clearDisplay();
      text(0, 20, "  Access  ");
      text(0, 40, "  Denied  ");
      // text(0, 1, cardName);
      for(int i = 0; i<5; i++){
        digitalWrite(Buzzer, 1);
        delay(80);
        digitalWrite(Buzzer, 0);
        delay(80);
      }
      delay(1000);
      clearDisplay();

    }
  }
}

String findCardName(String cardID) {
  for (int i = 0; i < numAllowedCards; i++) {
    if (cardID.equals(allowedCards[i].id)) {
      return allowedCards[i].name;
    }
  }
  return ""; // Return an empty string if card is not found
}