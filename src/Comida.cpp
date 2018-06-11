#include "../include/Comida.h"

Comida::Comida()
{
    novaComida();
}
Comida::~Comida()
{

}

void Comida::novaComida()
{
    ptrForma = gerarComidaAleatoria();
}

void Comida::desenharComida( cv::Mat &imagem, cv::Point point )
{
    ptrForma->desenharForma( imagem, point );
}
Forma *Comida::gerarComidaAleatoria()
{
    Forma *ptrForma;
    srand( time( NULL ) ); // Semente
    
    int numeroAleatorio = rand()%( 10 )+1; // Número aleatório de 1 a 10

    if( numeroAleatorio == 1 ) // Caso mais raro é o de Circulo, que vale mais pontos
    {
        ptrForma = new Circulo();
    }
    else if( numeroAleatorio == 2 || numeroAleatorio == 3 || numeroAleatorio == 4 )
    {
        ptrForma = new Quadrado();
    }
    else // provavelmente a forma que mais vai aparecer é o Retangulo, que vale menos pontos
    {
        ptrForma = new Retangulo();
    }

    return ptrForma;
}