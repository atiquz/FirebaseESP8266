#ifndef FirebaseESP8266_h
#define FirebaseESP8266_h
#include "Arduino.h"

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#else
#error "Please select an ESP8266 board for this sketch."
#endif

#define PORT 443

class FirebaseESP8266
{
  public:
    FirebaseESP8266(String referenceURL);
    int setString(String path, String data);
    int setNum(String path, String data);
    int setInt(String path, int data);
    int setFloat(String path, float data);
    int setBool(String path, bool data); // New method for setting boolean values
    int pushString(String path, String data);
    int pushNum(String path, String data);
    int pushInt(String path, int data);
    int pushFloat(String path, float data);
    int pushBool(String path, bool data); // New method for pushing boolean values
    void getData(String path);
    String getString(String path);
    int getInt(String path);
    float getFloat(String path);
    bool getBool(String path); // New method for retrieving boolean values
    int deleteData(String path);
    void json(bool json);
    void Connect_to_host();

  private:
    String _host;
    bool _json = false;
    String _String;
    int _int;
    float _float;
    bool _bool; // Added variable to store boolean values
    WiFiClientSecure _httpsClient;
};

#endif