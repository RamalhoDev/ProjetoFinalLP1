#include "../include/Forma.h"

Forma::Forma()
{
    setColor( DEFAULT_COLOR );
    setThickness( DEFAULT_THICKNESS );
    setLineType( DEFAULT_LINE_TYPE );
}
Forma::~Forma()
{

}

void Forma::setColor( const cv::Scalar &color )
{
    this->color = color;
}
void Forma::setThickness( int thickness )
{
    this->thickness = thickness;
}
void Forma::setLineType( int lineType )
{
    this->lineType = lineType;
}

cv::Scalar Forma::getColor()
{
    return color;
}
int Forma::getThickness()
{
    return thickness;
}
int Forma::getLineType()
{
    return lineType;
}

