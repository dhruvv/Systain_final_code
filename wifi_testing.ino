#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
//#include <boost/lexical_cast.hpp> // for lexical_cast()
#include <string>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin("codefest", "Code@Fest18");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting to connect");
  }
  Serial.println("Connected!");
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  float voltage = value * (5.0 / 1024.0);
  String data = String(voltage);
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://oakhack.pythonanywhere.com/post");
    int httpCode = http.POST(data);
    String payload = http.getString();
    Serial.println(httpCode);   //Print HTTP return code
    Serial.println(payload);    //Print request response payload
    http.end();
  }
  else {
    Serial.println("Wifi error");
  }
  delay(20000);
}
