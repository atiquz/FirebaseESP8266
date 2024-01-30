#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

FirebaseESP8266 firebase("https://esp-project-01-default-rtdb.firebaseio.com");
bool firebaseConnected = false;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("JioFiber Home", "Password");
  while (WiFi.status() != WL_CONNECTED) delay(500);

  firebaseConnected = true;

  firebase.setString("Fruits/Product", "Apple");
  firebase.setInt("Fruits/Code", 12345);
  firebase.setFloat("Fruits/Price", 72.30);
  firebase.setBool("Fruits/Available", firebaseConnected);

  firebase.pushString("Updates", "Apple");
  firebase.pushInt("Updates", 67890);
  firebase.pushFloat("Updates", 73.50);
  firebase.pushBool("Updates", firebaseConnected);

  String data1 = firebase.getString("Fruits/Product");
  Serial.print("Received Product:\t");
  Serial.println(data1);

  int data2 = firebase.getInt("Fruits/Code");
  Serial.print("Received Code:\t\t");
  Serial.println(data2);

  float data3 = firebase.getFloat("Fruits/Price");
  Serial.print("Received Price:\t\t");
  Serial.println(data3);

  bool data4 = firebase.getBool("Fruits/Available");
  Serial.print("Received Available:\t\t");
  Serial.println(data4);

  firebase.deleteData("Fruits");
}

void loop() {
}
