#include "../include/Circulo.h"

Circulo::Circulo()
    :   Forma()
{
    setPontuacao( PONTUACAO_CIRCULO );
    setRaio( RAIO );
    setColor( DEFAULT_COLOR_CIRCULO );
}
Circulo::~Circulo()
{

}

void Circulo::desenharForma( cv::Mat &image, cv::Point center )
{
    setCenter( center );

    cv::circle( image, center, getRaio(), getColor(), getThickness(), getLineType() );
}

void Circulo::setCenter( cv::Point center )
{
    this->center = center;
}
void Circulo::setRaio( int raio )
{
    this->raio = raio;
}

cv::Point Circulo::getCenter()
{
    return center;
}
int Circulo::getRaio()
{
    return raio;
}