#ifndef RETANGULO_H
#define RETANGULO_H

#include "Forma.h"

#define X_RETANGULO 60
#define Y_RETANGULO 40

class Retangulo : public Forma
{
public:
    Retangulo();
    virtual ~Retangulo();

    virtual void desenharForma( cv::Mat &image, cv::Point vertice1 );

    void setVertice1( cv::Point vertice1 );
    void setVertice2( cv::Point vertice2 );

    cv::Point &getVertice1();
    cv::Point getVertice2();
private:
    cv::Point vertice1;
    cv::Point vertice2;
};

#endif