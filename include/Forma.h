#ifndef FORMA_H
#define FORMA_H

#include <opencv2/opencv.hpp>
#include "PontuacaoCadaTipoComida.h"

#define DEFAULT_COLOR ( 0, 255, 255 )
#define DEFAULT_COLOR_RETANGULO ( 255, 255, 0 )
#define DEFAULT_COLOR_QUADRADO ( 255, 255, 0 )
#define DEFAULT_COLOR_CIRCULO ( 255, 255, 0 )
#define DEFAULT_THICKNESS -1
#define DEFAULT_LINE_TYPE 8

class Forma : public PontuacaoCadaTipoComida
{
public:
    Forma();
    virtual ~Forma();

    virtual void desenharForma( cv::Mat &image, cv::Point point ) = 0;

    void setColor( cv::Scalar color );
    void setThickness( int thickness );
    void setLineType( int lineType );

    cv::Scalar getColor();
    int getThickness();
    int getLineType();
private:
    cv::Scalar color;
    int thickness;
    int lineType;
};

#endif