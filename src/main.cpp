#include <Arduino.h>
#include "led.h"
#include "botao.h"

Led ledAmareloA(7);
Led ledVerde(5);
Led ledVermelho(15);

Botao botao(11);
Botao botao2(12);
Botao botao3(14);

void setup() {
  Serial.begin(9600);
  ledAmareloA.iniciar();
  ledAmareloA.desligar();
  //ledAmareloA.ativaPiscar();

  ledVerde.iniciar();
  //ledVerde.ativaPiscar(1000);

  ledVermelho.iniciar();
  //ledVermelho.ativaPiscar(500);

  botao.iniciar();
  botao2.iniciar();
  botao3.iniciar();
}

void loop() {
 botao.atualizar();
 botao2.atualizar();
 botao3.atualizar();

 Serial.println(botao.apertado() );

 if(botao.apertado()){
    ledAmareloA.ligar();
 }
 else
    ledAmareloA.desligar();

  if(botao2.apertado()){
    ledVerde.ligar();
 }
 else
    ledVerde.desligar();
  
  if(botao3.apertado()){
    ledVermelho.ligar();
 }
 else
    ledVermelho.desligar();

 ledAmareloA.atualizar();
 ledVerde.atualizar();
 ledVermelho.atualizar();
}

