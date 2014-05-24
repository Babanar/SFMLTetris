#include "OpenGL_Manager.hpp"
using namespace std;
OpenGL_Manager::OpenGL_Manager(){
    //_tetrisBoard = NULL;

    _isActivate = true;
    _inclinaison = -35;
    _tetrisBoard = new int*[BOARD_WIDTH];
    float test = 0;
}

void OpenGL_Manager::setTetrisBoard(int tetrisBoard[][BOARD_HEIGHT]){
    for(int i=0;i<BOARD_WIDTH;++i)
            _tetrisBoard[i]=tetrisBoard[i];

}

void OpenGL_Manager::preDraw(){

        if(_tetrisBoard == NULL)
            return;

        glClear(GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
       // glTranslatef(0.f, 0.f, -200.f);
//        float t=0.5;
//        glRotatef(t * 50, 1.f, 0.f, 0.f);
//        glRotatef(t * 30, 0.f, 1.f, 0.f);
//        glRotatef(t * 90, 0.f, 0.f, 1.f);


    //glRotatef(10, 0.f, 1.f, 0.f);

    glTranslatef(-100,0,-1300+(_inclinaison*10));
    glRotatef(_inclinaison, 1.f, 0.f, 0.f);
    glRotatef(test, 0.f, 1.f, 0.f);
    glRotatef(test, 0.f, 0.f, 1.f);

    test +=0.8;
    glTranslatef(-100.f*(BOARD_WIDTH/2),100.f*(BOARD_HEIGHT/2),0);
    for(int i=0;i<BOARD_WIDTH;++i){
            glTranslatef(100.f,0.f,0.f);
        for(int j=0;j<BOARD_HEIGHT;++j){
             glTranslatef(0.f,-100.f,0.f);
                    color[0]=0.2;
                    color[1]=0.2;
                    color[2]=0.2;
                    drawArretes();
            if(_tetrisBoard[i][j]>29 && _tetrisBoard[i][j]<37){
                sf::Color c = Tetromino::couleurs[_tetrisBoard[i][j]-30];
                color[0]= c.r/float(255)*(64.0/255);
                color[1]= c.g/float(255)*(64.0/255);
                color[2]= c.b/float(255)*(64.0/255);
                drawShape();
            }
            else if(_tetrisBoard[i][j]>19 && _tetrisBoard[i][j]<27){
                sf::Color c = Tetromino::couleurs[_tetrisBoard[i][j]-20];
                color[0]= c.r/float(255);
                color[1]= c.g/float(255);
                color[2]= c.b/float(255);
                drawShape();
            }
            else if(_tetrisBoard[i][j]>9 && _tetrisBoard[i][j]<17){
                sf::Color c = Tetromino::couleurs[_tetrisBoard[i][j]-10];
                color[0]= c.r/float(255)-0.2;
                color[1]= c.g/float(255)-0.2;
                color[2]= c.b/float(255)-0.2;
                drawShape();
            }

        }
        glTranslatef(0.f,100.f*BOARD_HEIGHT,0.f);

    }
    //drawShape(0,0);
}

void OpenGL_Manager::drawShape(){

        glBegin(GL_QUADS);
            setGLColor(-0.4,-0.4,-0.4);
            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f(-50.f,  50.f, -50.f);
            glVertex3f( 50.f,  50.f, -50.f);
            glVertex3f( 50.f, -50.f, -50.f);
            //FACE
            glColor3f(color[0], color[1], color[2]);
            glVertex3f(-50.f, -50.f, 50.f);
            glVertex3f(-50.f,  50.f, 50.f);
            glVertex3f( 50.f,  50.f, 50.f);
            glVertex3f( 50.f, -50.f, 50.f);
            setGLColor(-0.2,-0.2,-0.2);
            //GAUCHE
            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f(-50.f,  50.f, -50.f);
            glVertex3f(-50.f,  50.f,  50.f);
            glVertex3f(-50.f, -50.f,  50.f);
            setGLColor(-0.3,-0.3,-0.3);
            //Droite
            glVertex3f(50.f, -50.f, -50.f);
            glVertex3f(50.f,  50.f, -50.f);
            glVertex3f(50.f,  50.f,  50.f);
            glVertex3f(50.f, -50.f,  50.f);

            glVertex3f(-50.f, -50.f,  50.f);
            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f( 50.f, -50.f, -50.f);
            glVertex3f( 50.f, -50.f,  50.f);
            //HAUT
            setGLColor(-0.1,-0.1,-0.1);
            glVertex3f(-50.f, 50.f,  50.f);
            glVertex3f(-50.f, 50.f, -50.f);
            glVertex3f( 50.f, 50.f, -50.f);
            glVertex3f( 50.f, 50.f,  50.f);
        glEnd();

}

void OpenGL_Manager::drawArretes(){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) ;
        glBegin(GL_QUADS);

            setGLColor();
            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f(-50.f,  50.f, -50.f);
            glVertex3f( 50.f,  50.f, -50.f);
            glVertex3f( 50.f, -50.f, -50.f);

            glVertex3f(-50.f, -50.f, 50.f);
            glVertex3f(-50.f,  50.f, 50.f);
            glVertex3f( 50.f,  50.f, 50.f);
            glVertex3f( 50.f, -50.f, 50.f);
            //setGLColor(-0.5,-0.5,-0.5);
            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f(-50.f,  50.f, -50.f);
            glVertex3f(-50.f,  50.f,  50.f);
            glVertex3f(-50.f, -50.f,  50.f);

            glVertex3f(50.f, -50.f, -50.f);
            glVertex3f(50.f,  50.f, -50.f);
            glVertex3f(50.f,  50.f,  50.f);
            glVertex3f(50.f, -50.f,  50.f);

            glVertex3f(-50.f, -50.f,  50.f);
            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f( 50.f, -50.f, -50.f);
            glVertex3f( 50.f, -50.f,  50.f);

            glVertex3f(-50.f, 50.f,  50.f);
            glVertex3f(-50.f, 50.f, -50.f);
            glVertex3f( 50.f, 50.f, -50.f);
            glVertex3f( 50.f, 50.f,  50.f);


        glEnd();
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL) ;

}

OpenGL_Manager::~OpenGL_Manager(){
    delete[] _tetrisBoard;
}

void OpenGL_Manager::setGLColor(float r, float g, float b){
    float tmp[3];
    tmp[0]=r;
    tmp[1]=g;
    tmp[2]=b;

    for(int i=0;i<3;++i)
    {
        tmp[i]+=color[i];
        if(tmp[i]<0)
        tmp[i]=0;
        else if(tmp[i]>1)
        tmp[i]=1;
    }
    glColor3f(tmp[0], tmp[1], tmp[2]);
}
void OpenGL_Manager::setGLColor(){
    setGLColor(0,0,0);
}
bool OpenGL_Manager::getActivate(){
    return _isActivate;
}
float OpenGL_Manager::getInclinaison(){
    return _inclinaison;
}
void OpenGL_Manager::setActivate(bool _n){
    _isActivate = _n;
}
void OpenGL_Manager::setInclinaison(float _n){
    _inclinaison = _n;
}
