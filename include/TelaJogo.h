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

    cv::Point getVertice1();
    cv::Point getVertice2();

    void desenharTela( cv::Mat &frame, int janelaOpenCVWidth, int janelaOpenCVHeight );
    bool detectarProximidadeObjetos( cv::Point referenciaObjeto1, cv::Point referenciaObjeto2 );
    cv::Point gerarPontosAleatorios();
private:
    cv::Point vertice1;
    cv::Point vertice2;
};

#endif