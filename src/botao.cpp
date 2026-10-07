//! botao.h

#include "botao.h"

Botao::Botao(uint8_t pino) : _pinBotao(pino)
{
}

bool Botao::soltou()
{
    if (_estadoBotaoAnterior != _estadoBotaoAtual)
    {
        if (!_estadoBotaoAtual)
        {
            return _estadoBotaoAtual;
        }
    }
}

bool Botao::apertado()
{
    if (_estadoBotaoAnterior != _estadoBotaoAtual)
    {
        if (!_estadoBotaoAtual)
        {
            return _estadoBotaoAnterior;
        }
    }
}

void Botao::atualizar()
{
    digitalWrite(_pinBotao, _estadoBotaoAtual);
}
void Botao::iniciar()
{
    pinMode(_pinBotao, INPUT_PULLUP);
    digitalWrite(_pinBotao, _estadoBotaoAtual);
}

bool Botao::getEstadoBotaoAtual()
{
    return _estadoBotaoAtual;
}

bool Botao::getEstadoBotaoAnterior()
{
    return _estadoBotaoAnterior;
}