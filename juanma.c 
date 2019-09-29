//
//  main.cpp
//  Chkn_OpenGL
//
//  Created by Juanma on 27/09/19.
//  Copyright © 2019 Juan Manuel Perez. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <GLUT/glut.h>

#define GL_SILENCE_DEPRECATION

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

void display(void);
void reshape(int, int);

void init(void) {
    
    /**
     * !glClearColor, especifica el color a limpiar
     * @param GLfloat red
     * @param GLfloat blue
     * @param GLfloat green
     * @param GLfloat alpha
     */
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
    /**
     * !glEnable, habilita capacidades de servidor de GL
     * ?GL_DEPTH_TEST, si esta habilitado hace comparaciones de profundidad y actualiza el depth buffer
     */
    glEnable(GL_DEPTH_TEST);
    
    /**
     * !glDepthFunc, especfica el valor utilizado para las comparaciones de profundidad
     * ?GL_LEQUAL, pasa si el valor es menor o igual al valor guardado de profundidad
     */
    glDepthFunc(GL_LESS);
    
//    gluLookAt(0.5f, 0.5f, 2.5f, 0.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f);
    
    /**
     * !glClearDepth, especifica el clear value para depth
     */
    glClearDepth(1.0f);
    
    glRotatef(45, 1.0, 0.0, 0.0);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(512, 512);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Minecraft Chicken");

    /**
     * !glutDisplayFunc, funciona como un call back a la funcion que se encuentra en el parametro
     */
    glutDisplayFunc(display);
    
    glutReshapeFunc(reshape);


    init();

    /**
     * !glutMainLoop, hace que entre en el loop de GLUT para el procesamiento de eventos
     */
    glutMainLoop();

    return 0;
//    glutInit(&argc, argv);
//    glutInitWindowSize(512, 512);
//    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
//
//    glutCreateWindow("Chkn");
//
//    glutDisplayFunc(display);
//
//    glutReshapeFunc(reshape);
//
////    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
////    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
////    glEnable(GL_LIGHT0);
////    glEnable(GL_LIGHTING);
//
////    glEnable(GL_DEPTH_TEST);
////    glDepthFunc(GL_LESS);
//
////    glMatrixMode(GL_PROJECTION);
////    gluPerspective(40.0, 0.0, 0.0, 10.0);
////    glMatrixMode(GL_MODELVIEW);
////    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//    glClearColor(0,0,0,1);
//
//    glutMainLoop();
//
//    return 0;
}

void display()
{
    /* clear the color buffer (resets everything to black) */
    glClear(GL_COLOR_BUFFER_BIT);
    
    /* set the current drawing color to red */
//    glColor3f(1, 0, 0);
    
    glBegin(GL_QUADS);
    
    glColor3f(1.0f,1.0f,1.0f);
    
    // Cabeza cara enfrente
    glVertex3f(-0.5f, 2.5f, 0.5f);
    glVertex3f(0.5f, 2.5f, 0.5f);
    glVertex3f(-0.5f, 1.5f, 0.5f);
    glVertex3f(0.5f, 1.5f, 0.5f);
    
    // Cabeza cara atrás
    glVertex3f(0.5f, 2.5f, -0.5f);
    glVertex3f(-0.5f, 2.5f, -0.5f);
    glVertex3f(0.5f, 1.5f, -0.5f);
    glVertex3f(-0.5f, 1.5f, -0.5f);
    
    // Cabeza cara izquierda
    glVertex3f(-0.5f, 2.5f, -0.5f);
    glVertex3f(-0.5f, 2.5f, 0.5f);
    glVertex3f(-0.5f, 1.5f, -0.5f);
    glVertex3f(-0.5f, 1.5f, 0.5f);
    
    // Cabeza cara derecha
    glVertex3f(0.5f, 2.5f, -0.5f);
    glVertex3f(0.5f, 2.5f, 0.5f);
    glVertex3f(0.5f, 1.5f, -0.5f);
    glVertex3f(0.5f, 1.5f, 0.5f);
    
    // Cabeza cara abajo
    glVertex3f(-0.5f, 1.5f, 0.5f);
    glVertex3f(0.5f, 1.5f, 0.5f);
    glVertex3f(-0.5f, 1.5f, -0.5f);
    glVertex3f(0.5f, 1.5f, -0.5f);
    
    // Cabeza cara arriba
    glVertex3f(-0.5f, 2.5f, 0.5f);
    glVertex3f(0.5f, 2.5f, 0.5f);
    glVertex3f(-0.5f, 2.5f, -0.5f);
    glVertex3f(0.5f, 2.5f, -0.5f);
    
    // Cuerpo cara enfrente
    glVertex3f(-1.0f, 1.5f, 0.0f);
    glVertex3f(1.0f, 1.5f, 0.0f);
    glVertex3f(-1.0f, 0.5f, -0.5f);
    glVertex3f(1.0f, -0.5f, 0.0f);    
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
    glColor3f(1.0f,0.5f,0.0f);    // Color Orange
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)
    glColor3f(1.0f,0.0f,0.0f);    // Color Red
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
    glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
    glColor3f(1.0f,0.0f,1.0f);    // Color Violet
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Right)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Right)
    
    
    /* tell OpenGL we're done drawing triangles */
    glEnd();
    
    /* swap the back and front buffers so we can see what we just drew */
    glutSwapBuffers();
}

/*! glut reshape callback function.  GLUT calls this function whenever
 the window is resized, including the first time it is created.
 You can use variables to keep track the current window size.
 */
void reshape(int x, int y)
{
    /* tell OpenGL we want to display in a recangle that is the
     same size as the window
     */
//    glViewport(0,0,x,y);
//
//    /* switch to the projection matrix */
//    glMatrixMode(GL_PROJECTION);
//
//    /* clear the projection matrix */
//    glLoadIdentity();
//
//    /* set the camera view, orthographic projection in 2D */
//    gluOrtho2D(0,x,0,y);
//
//    /* switch back to the model view matrix */
//    glMatrixMode(GL_MODELVIEW);
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
    
//    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
//    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}