#include "../include/Retangulo.h"

Retangulo::Retangulo()
    :   Forma()
{
    setPontuacao( PONTUACAO_RETANGULO );
    setColor( DEFAULT_COLOR_RETANGULO );
}
Retangulo::~Retangulo()
{

}

void Retangulo::desenharForma( cv::Mat &image, cv::Point vertice1 )
{
    cv::Point vertice2( vertice1.x + X_RETANGULO, vertice1.y + Y_RETANGULO );

    setVertice1( vertice1 );
    setVertice2( vertice2 );
    
    cv::rectangle( image, getVertice1(), getVertice2(), getColor(), getThickness(), getLineType() );
}
 
void Retangulo::setVertice1( cv::Point vertice1 )
{
    this->vertice1 = vertice1;
}
void Retangulo::setVertice2( cv::Point vertice2 )
{
    this->vertice2 = vertice2;
}

cv::Point &Retangulo::getVertice1()
{
    return vertice1;
}
cv::Point Retangulo::getVertice2()
{
    return vertice2;
}