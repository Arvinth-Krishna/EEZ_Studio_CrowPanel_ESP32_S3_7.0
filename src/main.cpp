#include <Arduino.h>

#include "display_conf.h"
#include "ui.h"
#include "vars.h"

uint32_t counter{0};

void setup() {

  pinMode(38, OUTPUT);
	digitalWrite(38, LOW);

  Serial.begin(9600);

  display_conf::init();
  ui_init();
  display_conf::update();

}

void loop() {

  eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_COUNTER, counter++);

  display_conf::update();
  ui_tick();
  
  delay(1000);

}


