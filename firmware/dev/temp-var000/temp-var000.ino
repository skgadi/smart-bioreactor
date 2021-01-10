#include "configCommon.h";
#include "configWifi.h";

#include "configSpecific.h";





const char *gsk_types_0[] = { nullptr};
ThingDevice gsk_Device("device-0", "Device 0", gsk_types_0);
ThingProperty gsk_measure_0("Temperature name 0", "Temperature name 1", NUMBER, "TemperatureSensor");


void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.print("Connecting to \"");
  Serial.print(ssid);
  Serial.println("\"");
#if defined(ESP8266) || defined(ESP32)
  WiFi.mode(WIFI_STA);
#endif
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  adapter = new WebThingAdapter(GSK_AdapterNme, WiFi.localIP());

  gsk_Device.addProperty(&gsk_measure_0);
  adapter->addDevice(&gsk_Device);
  
  adapter->begin();

  Serial.println("HTTP server started");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.print("/things/");
  Serial.println(gsk_Device.id);

#ifdef analogWriteRange
  analogWriteRange(255);
#endif

}

int i=0;
void loop(void) {
  delay(1000);
  if (i++ >30) {
    i=0;    
  }
  ThingPropertyValue sensorValue;
  sensorValue.number = i;
  gsk_measure_0.setValue(sensorValue);
  adapter->update();
}
