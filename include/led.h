//!include/led.h


#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
   
    private:
    uint8_t _pinoLed;
    bool _estadoLed = 0;
    uint32_t _tempoAcaoAnterior_ms = 0;
    bool _estaPiscando = false;
    uint32_t _tempoEsperaAlternar_ms = 0;

    public:
    Led(uint8_t pino);
    void desligarPiscar();
    void ligar();
    void desligar();
    void ativaPiscar(uint32_t tempoEsepera=500);
    void iniciar();
    void atualizar();
    void alternar();

    uint8_t getPinoLed();
    void setEstadoLed(bool estado);



};


#endif