#include <Arduino.h>
#include "led.h"

Led ledAmareloA(7);
Led ledVerde(5);
Led ledVermelho(15);

void setup() {
  ledAmareloA.iniciar();
  ledAmareloA.ativaPiscar();

  ledVerde.iniciar();
  ledVerde.ativaPiscar(1000);

  ledVermelho.iniciar();
  ledVermelho.ativaPiscar(500);
}

void loop() {
 ledAmareloA.atualizar();
 ledVerde.atualizar();
 ledVermelho.atualizar();
}

