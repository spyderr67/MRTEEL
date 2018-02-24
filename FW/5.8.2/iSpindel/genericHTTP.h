/**************************************************************

    "iSpindel"
    changes by S.Lang <universam@web.de>

 **************************************************************/

#ifndef _GENHTTP_H_
#define _GENHTTP_H_

#include <ESP8266WiFi.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson

#define GHTTPJSONARRAY 200

typedef struct genValue
{
  char *id;
  float value_id;
} gValue;

typedef struct genString
{
  char *id;
  char *value_id;
} gString;

class genericHTTP
{
public:
  genericHTTP(char *device, char *server, uint16_t port, char *url);
  bool sendHTTP();
  bool sendTCP();
  void add(char *variable_id, float value);
  void add(char *variable_id, char *value);
  // ~genericHTTP();

private:
  char *_device;
  char *_server;
  char *_url;
  uint16_t _port;
  const uint8_t ghmaxValues = 6;
  const uint8_t gStrmaxValues = 3;
  uint8_t currentValue;
  uint8_t currentStrValue;
  gValue *val;
  gString *gStr;
  WiFiClient _client;
};

#endif
