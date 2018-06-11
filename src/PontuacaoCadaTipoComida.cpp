#include "../include/PontuacaoCadaTipoComida.h"

PontuacaoCadaTipoComida::PontuacaoCadaTipoComida()
{

}
PontuacaoCadaTipoComida::~PontuacaoCadaTipoComida()
{

} 

void PontuacaoCadaTipoComida::setPontuacao( int pontuacao )
{
    this->pontuacao = pontuacao;
}
int PontuacaoCadaTipoComida::getPontuacao() const
{
    return pontuacao;
}