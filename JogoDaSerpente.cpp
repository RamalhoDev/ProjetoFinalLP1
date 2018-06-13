#include "include/TelaJogo.h"
#include <iostream>
#include <string>
#include <exception>

#include "include/TelaJogo.h"

using namespace std;
using namespace cv;

void menuDeOpcoes( char opcao, cv::Mat &frame );
void janelaPrincipal( cv::Mat &frame );
void novaPartida();
void printRankingNaTela( cv::Mat &frame );
cv::Point detectFace( cv::Mat &image );
cv::Scalar gerarCorAleatoriaBGR();
void sair();

#define DEFAULT_TAMANHO_JANELA_PRINCIPAL 600, 800
#define DEFAULT_JANELA_HEIGHT 600
#define DEFAULT_JANELA_WIDTH 800
#define DEFAULT_POSICAO_RANKING 40, 70
#define DEFAULT_SCALE 1.3
#define ATRASO 100

std::string windowsName = "JOGO DA SERPENTE";
Comida *ptrComida = 0;
TelaJogo *ptrTela = 0;
int cor = 25;

int main()
{
    VideoCapture videoCap;
    Mat framePrincipal;
    double scale;
    ptrTela = new TelaJogo();
    int opcao;

    namedWindow( windowsName, WINDOW_AUTOSIZE );

    janelaPrincipal( framePrincipal );

    displayOverlay( windowsName, "SEJA BEM-VINDO AO JOGO DA SERPENTE", 10000 );

    createTrackbar( "COR DA TELA", windowsName, &cor, 50 );
    
    while( true )
    {
        printRankingNaTela( framePrincipal );

        opcao = waitKey( 10 );

        if( opcao != -1 )
           menuDeOpcoes( opcao, framePrincipal );
    }
    

    return 0;
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
            cout << "(!)Nenhuma opção reconhecida pelo programa foi digitada  " <<  endl;
    }
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
    Point comidaPoint, centerFacePoint;
    cv::Scalar corJanela;

    try
    {
        videoCap.open( 0 );
    }
    catch( Exception &error )
    {
        cout << "(!)" << error.what() << endl;
        exit( -1 );
    }

    // A variável i serve de controle pra alguns eventos no for
    for( int i = 0; ; )
    {
        videoCap >> frame;

        width = getWindowImageRect( windowsName ).width;
        height = getWindowImageRect( windowsName ).height;

        if( frame.empty() == true )
        {
            cout << "(!)Empty frame" << endl;
            exit( -1 );
        }

        centerFacePoint = detectFace( frame );

        corJanela = Scalar( cor*5, cor*5, cor*5 );
        
        ptrTela->desenharTela( frame, height, width, corJanela );

        // Apenas depois da janela ficar no tamanho do vídeo, poderá ser gerado um ponto aleatório nela
        if( i == ATRASO )
        {
            comidaPoint  = ptrTela->gerarPontoAleatorio();
            ptrComida = new Comida();
        }
        
        if( i <= ATRASO )
            i++;

        if( i > ATRASO )
            ptrComida->desenharComida( frame, comidaPoint );

        if( ptrTela->detectarProximidadeObjetos( centerFacePoint, comidaPoint ) == true )
        {
            comidaPoint = ptrTela->gerarPontoAleatorio();
            delete ptrComida;
            ptrComida = new Comida( gerarCorAleatoriaBGR() );
        }

        // Considera o outro vértice dos retângulos
        // getPontuacaoComida() só pode ser analisado quando a Comida for instanciada,
        // caso contrário, segFault. Para isso, utiliza-se o curto-circuito 
        if( i > ATRASO && ( ptrComida->getPontuacaoComida() == PONTUACAO_QUADRADO || 
            ptrComida->getPontuacaoComida() == PONTUACAO_RETANGULO ) )
        {
            if( ptrTela->detectarProximidadeObjetos( centerFacePoint, Point( comidaPoint.x + X_QUADRADO, comidaPoint.y + Y_RETANGULO ) ) )
            {
                comidaPoint = ptrTela->gerarPontoAleatorio();
                delete ptrComida;
                ptrComida = new Comida( gerarCorAleatoriaBGR() );
            }
        }

        imshow( windowsName, frame );

        if( waitKey( 10 ) == 27 )
        {
            delete ptrComida;
            break;
        }
    }
}

void printRankingNaTela( Mat &frame )
{
    int opcao;

    // Limpa o frame.
    frame = Mat( DEFAULT_TAMANHO_JANELA_PRINCIPAL, CV_8UC3, Scalar::all( 255 ) );

    QtFont font = fontQt( "Teste" );
    addText( frame, "Ranking should appear here", Point( DEFAULT_POSICAO_RANKING ), font );

    imshow( windowsName, frame );

    opcao = waitKey( 0 );

    menuDeOpcoes( opcao, frame );
}

Point detectFace( Mat &image )
{
    CascadeClassifier facesCascade( "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml" );
    vector<Rect> faces;
    Rect facePlayer;
    Mat gray, smallImg;
    Point centerFace( -50, -50 ); // valor padrão 

    if( facesCascade.empty() == true )
    {
        cout << "(!)Erro ao abrir facesCascade" << endl;
        exit( 1 );
    }

    cvtColor( image, gray, COLOR_BGR2GRAY );
    double fx = 1;
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    facesCascade.detectMultiScale( smallImg, faces,
        DEFAULT_SCALE, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );

    // Pega o Rect da última face detectadada
    if( faces.empty() == false )
    {
        facePlayer = faces.back();
        centerFace = Point( facePlayer.x + facePlayer.width*0.5, facePlayer.y + facePlayer.height*0.5 );
        cout << centerFace << endl;
    }

    return centerFace;
}

Scalar gerarCorAleatoriaBGR()
{
    int b, g, r;

    b = g = r = 0;

    srand( time( NULL ) );

    b = rand()%( 255 ) + 1;
    g = rand()%( 255 ) + 1;
    r = rand()%( 255 ) + 1;

    return Scalar( b, g, r );
}

void sair()
{
    cout << "(!)Programa encerrado pelo usuário" << endl;
    exit( -1 );
}