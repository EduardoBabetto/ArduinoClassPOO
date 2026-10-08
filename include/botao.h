#ifndef BOTAO_H
#define BOTAO_H

#include <Arduino.h>

class Botao {
    private:
        uint8_t _pinBotao;
        bool _estadoBotaoAtual = false;
        bool _estadoBotaoAnterior = false;
        bool _pressionou = false;
        bool _soltou = false;
        uint32_t _ultimaMudanca_ms = 0;
        uint32_t _tempoDebounce_ms = 20;
        bool _estadoUltimaAcao = HIGH;

    public:
        Botao(uint8_t pin);

        uint32_t tempoDecorrido();
        bool apertado();
        void atualizar();
        void iniciar();
        bool soltou();

        bool getEstadoBotaoAtual();
        bool getEstadoBotaoAnterior();

};

#endif