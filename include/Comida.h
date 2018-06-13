#ifndef COMIDA_H
#define COMIDA_H

#include "Forma.h"
#include "Retangulo.h"
#include "Quadrado.h"
#include "Circulo.h"
#include <cstdlib>
#include <ctime>

class Comida
{
public:
    Comida();
    Comida( const cv::Scalar &color );
    virtual ~Comida();

    int getPontuacaoComida();

    void novaComida();
    void novaComida( const cv::Scalar &color );

    void desenharComida( cv::Mat &imagem, cv::Point point );
private:
    Forma *ptrForma;

    Forma *gerarComidaAleatoria();
};

#endif 