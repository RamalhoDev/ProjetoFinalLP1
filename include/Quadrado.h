#ifndef QUADRADO_H
#define QUADRADO_H

#include "Retangulo.h"

#define X_QUADRADO 50
#define Y_QUADRADO 50

class Quadrado : public Retangulo
{
public:
    Quadrado();
    virtual ~Quadrado();

    virtual void desenharForma( cv::Mat &image, cv::Point vertice1 );
};

#endif