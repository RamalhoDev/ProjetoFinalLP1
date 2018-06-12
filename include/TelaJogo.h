#ifndef TELA_JOGO_H
#define TELA_JOGO_H

#include "Comida.h"

#define DEFAULT_COLOR_TELA ( 255, 255, 255 )
#define DEFAULT_TELA_THICKNESS 2
#define DISTANCIA_PROXIMA 50

class TelaJogo
{
public:
    TelaJogo();
    virtual ~TelaJogo();

    void setVertice1( cv::Point point );
    void setVertice2( cv::Point point );
    void setColor( const cv::Scalar &color );

    cv::Point getVertice1();
    cv::Point getVertice2();
    cv::Scalar getColor();

    void desenharTela( cv::Mat &frame, int janelaOpenCVWidth, int janelaOpenCVHeight );
    void desenharTela( cv::Mat &frame, int janelaOpenCVWidth, int janelaOpenCVHeight, cv::Scalar &color );
    bool detectarProximidadeObjetos( cv::Point referenciaObjeto1, cv::Point referenciaObjeto2 );
    cv::Point gerarPontoAleatorio();
private:
    cv::Point vertice1;
    cv::Point vertice2;
    cv::Scalar color;
};

#endif