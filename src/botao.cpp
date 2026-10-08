//! botao.h

#include "botao.h"

Botao::Botao(uint8_t pino) : _pinBotao(pino)
{
}

bool Botao::soltou()
{
    return _pressionou;
}

bool Botao::apertado()
{

    return _soltou;
}

// void Botao::atualizar()
// {
//     _pressionou = false;
//     _soltou = false;

//     _estadoBotaoAtual = digitalRead(_pinBotao);
//     if (_estadoBotaoAnterior != _estadoBotaoAtual)
//     {
//         _estadoBotaoAnterior = _estadoBotaoAtual;
//         _ultimaMudanca_ms = millis();
//     }
//     else if (tempoDecorrido() > _tempoDebounce_ms)
//     {
//         const bool acaoExecutada = _estadoUltimaAcao != _estadoBotaoAtual;
//         if (!acaoExecutada)
//         {
//             _estadoUltimaAcao = _estadoBotaoAtual;
//             const bool botaoPressionado = !_estadoBotaoAtual;

//             botaoPressionado ? _pressionou = true : _soltou = true;
//         }
//     }
// }

void Botao:: atualizar(){
    _pressionou = false;
    _soltou = false;

    _estadoBotaoAtual = digitalRead(_pinBotao);

     if (_estadoBotaoAnterior != _estadoBotaoAtual)
     {
         _estadoBotaoAnterior = _estadoBotaoAtual;
         _ultimaMudanca_ms = millis();
         return;
     }

    if(tempoDecorrido() < _tempoDebounce_ms){
        return;
    }
    if(_estadoBotaoAtual == _estadoBotaoAnterior) return;

    
    _estadoBotaoAnterior = _estadoBotaoAtual;
    
    const bool botaoPressionado = !_estadoBotaoAtual;

    botaoPressionado ? _pressionou = true : _soltou = true;


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

uint32_t Botao::tempoDecorrido(){
    return millis() - _ultimaMudanca_ms;
}