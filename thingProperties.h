#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[] = "849f4e42-555e-4965-88a1-0f5a51f11d43";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)


String p1;
String p2;
int parking_1;
int parking_2;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(p1, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(p2, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(parking_1, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(parking_2, READ, 1 * SECONDS, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
