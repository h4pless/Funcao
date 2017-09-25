#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include "Funcao.h";

using namespace std;

int size_x = 800;
int size_y = 480;
int pixel_size = 15;

float toRGBf(int x);
void draw();
void init();
void makeGrid();
void makeAxes();
void drawFunc();

float toRGBf(int x){
    return (float)x/255;
}

void draw(){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    makeGrid();

    glLineWidth(3);
    glColor3f(0.0, 0.0, 0.0);
    makeAxes();
    glLineWidth(1);


    glLineWidth(3.0f);
    glViewport(3*pixel_size, 3*pixel_size, size_x, 300);


    glColor3f(toRGBf(255), toRGBf(0), toRGBf(0));
    drawFunc();
    glLineWidth(1.0f);


    glFlush();
}

void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0 , size_x, 0, size_y);
    glClearColor(toRGBf(85), toRGBf(125), toRGBf(145), 1.0f);
}

void makeGrid(){

    for(int i = 0; i<=size_x; i+=pixel_size){
        glBegin(GL_LINES);
            glVertex2i(i, 0);
            glVertex2i(i, size_y);
        glEnd();
        glFlush();
    }
    for(int j = 0; j<=size_y; j+=pixel_size){
        glBegin(GL_LINES);
            glVertex2i(0, j);
            glVertex2i(size_x, j);
        glEnd();
        glFlush();
    }
}
/* ===> efeito legal

    void makeGrid(){


    for(int i = 0; i<=size_x; i+=pixel_size){
        glBegin(GL_LINES);
            glVertex2i(0, 0+i);
            glVertex2i(size_x, 1 );
            glVertex2i(0+i, 0);
            glVertex2i(1, size_y);
        glEnd();
        glFlush();
    }
}

*/

void makeAxes(){

    glBegin(GL_LINES);
        glVertex2i(3*pixel_size, 0);
        glVertex2i(3*pixel_size, size_y);
        glVertex2i(0, 3*pixel_size);
        glVertex2i(size_x, 3*pixel_size);
    glEnd();
    glFlush();
}

void drawFunc(){

    int x, y;

    Funcao *gauss1 = new Funcao(100, 100, 30);
    gauss1->makePoints(0, 500);

    glBegin(GL_LINE_STRIP);
    for(int i = 1 ; i < gauss1->retornaPontos().size(); i++){
        cout << "x: [" << gauss1->retornaPontos().at(i).at(0)<< "]  ";
        cout << "y: [" << gauss1->retornaPontos().at(i).at(1)<< "]  " << endl;
        glVertex2i(gauss1->retornaPontos().at(i).at(0)*3 , gauss1->retornaPontos().at(i).at(1)*3);
    }
    glEnd();
    glFlush();
}

int main(void){


    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(size_x,size_y);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Função Gauss");
    glutDisplayFunc(draw);
    init();



    glutMainLoop();
}



/*
    void myKeyboard(unsigned char key, int x, int y)

    void myMouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){


    }else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){

    }
    glFlush();
}
*/
