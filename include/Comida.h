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
    virtual ~Comida();

    void novaComida();

    void desenharComida( cv::Mat &imagem, cv::Point point );
private:
    Forma *ptrForma;

    Forma *gerarComidaAleatoria();
};

#endif 