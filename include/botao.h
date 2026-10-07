#ifndef BOTAO_H
#define BOTAO_H

#include <Arduino.h>

class Botao {
    private:
        uint8_t _pinBotao;
        bool _estadoBotaoAtual;
        bool _estadoBotaoAnterior;

    public:
        Botao(uint8_t pin);
        bool apertado();
        void atualizar();
        void iniciar();
        bool soltou();

        bool getEstadoBotaoAtual();
        bool getEstadoBotaoAnterior();

};

#endif