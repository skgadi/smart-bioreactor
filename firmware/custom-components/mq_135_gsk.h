#include "esphome.h"
#include "MQ135.h"

class MyCustomSensor2 : public PollingComponent, public Sensor {
 public:
 MQ135 gasSensor = MQ135(13);
  // constructor
  MyCustomSensor2() : PollingComponent(60000) {
    //gasSensor ;
  }

  void setup() override {
    // This will be called by App.setup()
    //(*dht).begin();
  }
  int i=0;
  void update() override {
    publish_state(gasSensor.getPPM());
  }
};