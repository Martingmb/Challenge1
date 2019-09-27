#include <GLUT/glut.h>

void drawBox(GLfloat x, GLfloat y, GLfloat z) {
    /**
     * *De limita los vertices de un primitivo
     * !GL_QUADS es el paramaetro que representa un modo, en especifico trata un grupo de 4 vertices como un quadrilatero
    */
    glBegin(GL_QUADS);

    /**
     * !glColor3f define el color actual
    */
    // glColor3f(1.0f, 0.0f, 0.0f);


    /**
     * *Cara que representa el frente
     * ?glVertex3f, especifica un vertice
     * @param x
     * @param y
     * @param z
     * ?glColor3f, especifica el color actual
     * @param red
     * @param blue
     * @param green
    */
	glColor3f(1.0f, 1.0f, 1.0f);
    // FRONT
	glVertex3f(-0.5f * x, -0.5f * y, 0.5f * z);
	glVertex3f( 0.5f * x, -0.5f * y, 0.5f * z);
	glVertex3f( 0.5f * x, 0.5f * y, 0.5f * z);
	glVertex3f(-0.5f * x, 0.5f * y, 0.5f * z);

	// BACK
	glVertex3f(-0.5f * x, -0.5f * y, -0.5f * z);
	glVertex3f(-0.5f * x, 0.5f * y, -0.5f * z);
	glVertex3f( 0.5f * x, 0.5f * y, -0.5f * z);
	glVertex3f( 0.5f * x, -0.5f * y, -0.5f * z);


	// LEFT
	glVertex3f(-0.5f * x, -0.5f * y, 0.5f * z);
	glVertex3f(-0.5f * x, 0.5f * y, 0.5f * z);
	glVertex3f(-0.5f * x, 0.5f * y, -0.5f * z);
	glVertex3f(-0.5f * x, -0.5f * y, -0.5f * z);
	// RIGHT
	glVertex3f( 0.5f * x, -0.5f * y, -0.5f * z);
	glVertex3f( 0.5f * x, 0.5f * y, -0.5f * z);
	glVertex3f( 0.5f * x, 0.5f * y, 0.5f * z);
	glVertex3f( 0.5f * x, -0.5f * y, 0.5f * z);

	// TOP
	glVertex3f(-0.5f * x, 0.5f * y, 0.5f * z);
	glVertex3f( 0.5f * x, 0.5f * y, 0.5f * z);
	glVertex3f( 0.5f * x, 0.5f * y, -0.5f * z);
	glVertex3f(-0.5f * x, 0.5f * y, -0.5f * z);

	// BOTTOM
	glVertex3f(-0.5f * x, -0.5f * y, 0.5f * z);
	glVertex3f(-0.5f * x, -0.5f * y, -0.5f * z);
	glVertex3f( 0.5f * x, -0.5f * y, -0.5f * z);
	glVertex3f( 0.5f * x, -0.5f * y, 0.5f * z);

    /**
     * !Termina la delimitacion de los vertices de un primitivo
    */
    glEnd();
}




/**
 * ?Esta funcion prepara el display y con drawBox dibuja los vertices
*/
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawBox(1.0f, 1.0f, 1.0f);
  drawBox(1.0f, 2.0f, 1.0f);
  glutSwapBuffers();
}

/**
 * 
*/
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
    glDepthFunc(GL_LEQUAL);

    /**
     * !glClearDepth, especifica el clear value para depth
    */
    glClearDepth(1.0f);

    glRotatef(90, 1.0, 0.0, 0.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Minecraft Chicken");

    /**
     * !glutDisplayFunc, funciona como un call back a la funcion que se encuentra en el parametro
    */
    glutDisplayFunc(display);


    init();

    /**
     * !glutMainLoop, hace que entre en el loop de GLUT para el procesamiento de eventos
    */
    glutMainLoop();

    return 0;
}