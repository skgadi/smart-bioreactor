#include "esphome.h"
#include "Adafruit_BMP085.h"

class MyCustomSensor : public PollingComponent, public Sensor {
 public:
  // constructor
  MyCustomSensor() : PollingComponent(15000) {}

  void setup() override {
    // This will be called by App.setup()
  }
  void update() override {
    publish_state(42.0);
  }
};