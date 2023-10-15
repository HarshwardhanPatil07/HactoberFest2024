#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <SoftwareSerial.h>

SoftwareSerial espSerial(13, 15);

const char* wifiName = " ";
const char* password = " ";

const unsigned long WiFiCheckInterval = 10000;
unsigned long lastWiFiCheckTime = 0;

bool flag = false;

WiFiClient wifiClient;

void access(int a) {
  switch (a) {
    case 1:
      espSerial.print("@");
      delay(ACCESS_DELAY);
      espSerial.print("%");
      break;
    case 2:
      espSerial.print("&");
      delay(DENIED_DELAY);
      break;
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  espSerial.begin(9600);

  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_R, HIGH);

  WiFi.begin(wifiName, password);
  lastWiFiCheckTime = millis();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi and Firebase");
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_R, LOW);
  }
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastWiFiCheckTime >= WiFiCheckInterval) {
    lastWiFiCheckTime = currentMillis;

    if (WiFi.status() != WL_CONNECTED) {
      digitalWrite(LED_R, HIGH);
      Serial.println("Wifi disconnected");
      flag = true;
    } else if (flag) {
      Serial.println("Wifi connected");
      flag = false;
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_R, LOW);
    }
  }

  if (Firebase.getString("lock") == "open") {
    Serial.println("Someone opened door");
    access(1);
    Firebase.setString("lock", "close");
  }
}
