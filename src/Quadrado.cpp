#include "../include/Quadrado.h"

Quadrado::Quadrado()
    :   Retangulo()
{
    setPontuacao( PONTUACAO_QUADRADO );
    setColor( DEFAULT_COLOR_QUADRADO );
}
Quadrado::~Quadrado()
{

}

void Quadrado::desenharForma( cv::Mat &image, cv::Point vertice1 )
{
    cv::Point vertice2( vertice1.x + X_QUADRADO, vertice1.y + Y_QUADRADO );

    setVertice1( vertice1 );
    setVertice2( vertice2 );
    
    cv::rectangle( image, getVertice1(), getVertice2(), getColor(), getThickness(), getLineType() );  
}