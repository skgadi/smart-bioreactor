#include "esphome.h"
#include "CO2Sensor.h"

class MyCustomSensor2 : public PollingComponent, public Sensor {
 public:
 CO2Sensor co2Sensor = CO2Sensor(13, 0.99, 100);
  // constructor
  MyCustomSensor2() : PollingComponent(60000) {
    //gasSensor ;
  }

  void setup() override {
    // This will be called by App.setup()
    //(*dht).begin();
    co2Sensor.calibrate();
  }
  int i=0;
  void update() override {
    publish_state(co2Sensor.read());
  }
};