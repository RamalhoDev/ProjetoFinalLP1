#ifndef PONTUACAO_COMIDA_H
#define PONTUACAO_COMIDA_H

#define PONTUACAO_RETANGULO 5 // Mais comum
#define PONTUACAO_QUADRADO 7
#define PONTUACAO_CIRCULO 50 // Mais raro

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