#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <stdio.h>

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define feathersImageWidth 64
#define feathersImageHeight 64
static GLubyte feathersImage[feathersImageHeight][feathersImageWidth][4];
int width, height, colours;

#define headImageWidth 32
#define headImageHeight 32
static GLubyte headImage[headImageHeight][headImageWidth][4];


// Parameters for scaling
float xScale = 0.2f;
float yScale = 0.2f;
float zScale = 0.2f;


// Parameters for translating
float xTranslate = 0.0f;
float yTranslate = 0.0f;
float zTranslate = 0.0f;

// Parameters for rotating
double xAxis = 0.0;
double yAxis = 1.0;
double zAxis = 0.0;

int angle = 90;

/*
 * Function to apply texture to the body
 */
void makeChickenFeathers(void)
{
    int i, j, c;
    char keyword[2];
    string comment;

    // Reading texture file
    ifstream inFile;

    inFile.open("C://Users//dav_r//Documents//Sem 9//Graficas//Challenge1//feathers.ppm"); // Change to own directory
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1); // Terminate with error
    }

    // Read the file headers
    inFile >> keyword;
    inFile >> comment;
    inFile >> comment;
    inFile >> comment;
    inFile >> comment;
    inFile >> comment;
    inFile >> width;
    inFile >> height;
    inFile >> colours;

    //Read the image
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            inFile >> c;
            feathersImage[height - i][j][0] = (GLubyte)c;
            inFile >> c;
            feathersImage[height - i][j][1] = (GLubyte)c;
            inFile >> c;
            feathersImage[height - i][j][2] = (GLubyte)c;
            feathersImage[height - i][j][3] = (GLubyte)255;
        }
    }
    inFile.close();
}

/*
 * Function to apply texture to the head
 */
void makeChickenHead(void)
{
    int i, j, c;
    char keyword[2];
    string comment;

    //Reading texture file
    ifstream inFile;

    inFile.open("C://Users//dav_r//Documents//Sem 9//Graficas//Challenge1//head.ppm"); // Change to own directory
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1); // Terminate with error
    }

    // Read the file headers
    inFile >> keyword;
    inFile >> width;
    inFile >> height;
    inFile >> colours;

    // Read the image
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            inFile >> c;
            headImage[height - i][j][0] = (GLubyte)c;
            inFile >> c;
            headImage[height - i][j][1] = (GLubyte)c;
            inFile >> c;
            headImage[height - i][j][2] = (GLubyte)c;
            headImage[height - i][j][3] = (GLubyte)255;
        }
    }
    inFile.close();
}

/*
 * Function to apply texture to the head
 * * glBegin() limits the vertices of a primitive
 * * glColor3f() defines the current color (for non-texturized parts)
 * * glTexImage2D() applies the texture
 */
void drawBox(GLfloat x, GLfloat y, GLfloat z)
{

    glBegin(GL_QUADS);

    // White body parts
    glColor3f(1.0f, 1.0f, 1.0f);

    // Head texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, headImageWidth,
                 headImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 headImage);

    /* ---- Head rendering ---- */

    //Front
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5f, 2.5f, 1.5f); //v1
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.5f, 2.5f, 1.5f); //v2
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5f, 1.5f, 1.5f); //v3
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.5f, 1.5f, 1.5f); //v4

    // Feather texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, feathersImageWidth,
                 feathersImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 feathersImage);

    //Back
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.5f, 2.5f, 0.5f); //v6
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.5f, 2.5f, 0.5f); //v5
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-0.5f, 1.5f, 0.5f); //v8
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.5f, 1.5f, 0.5f); //v7

    //Left
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5f, 2.5f, 0.5f); //v5
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.5f, 2.5f, 1.5f); //v1
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-0.5f, 1.5f, 1.5f); //v4
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.5f, 1.5f, 0.5f); //v8

    //Right
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.5f, 2.5f, 1.5f); //v2
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.5f, 2.5f, 0.5f); //v6
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5f, 1.5f, 0.5f); //v7
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.5f, 1.5f, 1.5f); //v3

    //Bottom
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5f, 1.5f, 1.5f); //v4
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.5f, 1.5f, 1.5f); //v3
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5f, 1.5f, 0.5f); //v7
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.5f, 1.5f, 0.5f); //v8

    //Top
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5f, 2.5f, 0.5f); //v5
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.5f, 2.5f, 0.5f); //v6
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5f, 2.5f, 1.5f); //v2
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.5f, 2.5f, 1.5f); //v1

    /* ---- Body rendering ---- */

    //Front
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.0f, 1.5f, 1.0f); //v1
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1.0f, 1.5f, 1.0f); //v2
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.0f, -0.5f, 1.0f); //v3
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.0f, -0.5f, 1.0f); //v4

    //Back
    glTexCoord2f(0.0, 0.0);
    glVertex3f(1.0f, 1.5f, -1.0f); //v6
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1.0f, 1.5f, -1.0f); //v5
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-1.0f, -0.5f, -1.0f); //v8
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1.0f, -0.5f, -1.0f); //v7

    //Left
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.0f, 1.5f, -1.0f); //v5
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1.0f, 1.5f, 1.0f); //v1
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-1.0f, -0.5f, 1.0f); //v4
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.0f, -0.5f, -1.0f); //v8

    //Right
    glTexCoord2f(0.0, 0.0);
    glVertex3f(1.0f, 1.5f, 1.0f); //v2
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1.0f, 1.5f, -1.0f); //v6
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.0f, -0.5f, -1.0f); //v7
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1.0f, -0.5f, 1.0f); //v3

    //Bottom
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.0f, -0.5f, 1.0f); //v4
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1.0f, -0.5f, 1.0f); //v3
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.0f, -0.5f, -1.0f); //v7
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.0f, -0.5f, -1.0f); //v8

    //Top
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.0f, 1.5f, -1.0f); //v5
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1.0f, 1.5f, -1.0f); //v6
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.0f, 1.5f, 1.0f); //v2
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.0f, 1.5f, 1.0f); //v1

    /* ---- Right Wing rendering ---- */

    //Front
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.2f, 1.5f, 0.75f); //v1
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.8f, 1.5f, 0.75f); //v2
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-0.8f, 0.0f, 0.75f); //v3
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.2f, 0.0f, 0.75f); //v4

    //Back
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.8f, 1.5f, -0.75f); //v6
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1.2f, 1.5f, -0.75f); //v5
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-1.2f, 0.0f, -0.75f); //v8
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.8f, 0.0f, -0.75f); //v7

    //Left
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.2f, 1.5f, -0.75f); //v5
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1.2f, 1.5f, 0.75f); //v1
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-1.2f, 0.0f, 0.75f); //v4
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.2f, 0.0f, -0.75f); //v8

    //Right
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.8f, 1.5f, 0.75f); //v2
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.8f, 1.5f, -0.75f); //v6
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-0.8f, 0.0f, -0.75f); //v7
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.8f, 0.0f, 0.75f); //v3

    //Bottom
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.2f, 0.0f, 0.75f); //v4
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.8f, 0.0f, 0.75f); //v3
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-0.8f, 0.0f, -0.75f); //v7
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.2f, 0.0f, -0.75f); //v8

    //Top
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.2f, 1.5f, -0.75f); //v5
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.8f, 1.5f, -0.75f); //v6
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-0.8f, 1.5f, 0.75f); //v2
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.2f, 1.5f, 0.75f); //v1

    /* ---- Left Wing rendering ---- */

    //Front
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.8f, 1.5f, 0.75f); //v1
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1.2f, 1.5f, 0.75f); //v2
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.2f, 0.0f, 0.75f); //v3
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.8f, 0.0f, 0.75f); //v4

    //Back
    glTexCoord2f(0.0, 0.0);
    glVertex3f(1.2f, 1.5f, -0.75f); //v6
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.8f, 1.5f, -0.75f); //v5
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.2f, 0.0f, -0.75f); //v7
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.8f, 0.0f, -0.75f); //v8

    //Left
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.8f, 1.5f, -0.75f); //v5
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.8f, 1.5f, 0.75f); //v1
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.8f, 0.0f, 0.75f); //v4
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.8f, 0.0f, -0.75f); //v8

    //Right
    glTexCoord2f(0.0, 0.0);
    glVertex3f(1.2f, 1.5f, 0.75f); //v2
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1.2f, 1.5f, -0.75f); //v6
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.2f, 0.0f, -0.75f); //v7
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1.2f, 0.0f, 0.75f); //v3

    //Bottom
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.8f, 0.0f, 0.75f); //v4
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1.2f, 0.0f, 0.75f); //v3
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.2f, 0.0f, -0.75f); //v7
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.8f, 0.0f, -0.75f); //v8

    //Top
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.8f, 1.5f, -0.75f); //v5
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1.2f, 1.5f, -0.75f); //v6
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.2f, 1.5f, 0.75f); //v2
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.8f, 1.5f, 0.75f); //v1

    // Yellow  body parts
    glColor3f(1.0f, 1.0f, 0.0f);

    /* ---- Beak rendering ---- */

    //Front
    glVertex3f(-0.5f, 2.0f, 1.8f); //v1
    glVertex3f(0.5f, 2.0f, 1.8f);  //v2
    glVertex3f(0.5f, 1.8f, 1.8f);  //v3
    glVertex3f(-0.5f, 1.8f, 1.8f); //v4

    //Back
    glVertex3f(0.5f, 2.0f, 1.5f);  //v6
    glVertex3f(-0.5f, 2.0f, 1.5f); //v5
    glVertex3f(-0.5f, 1.8f, 1.5f); //v8
    glVertex3f(0.5f, 1.8f, 1.5f);  //v7

    //Left
    glVertex3f(-0.5f, 2.0f, 1.5f); //v5
    glVertex3f(-0.5f, 2.0f, 1.8f); //v1
    glVertex3f(-0.5f, 1.8f, 1.8f); //v4
    glVertex3f(-0.5f, 1.8f, 1.5f); //v8

    //Right
    glVertex3f(0.5f, 2.0f, 1.8f);  //v2
    glVertex3f(0.5f, 2.0f, 1.5f);  //v6
    glVertex3f(0.5f, 1.8f, 1.5f);  //v7
    glVertex3f(-0.5f, 1.8f, 1.5f); //v8

    //Bottom
    glVertex3f(-0.5f, 1.8f, 1.8f); //v4
    glVertex3f(0.5f, 1.8f, 1.8f);  //v3
    glVertex3f(0.5f, 1.8f, 1.5f);  //v7
    glVertex3f(-0.5f, 1.8f, 1.5f); //v8

    //Top
    glVertex3f(-0.5f, 2.0f, 1.5f); //v5
    glVertex3f(0.5f, 2.0f, 1.5f);  //v6
    glVertex3f(0.5f, 2.0f, 1.8f);  //v2
    glVertex3f(-0.5f, 2.0f, 1.8f); //v1

    /* ---- Right Leg rendering ---- */

    //Front
    glVertex3f(-0.7, -0.5f, 0.2f); //v1
    glVertex3f(-0.3, -0.5f, 0.2f); //v2
    glVertex3f(-0.3, -2.0f, 0.2f); //v3
    glVertex3f(-0.7, -2.0f, 0.2f); //v4

    //Back
    glVertex3f(-0.3, -0.5f, -0.2f); //v6
    glVertex3f(-0.7, -0.5f, -0.2f); //v5
    glVertex3f(-0.7, -2.0f, -0.2f); //v8
    glVertex3f(-0.3, -2.0f, -0.2f); //v7

    //Left
    glVertex3f(-0.7, -0.5f, -0.2f); //v5
    glVertex3f(-0.7, -0.5f, 0.2f);  //v1
    glVertex3f(-0.7, -2.0f, 0.2f);  //v4
    glVertex3f(-0.7, -2.0f, -0.2f); //v8

    //Right
    glVertex3f(-0.3, -0.5f, 0.2f);  //v2
    glVertex3f(-0.3, -0.5f, -0.2f); //v6
    glVertex3f(-0.3, -2.0f, -0.2f); //v7
    glVertex3f(-0.3, -2.0f, 0.2f);  //v3

    //Bottom
    glVertex3f(-0.7, -2.0f, 0.2f);  //v4
    glVertex3f(-0.3, -2.0f, 0.2f);  //v3
    glVertex3f(-0.3, -2.0f, -0.2f); //v7
    glVertex3f(-0.7, -2.0f, -0.2f); //v8

    //Top
    glVertex3f(-0.7, -0.5f, -0.2f); //v5
    glVertex3f(-0.3, -0.5f, -0.2f); //v6
    glVertex3f(-0.3, -0.5f, 0.2f);  //v2
    glVertex3f(-0.7, -0.5f, 0.2f);  //v1

    /* ---- Left Leg rendering ---- */

    //Front
    glVertex3f(0.3f, -0.5f, 0.2f); //v1
    glVertex3f(0.7f, -0.5f, 0.2f); //v2
    glVertex3f(0.7f, -2.0f, 0.2f); //v3
    glVertex3f(0.3f, -2.0f, 0.2f); //v4

    //Back
    glVertex3f(0.7f, -0.5f, -0.2f); //v6
    glVertex3f(0.3f, -0.5f, -0.2f); //v5
    glVertex3f(0.3f, -2.0f, -0.2f); //v8
    glVertex3f(0.7f, -2.0f, -0.2f); //v7

    //Left
    glVertex3f(0.3f, -0.5f, -0.2f); //v5
    glVertex3f(0.3f, -0.5f, 0.2f);  //v1
    glVertex3f(0.3f, -2.0f, 0.2f);  //v4
    glVertex3f(0.3f, -2.0f, -0.2f); //v8

    //Right
    glVertex3f(0.7f, -0.5f, 0.2f);  //v2
    glVertex3f(0.7f, -0.5f, -0.2f); //v6
    glVertex3f(0.7f, -2.0f, -0.2f); //v7
    glVertex3f(0.7f, -2.0f, 0.2f);  //v3

    //Bottom
    glVertex3f(0.3f, -2.0f, 0.2f);  //v4
    glVertex3f(0.7f, -2.0f, 0.2f);  //v3
    glVertex3f(0.7f, -2.0f, -0.2f); //v7
    glVertex3f(0.3f, -2.0f, -0.2f); //v8

    //Top
    glVertex3f(0.3f, -0.5f, -0.2f); //v5
    glVertex3f(0.7f, -0.5f, -0.2f); //v6
    glVertex3f(0.7f, -0.5f, 0.2f);  //v2
    glVertex3f(0.3f, -0.5f, 0.2f);  //v1

    // Red parts
    glColor3f(1.0f, 0.0f, 0.0f);

    /* ---- Crest rendering ---- */

    //Front
    glVertex3f(-0.25f, 1.9f, 1.75f); //v1
    glVertex3f(0.25f, 1.9f, 1.75f);  //v2
    glVertex3f(0.35f, 1.7f, 1.75f);  //v3
    glVertex3f(-0.25f, 1.7f, 1.75f); //v4

    //Back
    glVertex3f(0.25f, 1.9f, 1.55f);  //v6
    glVertex3f(-0.25f, 1.9f, 1.55f); //v5
    glVertex3f(-0.25f, 1.7f, 1.55f); //v8
    glVertex3f(0.25f, 1.7f, 1.55f);  //v7

    //Left
    glVertex3f(-0.25f, 1.9f, 1.55f); //v5
    glVertex3f(-0.25f, 1.9f, 1.75f); //v1
    glVertex3f(-0.25f, 1.7f, 1.75f); //v4
    glVertex3f(-0.25f, 1.7f, 1.55f); //v8

    //Right
    glVertex3f(0.25f, 1.9f, 1.75f); //v2
    glVertex3f(0.25f, 1.9f, 1.55f); //v6
    glVertex3f(0.25f, 1.7f, 1.55f); //v7
    glVertex3f(0.35f, 1.7f, 1.75f); //v3

    //Bottom
    glVertex3f(-0.25f, 1.7f, 1.75f); //v4
    glVertex3f(0.35f, 1.7f, 1.75f);  //v3
    glVertex3f(0.25f, 1.7f, 1.55f);  //v7
    glVertex3f(-0.25f, 1.7f, 1.55f); //v8

    //Top
    glVertex3f(-0.25f, 1.9f, 1.55f); //v5
    glVertex3f(0.25f, 1.9f, 1.55f);  //v6
    glVertex3f(0.25f, 1.9f, 1.75f);  //v2
    glVertex3f(-0.25f, 1.9f, 1.75f); //v1

    // Ends the vertex delimitation
    glEnd();
}

/*
 * Prepares the display in the window
 * * drawbox() renders the vertices
 */
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(xTranslate, yTranslate, zTranslate);
    glScalef(xScale, yScale, zScale);
    glRotatef(angle, xAxis, yAxis, zAxis);

    glEnable(GL_TEXTURE_2D);

    drawBox(1.0f, 1.0f, 1.0f);

    glDisable(GL_TEXTURE_2D);

    glFlush();
    glutSwapBuffers();
}

/*
 * Function to intialize the tools for rendering the model
 * * glClearColor() specifies the color to clean
 * * glEnable() enables GL server capabilites
 * * glDepthFunc() specifies the value used for depth comparisons
 * * glClearDepth() specifies the clear value for depth
 */
void init(void)
{

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);

    makeChickenFeathers();
    makeChickenHead();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, feathersImageWidth,
                 feathersImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 feathersImage);

    glDepthFunc(GL_LEQUAL);
    glClearDepth(1.0f);

    // Correct initial positioning
    glRotatef(angle, 0.0, 1.0, 0.0);

    glFlush();
    glutSwapBuffers();
}

/*
 * Function to enable keyboard commands
 */

void keyboard(unsigned char key, int x, int y)
{
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

    // Refreshes the image
    glutPostRedisplay();
}

/*
 * Function which displays the instructions to scale, rotate and translate the model
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

/*
 * Main function
 * * glutDisplayFunc() works as a callback function to its parameter function
 * * glutMainLoop() makes GLUT run in a loop for event processing
 */
int main(int argc, char **argv)
{
    instructions();
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Minecraft Chicken");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
