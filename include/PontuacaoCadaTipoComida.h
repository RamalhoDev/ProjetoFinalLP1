#ifndef PONTUACAO_COMIDA_H
#define PONTUACAO_COMIDA_H

#define PONTUACAO_RETANGULO 2
#define PONTUACAO_QUADRADO 4
#define PONTUACAO_CIRCULO 10

class PontuacaoCadaTipoComida
{
public:
    PontuacaoCadaTipoComida();
    virtual ~PontuacaoCadaTipoComida();
    
    void setPontuacao( int pontuacao );
    int getPontuacao() const;
private:
    int pontuacao;
};

#endif