#include "esphome.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>

class MyCustomSensor1 : public PollingComponent, public Sensor {
 public:
  // constructor
  DHT* dht;
  Sensor *temperature_sensor = new Sensor();
  Sensor *humidity_sensor = new Sensor();
  MyCustomSensor1() : PollingComponent(60000) {
  dht = new DHT(4, 11);
  }

  void setup() override {
    // This will be called by App.setup()
    (*dht).begin();
  }
  int i=0;
  void update() override {
    temperature_sensor->publish_state((*dht).readTemperature());
    humidity_sensor->publish_state((*dht).readHumidity());
  }
};