//! src/led.cpp

#include "led.h"

Led::Led(uint8_t pino) : _pinoLed(pino)
{
   // _pinoLed= pino;
}

void Led::ligar()
{
   _estadoLed = HIGH;
}

void Led::desligar()
{
   _estadoLed = LOW;
}

void Led::ativaPiscar(uint32_t tempoEspera){
    _estaPiscando = true;
    _tempoEsperaAlternar_ms = tempoEspera;

}

void Led::desligarPiscar(){
    _estaPiscando = false;
    _estadoLed = LOW;
}

void Led::iniciar(){
    pinMode(_pinoLed, OUTPUT);
    digitalWrite(_pinoLed,_estadoLed);
    _tempoAcaoAnterior_ms = millis();
}

void Led::atualizar(){

    if(_estaPiscando)
    {
        const uint32_t tempoDecorrido = millis() - _tempoAcaoAnterior_ms;
        if(tempoDecorrido  >= _tempoEsperaAlternar_ms){
            _tempoAcaoAnterior_ms = millis();
            alternar();
        }
    }
    digitalWrite(_pinoLed,_estadoLed);
}

void Led::alternar(){
    _estadoLed = !_estadoLed;

}

uint8_t Led::getPinoLed(){
    return _pinoLed;
}

void Led::setEstadoLed(bool estado){
    _estadoLed = estado;
}
