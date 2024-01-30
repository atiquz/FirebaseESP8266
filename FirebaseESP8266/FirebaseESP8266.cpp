#include "FirebaseESP8266.h"

FirebaseESP8266::FirebaseESP8266(String referenceURL) {
  _host = referenceURL;

  if (_host.startsWith("https://")) {
    _host.remove(0, 8);
  }

  if (_host.endsWith("/")) {
    _host.remove(_host.length() - 1);
  }

  _httpsClient.setInsecure();
}

int FirebaseESP8266::setString(String path, String data) {
  Connect_to_host();
  String jsonObject = String("/") + path + String(".json");
  String msg = "\"" + data + "\"";

  _httpsClient.print(String("PUT ") + jsonObject + " HTTP/1.1\r\n" + "Host: " + _host + "\r\n" + "Connection: close\r\n" + "Accept: */*\r\n" + "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" + "Content-Type: application/json;charset=utf-8\r\n" + "Content-Length: " + msg.length() + "\r\n" + "\r\n" + msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while (_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    if (line.length() > 0)
      return 200;  // Success
  }

  return 400;  // Failed
}

int FirebaseESP8266::setInt(String path, int data) {
  String Data = String(data);
  return FirebaseESP8266::setNum(path, Data);
}

int FirebaseESP8266::setFloat(String path, float data) {
  String Data = String(data);
  return FirebaseESP8266::setNum(path, Data);
}

int FirebaseESP8266::setNum(String path, String msg) {
  Connect_to_host();
  String jsonObject = String("/") + path + String(".json");

  _httpsClient.print(String("PUT ") + jsonObject + " HTTP/1.1\r\n" + "Host: " + _host + "\r\n" + "Connection: close\r\n" + "Accept: */*\r\n" + "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" + "Content-Type: application/json;charset=utf-8\r\n" + "Content-Length: " + msg.length() + "\r\n" + "\r\n" + msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while (_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    if (line.length() > 0)
      return 200;  // Success
  }

  return 400;  // Failed
}

int FirebaseESP8266::setBool(String path, bool data) {
  String Data = data ? "true" : "false";
  return FirebaseESP8266::setNum(path, Data);
}

int FirebaseESP8266::pushString(String path, String data) {
  Connect_to_host();
  String jsonObject = String("/") + path + String(".json");

  String msg = "\"" + data + "\"";

  _httpsClient.print(String("POST ") + jsonObject + " HTTP/1.1\r\n" + "Host: " + _host + "\r\n" + "Connection: close\r\n" + "Accept: */*\r\n" + "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" + "Content-Type: application/json;charset=utf-8\r\n" + "Content-Length: " + msg.length() + "\r\n" + "\r\n" + msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while (_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    if (line.length() > 0)
      return 200;  // Success
  }

  return 400;  // Failed
}

int FirebaseESP8266::pushInt(String path, int data) {
  String Data = String(data);
  return FirebaseESP8266::pushNum(path, Data);
}

int FirebaseESP8266::pushFloat(String path, float data) {
  String Data = String(data);
  return FirebaseESP8266::pushNum(path, Data);
}

int FirebaseESP8266::pushBool(String path, bool data) {
  String Data = data ? "true" : "false";
  return FirebaseESP8266::pushNum(path, Data);
}

int FirebaseESP8266::pushNum(String path, String msg) {
  Connect_to_host();
  String jsonObject = String("/") + path + String(".json");

  _httpsClient.print(String("POST ") + jsonObject + " HTTP/1.1\r\n" + "Host: " + _host + "\r\n" + "Connection: close\r\n" + "Accept: */*\r\n" + "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" + "Content-Type: application/json;charset=utf-8\r\n" + "Content-Length: " + msg.length() + "\r\n" + "\r\n" + msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while (_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    if (line.length() > 0)
      return 200;  // Success
  }

  return 400;  // Failed
}

String FirebaseESP8266::getString(String path) {
  FirebaseESP8266::getData(path);
  return _String;
}

int FirebaseESP8266::getInt(String path) {
  FirebaseESP8266::getData(path);
  return _int;
}

float FirebaseESP8266::getFloat(String path) {
  FirebaseESP8266::getData(path);
  return _float;
}

bool FirebaseESP8266::getBool(String path) {
  FirebaseESP8266::getData(path);
  return _bool;
}

void FirebaseESP8266::getData(String path) {
  Connect_to_host();
  String jsonObject = String("/") + path + String(".json");

  _httpsClient.print(String("GET ") + jsonObject + " HTTP/1.1\r\n" + "Host: " + _host + "\r\n" + "Connection: close\r\n\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while (_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    _int = line.toInt();
    _float = line.toFloat();
    _bool = line.equalsIgnoreCase("true");
    if (_json == false)
      _String = line.substring(1, line.length() - 1);
    else
      _String = line;
  }
}

int FirebaseESP8266::deleteData(String path) {
  Connect_to_host();
  String jsonObject = String("/") + path + String(".json");

  _httpsClient.print(String("DELETE ") + jsonObject + " HTTP/1.1\r\n" + "Host: " + _host + "\r\n" + "Connection: close\r\n\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while (_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    if (line.length() > 0)
      return 200;  // Success
  }

  return 400;  // Failed
}

void FirebaseESP8266::json(bool json) {
  _json = json;
}

void FirebaseESP8266::Connect_to_host() {
  int r = 0;
  while ((!_httpsClient.connect(_host, PORT)) && (r < 30)) {
    delay(100);
    r++;
  }
}
