#include <GLUT/glut.h>
#include <stdio.h>

/**
 * !Parameters for scaling
*/

float xScale = 0.2f;
float yScale = 0.2f;
float zScale = 0.2f;

/**
 * !Parameters for translating
*/

float xTranslate = 0.0f;
float yTranslate = 0.0f;
float zTranslate = 0.0f;

/**
 * !Parameters for rotating
 * ?To rotate in an axis you change the angle and put 1 in the desired axis
*/

double xAxis = 0.0;
double yAxis = 1.0;
double zAxis = 0.0;

int angle = 90;


void drawBox(GLfloat x, GLfloat y, GLfloat z) {

    

    /**
     * *De limita los vertices de un primitivo
     * !GL_QUADS es el paramaetro que representa un modo, en especifico trata un grupo de 4 vertices como un quadrilatero
    */
    glBegin(GL_QUADS);

    /**
     * !glColor3f define el color actual
    */

    /**
     * *Cara
     * ?glVertex3f, especifica un vertice
     * @param x
     * @param y
     * @param z
     * ?glColor3f, especifica el color actual
     * @param red
     * @param blue
     * @param green
    */

    // Partes Blancas
    glColor3f(1.0f,1.0f,1.0f);

    /**
     * Cabeza
    */
    //Frente
    glVertex3f(-0.5f, 2.5f, 1.5f); //v1
    glVertex3f(0.5f, 2.5f, 1.5f); //v2
    glVertex3f(0.5f, 1.5f, 1.5f); //v3
    glVertex3f(-0.5f, 1.5f, 1.5f); //v4

    //Atras
    glVertex3f(0.5f, 2.5f, 0.5f); //v6
    glVertex3f(-0.5f, 2.5f, 0.5f); //v5
    glVertex3f(-0.5f, 1.5f, 0.5f); //v8
    glVertex3f(0.5f, 1.5f, 0.5f); //v7

    //Izquierda
    glVertex3f(-0.5f, 2.5f, 0.5f); //v5
    glVertex3f(-0.5f, 2.5f, 1.5f); //v1
    glVertex3f(-0.5f, 1.5f, 1.5f); //v4
    glVertex3f(-0.5f, 1.5f, 0.5f); //v8

    //Derecha
    glVertex3f(0.5f, 2.5f, 1.5f); //v2
    glVertex3f(0.5f, 2.5f, 0.5f); //v6
    glVertex3f(0.5f, 1.5f, 0.5f); //v7
    glVertex3f(0.5f, 1.5f, 1.5f); //v3

    //Debajo
    glVertex3f(-0.5f, 1.5f, 1.5f); //v4
    glVertex3f(0.5f, 1.5f, 1.5f); //v3
    glVertex3f(0.5f, 1.5f, 0.5f); //v7
    glVertex3f(-0.5f, 1.5f, 0.5f); //v8

    //Arriba
    glVertex3f(-0.5f, 2.5f, 0.5f); //v5
    glVertex3f(0.5f, 2.5f, 0.5f); //v6
    glVertex3f(0.5f, 2.5f, 1.5f); //v2
    glVertex3f(-0.5f, 2.5f, 1.5f); //v1

    /**
     * Cuerpo
    */
    //Frente
    glVertex3f(-1.0f, 1.5f, 1.0f); //v1
    glVertex3f(1.0f, 1.5f, 1.0f); //v2
    glVertex3f(1.0f, -0.5f, 1.0f); //v3
    glVertex3f(-1.0f, -0.5f, 1.0f); //v4

    //Atras
    glVertex3f(1.0f, 1.5f, -1.0f); //v6
    glVertex3f(-1.0f, 1.5f, -1.0f); //v5
    glVertex3f(-1.0f, -0.5f, -1.0f); //v8
    glVertex3f(1.0f, -0.5f, -1.0f); //v7

    //Izquierda
    glVertex3f(-1.0f, 1.5f, -1.0f); //v5
    glVertex3f(-1.0f, 1.5f, 1.0f); //v1
    glVertex3f(-1.0f, -0.5f, 1.0f); //v4
    glVertex3f(-1.0f, -0.5f, -1.0f); //v8

    //Derecha
    glVertex3f(1.0f, 1.5f, 1.0f); //v2
    glVertex3f(1.0f, 1.5f, -1.0f); //v6
    glVertex3f(1.0f, -0.5f, -1.0f); //v7
    glVertex3f(1.0f, -0.5f, 1.0f); //v3

    //Debajo
    glVertex3f(-1.0f, -0.5f, 1.0f); //v4
    glVertex3f(1.0f, -0.5f, 1.0f); //v3
    glVertex3f(1.0f, -0.5f, -1.0f); //v7
    glVertex3f(-1.0f, -0.5f, -1.0f); //v8

    //Arriba
    glVertex3f(-1.0f, 1.5f, -1.0f); //v5
    glVertex3f(1.0f, 1.5f, -1.0f); //v6
    glVertex3f(1.0f, 1.5f, 1.0f); //v2
    glVertex3f(-1.0f, 1.5f, 1.0f); //v1

    /**
     * Ala Derecha
    */
    //Frente
    glVertex3f(-1.2f, 1.5f, 0.75f); //v1
    glVertex3f(-0.8f, 1.5f, 0.75f); //v2
    glVertex3f(-0.8f, 0.0f, 0.75f); //v3
    glVertex3f(-1.2f, 0.0f, 0.75f); //v4

    //Atras
    glVertex3f(-0.8f, 1.5f, -0.75f); //v6
    glVertex3f(-1.2f, 1.5f, -0.75f); //v5
    glVertex3f(-1.2f, 0.0f, -0.75f); //v8
    glVertex3f(-0.8f, 0.0f, -0.75f); //v7

    //Izquierda
    glVertex3f(-1.2f, 1.5f, -0.75f); //v5
    glVertex3f(-1.2f, 1.5f, 0.75f); //v1
    glVertex3f(-1.2f, 0.0f, 0.75f); //v4
    glVertex3f(-1.2f, 0.0f, -0.75f); //v8

    //Derecha
    glVertex3f(-0.8f, 1.5f, 0.75f); //v2
    glVertex3f(-0.8f, 1.5f, -0.75f); //v6
    glVertex3f(-0.8f, 0.0f, -0.75f); //v7
    glVertex3f(-0.8f, 0.0f, 0.75f); //v3

    //Debajo
    glVertex3f(-1.2f, 0.0f, 0.75f); //v4
    glVertex3f(-0.8f, 0.0f, 0.75f); //v3
    glVertex3f(-0.8f, 0.0f, -0.75f); //v7
    glVertex3f(-1.2f, 0.0f, -0.75f); //v8

    //Arriba
    glVertex3f(-1.2f, 1.5f, -0.75f); //v5
    glVertex3f(-0.8f, 1.5f, -0.75f); //v6
    glVertex3f(-0.8f, 1.5f, 0.75f); //v2
    glVertex3f(-1.2f, 1.5f, 0.75f); //v1

    /**
     * Ala Izquierda
    */
    //Frente
    glVertex3f(0.8f, 1.5f, 0.75f); //v1
    glVertex3f(1.2f, 1.5f, 0.75f); //v2
    glVertex3f(1.2f, 0.0f, 0.75f); //v3
    glVertex3f(0.8f, 0.0f, 0.75f); //v4

    //Atras
    glVertex3f(1.2f, 1.5f, -0.75f); //v6
    glVertex3f(0.8f, 1.5f, -0.75f); //v5
    glVertex3f(1.2f, 0.0f, -0.75f); //v7
    glVertex3f(0.8f, 0.0f, -0.75f); //v8

    //Izquierda
    glVertex3f(0.8f, 1.5f, -0.75f); //v5
    glVertex3f(0.8f, 1.5f, 0.75f); //v1
    glVertex3f(0.8f, 0.0f, 0.75f); //v4
    glVertex3f(0.8f, 0.0f, -0.75f); //v8

    //Derecha
    glVertex3f(1.2f, 1.5f, 0.75f); //v2
    glVertex3f(1.2f, 1.5f, -0.75f); //v6
    glVertex3f(1.2f, 0.0f, -0.75f); //v7
    glVertex3f(1.2f, 0.0f, 0.75f); //v3

    //Debajo
    glVertex3f(0.8f, 0.0f, 0.75f); //v4
    glVertex3f(1.2f, 0.0f, 0.75f); //v3
    glVertex3f(1.2f, 0.0f, -0.75f); //v7
    glVertex3f(0.8f, 0.0f, -0.75f); //v8

    //Arriba
    glVertex3f(0.8f, 1.5f, -0.75f); //v5
    glVertex3f(1.2f, 1.5f, -0.75f); //v6
    glVertex3f(1.2f, 1.5f, 0.75f); //v2
    glVertex3f(0.8f, 1.5f, 0.75f); //v1


    //Partes Amarillas
    glColor3f(1.0f,1.0f,0.0f);

    /**
     * Pico
    */
    //Frente
    glVertex3f(-0.5f, 2.0f, 1.8f); //v1
    glVertex3f(0.5f, 2.0f, 1.8f); //v2
    glVertex3f(0.5f, 1.8f, 1.8f); //v3
    glVertex3f(-0.5f, 1.8f, 1.8f); //v4

    //Detras
    glVertex3f(0.5f, 2.0f, 1.5f); //v6
    glVertex3f(-0.5f, 2.0f, 1.5f); //v5
    glVertex3f(-0.5f, 1.8f, 1.5f); //v8
    glVertex3f(0.5f, 1.8f, 1.5f); //v7

    //Izquierda
    glVertex3f(-0.5f, 2.0f, 1.5f); //v5
    glVertex3f(-0.5f, 2.0f, 1.8f); //v1
    glVertex3f(-0.5f, 1.8f, 1.8f); //v4
    glVertex3f(-0.5f, 1.8f, 1.5f); //v8

    //Derecha
    glVertex3f(0.5f, 2.0f, 1.8f); //v2
    glVertex3f(0.5f, 2.0f, 1.5f); //v6
    glVertex3f(0.5f, 1.8f, 1.5f); //v7
    glVertex3f(-0.5f, 1.8f, 1.5f); //v8

    //Debajo
    glVertex3f(-0.5f, 1.8f, 1.8f); //v4
    glVertex3f(0.5f, 1.8f, 1.8f); //v3
    glVertex3f(0.5f, 1.8f, 1.5f); //v7
    glVertex3f(-0.5f, 1.8f, 1.5f); //v8

    //Arriba
    glVertex3f(-0.5f, 2.0f, 1.5f); //v5
    glVertex3f(0.5f, 2.0f, 1.5f); //v6
    glVertex3f(0.5f, 2.0f, 1.8f); //v2
    glVertex3f(-0.5f, 2.0f, 1.8f); //v1  
    
    /**
     * Pierna Derecha
    */
    //Frente
    glVertex3f(-0.7, -0.5f, 0.2f); //v1
    glVertex3f(-0.3, -0.5f, 0.2f); //v2
    glVertex3f(-0.3, -2.0f, 0.2f); //v3
    glVertex3f(-0.7, -2.0f, 0.2f); //v4

    //Atras
    glVertex3f(-0.3, -0.5f, -0.2f); //v6
    glVertex3f(-0.7, -0.5f, -0.2f); //v5
    glVertex3f(-0.7, -2.0f, -0.2f); //v8
    glVertex3f(-0.3, -2.0f, -0.2f); //v7

    //Izquierda
    glVertex3f(-0.7, -0.5f, -0.2f); //v5
    glVertex3f(-0.7, -0.5f, 0.2f); //v1
    glVertex3f(-0.7, -2.0f, 0.2f); //v4
    glVertex3f(-0.7, -2.0f, -0.2f); //v8

    //Derecha
    glVertex3f(-0.3, -0.5f, 0.2f); //v2
    glVertex3f(-0.3, -0.5f, -0.2f); //v6
    glVertex3f(-0.3, -2.0f, -0.2f); //v7
    glVertex3f(-0.3, -2.0f, 0.2f); //v3

    //Debajo
    glVertex3f(-0.7, -2.0f, 0.2f); //v4
    glVertex3f(-0.3, -2.0f, 0.2f); //v3
    glVertex3f(-0.3, -2.0f, -0.2f); //v7 
    glVertex3f(-0.7, -2.0f, -0.2f); //v8

    //Arriba
    glVertex3f(-0.7, -0.5f, -0.2f); //v5
    glVertex3f(-0.3, -0.5f, -0.2f); //v6
    glVertex3f(-0.3, -0.5f, 0.2f); //v2
    glVertex3f(-0.7, -0.5f, 0.2f); //v1

    /**
     * Pierna Izquierda
    */

    //Frente
    glVertex3f(0.3f, -0.5f, 0.2f); //v1
    glVertex3f(0.7f, -0.5f, 0.2f); //v2
    glVertex3f(0.7f, -2.0f, 0.2f); //v3
    glVertex3f(0.3f, -2.0f, 0.2f); //v4

    //Atras
    glVertex3f(0.7f, -0.5f, -0.2f); //v6
    glVertex3f(0.3f, -0.5f, -0.2f); //v5
    glVertex3f(0.3f, -2.0f, -0.2f); //v8
    glVertex3f(0.7f, -2.0f, -0.2f); //v7

    //Izquierda
    glVertex3f(0.3f, -0.5f, -0.2f); //v5
    glVertex3f(0.3f, -0.5f, 0.2f); //v1
    glVertex3f(0.3f, -2.0f, 0.2f); //v4
    glVertex3f(0.3f, -2.0f, -0.2f); //v8

    //Derecha
    glVertex3f(0.7f, -0.5f, 0.2f); //v2
    glVertex3f(0.7f, -0.5f, -0.2f); //v6
    glVertex3f(0.7f, -2.0f, -0.2f); //v7
    glVertex3f(0.7f, -2.0f, 0.2f); //v3

    //Debajo
    glVertex3f(0.3f, -2.0f, 0.2f); //v4
    glVertex3f(0.7f, -2.0f, 0.2f); //v3
    glVertex3f(0.7f, -2.0f, -0.2f); //v7
    glVertex3f(0.3f, -2.0f, -0.2f); //v8

    //Arriba
    glVertex3f(0.3f, -0.5f, -0.2f); //v5
    glVertex3f(0.7f, -0.5f, -0.2f); //v6
    glVertex3f(0.7f, -0.5f, 0.2f); //v2
    glVertex3f(0.3f, -0.5f, 0.2f); //v1


    //Partes Rojas
    glColor3f(1.0f,0.0f,0.0f);

    /**
     * Cresta
    */
    //Frente
    glVertex3f(-0.25f, 1.9f, 1.75f); //v1
    glVertex3f(0.25f, 1.9f, 1.75f); //v2
    glVertex3f(0.35f, 1.7f, 1.75f); //v3
    glVertex3f(-0.25f, 1.7f, 1.75f); //v4

    //Atras
    glVertex3f(0.25f, 1.9f, 1.55f); //v6
    glVertex3f(-0.25f, 1.9f, 1.55f); //v5
    glVertex3f(-0.25f, 1.7f, 1.55f); //v8
    glVertex3f(0.25f, 1.7f, 1.55f); //v7

    //Izquierda
    glVertex3f(-0.25f, 1.9f, 1.55f); //v5
    glVertex3f(-0.25f, 1.9f, 1.75f); //v1
    glVertex3f(-0.25f, 1.7f, 1.75f); //v4
    glVertex3f(-0.25f, 1.7f, 1.55f); //v8

    //Derecha
    glVertex3f(0.25f, 1.9f, 1.75f); //v2
    glVertex3f(0.25f, 1.9f, 1.55f); //v6
    glVertex3f(0.25f, 1.7f, 1.55f); //v7
    glVertex3f(0.35f, 1.7f, 1.75f); //v3

    //Debajo
    glVertex3f(-0.25f, 1.7f, 1.75f); //v4
    glVertex3f(0.35f, 1.7f, 1.75f); //v3
    glVertex3f(0.25f, 1.7f, 1.55f); //v7
    glVertex3f(-0.25f, 1.7f, 1.55f); //v8

    //Arriba
    glVertex3f(-0.25f, 1.9f, 1.55f); //v5
    glVertex3f(0.25f, 1.9f, 1.55f); //v6
    glVertex3f(0.25f, 1.9f, 1.75f); //v2
    glVertex3f(-0.25f, 1.9f, 1.75f); //v1

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
  glLoadIdentity();
  glTranslatef(xTranslate, yTranslate, zTranslate);
  glScalef(xScale, yScale, zScale);
  glRotatef(angle, xAxis, yAxis, zAxis);

  drawBox(1.0f, 1.0f, 1.0f);

  glFlush();  
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

    
    
    glRotatef(angle, 0.0, 1.0, 0.0);

    glFlush();
	glutSwapBuffers();

}

/**
 * !Function for the keyboard
 * ?A switch statement to listen to the keypresses, it updates their corresponding value
*/

void keyboard(unsigned char key) {
    switch (key)
    {
    case 27:
        exit(1);
        break;
    case 'w':
    case 'W':
        yTranslate += 0.05f;
        break;
    
    case 's':
    case 'S':
        yTranslate -= 0.05f;
        break;
    
    case 'd':
    case 'D':
        xTranslate += 0.05f;
        break;
    
    case 'a':
    case 'A': 
        xTranslate -= 0.05f;
        break;
    
    case 'q':
    case 'Q':
        angle -= 8;
        break;
    case 'e':
    case 'E':
        angle += 8;
        break;

	case 'Z':
	case 'z':
		xScale += 0.05f;
        yScale += 0.05f;
        zScale += 0.05f;
		break;
	case 'X':
	case 'x':
        xScale -= 0.05f;
        yScale -= 0.05f;
        zScale -= 0.05f;
		break;

    default:
        break;
    }

    glutPostRedisplay();
}

/**
 * !Function
 * ?Displays the instructions to scale, rotate and translate the model
*/

void instructions()
{
    printf("q -----------> Rotate counter clockwise\n");
    printf("e -----------> Rotate clockwise\n");
    printf("W or w ------> Up\n");
    printf("S or s -----> Down\n");
    printf("D or d ------> Right\n");
    printf("A or a ------> Left\n");
    printf("Z or z ------> Scale Up\n");
    printf("X or x ------> Scale Down\n");
    printf("Escape Key ---> Exit \n");
}

int main(int argc, char **argv) {
    instructions();
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Minecraft Chicken");

    /**
     * !glutDisplayFunc, funciona como un call back a la funcion que se encuentra en el parametro
    */
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    
    init();




    /**
     * !glutMainLoop, hace que entre en el loop de GLUT para el procesamiento de eventos
    */
    glutMainLoop();

    return 0;
}