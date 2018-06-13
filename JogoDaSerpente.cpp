#include "include/TelaJogo.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;
using namespace cv;

void janelaPrincipal( Mat &frame );
void novaPartida();
void menuDeOpcoes( char opcao, Mat &frame );
int printRankingNaTela( Mat &frame );
void sair();

#define DEFAULT_TAMANHO_JANELA_PRINCIPAL 600, 800
#define DEFAULT_JANELA_HEIGHT 600
#define DEFAULT_JANELA_WIDTH 800
#define DEFAULT_POSICAO_RANKING 40, 70

Comida *ptrComida;
TelaJogo *ptrTela;
string windowsName = "JOGO DA SERPENTE";

int main()
{
    VideoCapture videoCap;
    Mat framePrincipal;
    double scale;
    ptrTela = new TelaJogo();
    Scalar corJanela;
    int cor = 25;
    int opcao;

    namedWindow( windowsName, WINDOW_AUTOSIZE );

    janelaPrincipal( framePrincipal );

    displayOverlay( windowsName, "SEJA BEM-VINDO AO JOGO DA SERPENTE", 10000 );

    createTrackbar( "COR DA TELA", windowsName, &cor, 50 );
    
    while( true )
    {
        corJanela = Scalar( cor*5, cor*5, cor*5 );
        imshow( windowsName, framePrincipal );
        ptrTela->desenharTela( framePrincipal, DEFAULT_JANELA_HEIGHT, DEFAULT_JANELA_WIDTH, corJanela );

        opcao = waitKey( 10 );

        if( opcao != -1 )
            menuDeOpcoes( opcao, framePrincipal );
    }
    

    return 0;
}

void janelaPrincipal( Mat &frame )
{
    try
    {
        frame = Mat( DEFAULT_TAMANHO_JANELA_PRINCIPAL, CV_8UC3, Scalar::all( 255 ) );
    }
    catch( Exception &error )
    {
        cout << "(!)" << error.what() << endl;
    }
}

void novaPartida()
{
    VideoCapture videoCap;
    Mat frame;
    int width, height;

    try
    {
        videoCap.open( 0 );
    }
    catch( Exception &error )
    {
        cout << "(!)" << error.what() << endl;
    }

    while( true )
    {
        videoCap >> frame;

        width = getWindowImageRect( windowsName ).width;
        height = getWindowImageRect( windowsName ).height;

        if( frame.empty() == true )
        {
            cout << "(!)Empy frame" << endl;
            exit( 1 );
        }

        ptrTela->desenharTela( frame, height, width );
        imshow( windowsName, frame );

        if( waitKey( 10 ) == 27 )
        {
            break;
        }
    }
}

void menuDeOpcoes( char opcao, Mat &frame )
{
    switch( opcao )
    {
        case 'N':
        case 'n':
            novaPartida();
            break;
        case 'S':
        case 's':
            sair();
            break;
        case 'R':
        case 'r':
            printRankingNaTela( frame );
            break;
        default:
            cout << "(!)Nenhuma opção reconhecida pelo programa foi digitada  " << opcao <<  endl;
    }
}

void sair()
{
    cout << "(!)Programa encerrado pelo usuário" << endl;
    exit( 1 );
}

int printRankingNaTela( Mat &frame )
{
    int opcao;

    // O frame vem com a tela desenhada, vestígios do método desenharTela no main,
    // portanto precisa ficar branco de novo
    frame = Mat( DEFAULT_TAMANHO_JANELA_PRINCIPAL, CV_8UC3, Scalar::all( 255 ) );

    QtFont font = fontQt( "Times" );
    addText( frame, "Ranking should appear here", Point( DEFAULT_POSICAO_RANKING ), font );

    imshow( windowsName, frame );

    opcao = waitKey( 0 );

    // Retorna o frame limpo
    frame = Mat( DEFAULT_TAMANHO_JANELA_PRINCIPAL, CV_8UC3, Scalar::all( 255 ) );

    // Só sai desta função se o Esc for pressionado, caso contrário, recursividade
    if( opcao != 27)
        printRankingNaTela( frame );

    return opcao;
}