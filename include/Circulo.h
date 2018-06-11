#ifndef CIRCULO_H
#define CIRCULO_H

#include "Forma.h"

#define RAIO 25

class Circulo : public Forma
{
public:
    Circulo();
    virtual ~Circulo();

    virtual void desenharForma( cv::Mat &image, cv::Point center );

    void setCenter( cv::Point center );
    void setRaio( int raio );

    cv::Point getCenter();
    int getRaio();
private:
    int raio;
    cv::Point center;
};

#endif