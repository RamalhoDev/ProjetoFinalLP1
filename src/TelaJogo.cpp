#include "../include/TelaJogo.h"
#include <cmath>

using namespace cv;
using namespace std;

TelaJogo::TelaJogo()
{
    setVertice1( Point( 0, 0 ) );
    setVertice2( Point( 0, 0 ) );
    setColor( DEFAULT_COLOR_TELA );
}
TelaJogo::~TelaJogo()
{

}

void TelaJogo::setVertice1( cv::Point point )
{
    vertice1 = point;
}
void TelaJogo::setVertice2( cv::Point point )
{
    vertice2 = point;
}
void TelaJogo::setColor( const Scalar &color )
{
    this->color = color;
}

cv::Point TelaJogo::getVertice1()
{
    return vertice1;
}
cv::Point TelaJogo::getVertice2()
{
    return vertice2;
}
Scalar TelaJogo::getColor()
{
    return color;
}

void TelaJogo::desenharTela( Mat &frame, int janelaOpenCVWidth, int janelaOpenCVHeight )
{
    Point vertice1( janelaOpenCVWidth*0.05, janelaOpenCVHeight*0.05 );
    Point vertice2( janelaOpenCVWidth*0.95, janelaOpenCVHeight*0.95 );
    // Ou seja, a tela desenhada tem 90% do tamanho da janela do OpenCV

    setVertice1( vertice1 );
    setVertice2( vertice2 );

    rectangle( frame, vertice1, vertice2, getColor(), DEFAULT_TELA_THICKNESS, DEFAULT_LINE_TYPE );
}

void TelaJogo::desenharTela( Mat &frame, int janelaOpenCVWidth, int janelaOpenCVHeight, Scalar &color )
{
    setColor( color );

    desenharTela( frame, janelaOpenCVWidth, janelaOpenCVHeight );
}


// Diz se objetos estão próximos baseado na distância entre eles e na constante simbólica DISTANCIA_PROXIMA
bool TelaJogo::detectarProximidadeObjetos( cv::Point referenciaObjeto1, cv::Point referenciaObjeto2 )
{
    double distancia = 0.0;

    int temp1 = pow( ( referenciaObjeto2.x - referenciaObjeto1.x ), 2 );
    int temp2 = pow( ( referenciaObjeto2.y - referenciaObjeto1.y ), 2 );

    distancia = sqrt( temp1 + temp2 );

    if( distancia <= DISTANCIA_PROXIMA )
        return true;
    else
        return false;
}

cv::Point TelaJogo::gerarPontoAleatorio()
{
    Point pointAleatorio;

    Point vertice1 = getVertice1();
    Point vertice2 = getVertice2();

    // variáveis que definem os limites de x e y do ponto aleatório a ser gerado
    int xBegin = vertice1.x; // Pega o x do vertice1 da tela
    int yBegin = vertice1.y; // Pega o y do vertice1 da tela
    int xEnd = vertice2.x; // Pega o x do vertice2 da tela
    int yEnd = vertice2.y; // Pega o y do vertice2 da tela

    srand( time( NULL ) );

    pointAleatorio.x = rand()%( xEnd - xBegin + 1 ) + xBegin;
    pointAleatorio.y = rand()%( yEnd - yBegin + 1 ) + yBegin;

    return pointAleatorio;
}