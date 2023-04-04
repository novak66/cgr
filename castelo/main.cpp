#include <GL/glut.h>


float anglex = 0.0f;
float angley = 0.0f;

float deltaAnglex = 0.0f;
float deltaAngley = 0.0f;

void changeSize(int w, int h)
{

    if (h == 0)
        h = 1;
    float ratio = w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glScalef(0.5, 0.5, 0.5);

    glViewport(0, 0, w, h);


    gluPerspective(45.0f, ratio, 0.1f, 100.0f);


    glMatrixMode(GL_MODELVIEW);
}



void drawCastelo()
{
    GLUquadricObj *pObj;

    pObj = gluNewQuadric();
    gluQuadricDrawStyle(pObj, GLU_FILL);
    gluQuadricNormals(pObj, GLU_SMOOTH);



    //parede traseira
    glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.2f);
    glTranslatef(0.0f, 3.f, -15.f);
    glScalef(40.0f, 6.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //torre esquerda traseira
    glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.2f);
    glTranslatef(-20.0f, 3.f, -15.f);
    glScalef(5.0f, 15.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
    //chapeu
    glPushMatrix();
    glTranslatef(-20.0f, 10.0f, -15.0f);
    glRotatef(-100.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCone(3.0f, 2.0f , 16, 10);
    glPopMatrix();


    //torre direita traseira
    glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.2f);
    glTranslatef(20.0f, 3.f, -15.f);
    glScalef(5.0f, 15.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //chapeu
    glPushMatrix();
    glTranslatef(20.0f, 10.0f, -15.0f);
    glRotatef(-100.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCone(3.0f, 2.0f , 16, 10);
    glPopMatrix();

    //parede direita
    glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.2f);
    glTranslatef(20.0f, 3.f, 1.f);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    glScalef(40.0f, 6.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //torre direita frente
    glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.2f);
    glTranslatef(19.0f, 3.f, 20.f);
    glScalef(5.0f, 15.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

      //torre central
    glPushMatrix();
    glColor3f(0.3f, 0.2f, 0.2f);
    glTranslatef(0.0f, 5.f, 10.f);
    glScalef(5.0f, 15.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
    //chapeu
    glPushMatrix();
    glTranslatef(0.0f, 12.f, 10.f);
    glRotatef(-100.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCone(4.0f, 2.0f , 16, 10);
    glPopMatrix();


    //chapeu
    glPushMatrix();
    glTranslatef(19.0f, 10.f, 20.f);
    glRotatef(-100.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCone(3.0f, 2.0f , 16, 10);
    glPopMatrix();

    //transparente
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTranslatef(0.0f, 2.9f, 20.f);  // move para o centro do cone
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f); // 50% de transparência
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f); // rotaciona a porta em 45 graus em torno do eixo Y
    glScalef(1.5f, 1.3f, 0.7f); // ajusta a escala da porta para que fique mais alta do que larga
    glutSolidCube(5.0f); // desenha o cubo que representa a porta
    glPopMatrix();



    //parede frente
    glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.2f);
    glTranslatef(0.0f, 3.f, 20.f);
    glScalef(40.0f, 6.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();








    //torre esquerda frente
    glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.2f);
    glTranslatef(-20.0f, 3.f, 20.f);
    glScalef(5.0f, 15.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
    //chapeu
    glPushMatrix();
    glTranslatef(-20.0f, 10.0f, 20.0f);
    glRotatef(-100.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCone(3.0f, 2.0f , 16, 10);
    glPopMatrix();



    //parede esquerda
    glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.2f);
    glTranslatef(-20.0f, 3.f, 1.f);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    glScalef(40.0f, 6.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();






}

void renderScene(void)
{

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(.0, .0, .0, 1.0);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(0.0f, 10.f, 45.0f,
              0.0f, 10.0f, 4.0f,
              0.0f, 1.0f, 0.0f);

    glRotatef(anglex, 0.0f, 1.0f, 0.0f);
    glRotatef(angley, 1.0f, 0.0f, 0.0f);

    // Draw ground
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-25.0f, 0.0f, -25.0f);
    glVertex3f(-25.0f, 0.0f, 25.0f);
    glVertex3f(25.0f, 0.0f, 25.0f);
    glVertex3f(25.0f, 0.0f, -25.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    drawCastelo();
    glPopMatrix();
    anglex += deltaAnglex;
    angley += deltaAngley;

    glutSwapBuffers();
}

void pressKey(int key, int xx, int yy)
{

    switch (key)
    {
    case GLUT_KEY_LEFT:
        deltaAnglex = -0.5f;
        break;
    case GLUT_KEY_RIGHT:
        deltaAnglex = 0.5f;
        break;
    case GLUT_KEY_UP:
        deltaAngley = 0.5f;
        break;
    case GLUT_KEY_DOWN:
        deltaAngley = -0.5f;
        break;
    }
}

void releaseKey(int key, int x, int y)
{

    switch (key)
    {
    case GLUT_KEY_LEFT:
    case GLUT_KEY_RIGHT:
        deltaAnglex = 0.0f;
        break;
    case GLUT_KEY_UP:
    case GLUT_KEY_DOWN:
        deltaAngley = 0.0f;
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1200, 768);
    glutCreateWindow("castelo");

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutSpecialFunc(pressKey);
    glutIgnoreKeyRepeat(1);
    glutSpecialUpFunc(releaseKey);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 1;
}
