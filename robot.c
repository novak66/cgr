// gcc robot.c -lglut -lGL -lGLU -lm -o robot && ./robot
#include <GL/glut.h>

// anglex of rotation for the camera direction
float anglex = 0.0f;
float angley = 0.0f;
// actual vector representing the camera's direction
float deltaAnglex = 0.0f;
float deltaAngley = 0.0f;

void changeSize(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    if (h == 0)
        h = 1;
    float ratio = w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void drawRobo()
{
    GLUquadricObj *pObj;

    pObj = gluNewQuadric();
    gluQuadricDrawStyle(pObj, GLU_FILL);
    gluQuadricNormals(pObj, GLU_SMOOTH);

    // corpo
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(0.0f, 13.f, 0.f);
    glScalef(5.0f, 8.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // bola pescoço
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 17.25f, 0.f);
    gluSphere(pObj, .3f, 40, 30);
    glPopMatrix();

    // cabeça
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(0.0f, 19.f, 0.f);
    glScalef(3.0f, 3.f, 2.0f);
    gluSphere(pObj, 0.55f, 26, 13);
    glPopMatrix();

    // olho direito
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.7f, 19.5f, 1.1f);
    glScalef(.75f, .5f, .0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // olho esquerdo
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-0.7f, 19.5f, 1.1f);
    glScalef(.75f, .5f, .0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // boca
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.f, 18.5f, 1.1f);
    glScalef(1.5f, .3f, .0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // primeira bola braço direito
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(3.f, 16.5f, 0.f);
    gluSphere(pObj, .5f, 40, 30);
    glPopMatrix();

    // primeira bola braço esquerdo
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-3.f, 16.5f, 0.f);
    gluSphere(pObj, .5f, 40, 30);
    glPopMatrix();

    // antebraço direito
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(5.f, 16.5f, 0.f);
    glScalef(3.0f, 1.0f, 1.f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // antebraço esquerdo
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(-5.f, 16.5f, 0.f);
    glScalef(3.0f, 1.0f, 1.f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // segunda bola braço direito
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(6.8f, 16.5f, 0.f);
    gluSphere(pObj, .35f, 40, 30);
    glPopMatrix();

    // segunda bola braço esquerdo
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-6.8f, 16.5f, 0.f);
    gluSphere(pObj, .35f, 40, 30);
    glPopMatrix();

    // braço direito
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(8.5f, 16.5f, 0.f);
    glScalef(3.f, .75f, 0.75f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // braço esquerdo
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(-8.5f, 16.5f, 0.f);
    glScalef(3.f, .75f, 0.75f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // mão direita
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(10.1f, 16.5f, 0.f);
    glScalef(.5f, 0.5f, 0.25f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // mão esquerda
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-10.1f, 16.5f, 0.f);
    glScalef(.5f, 0.5f, 0.25f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // primeira bola perna direita
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(1.8f, 8.7f, 0.f);
    gluSphere(pObj, .5f, 40, 30);
    glPopMatrix();

    // primeira bola perna esquerda
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.8f, 8.7f, 0.f);
    gluSphere(pObj, .5f, 40, 30);
    glPopMatrix();

    // coxa direita
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(1.8f, 6.6f, 0.f);
    glScalef(1.5f, 3.5f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // coxa esquerda
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(-1.8f, 6.6f, 0.f);
    glScalef(1.5f, 3.5f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // joelho esquerdo
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.8f, 4.6f, 0.f);
    gluSphere(pObj, .35f, 40, 30);
    glPopMatrix();

    // joelho direito
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(1.8f, 4.6f, 0.f);
    gluSphere(pObj, .35f, 40, 30);
    glPopMatrix();

    // perna direita
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(1.8f, 2.5f, 0.f);
    glScalef(1.35f, 3.5f, 1.35f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // perna esquerda
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(-1.8f, 2.5f, 0.f);
    glScalef(1.35f, 3.5f, 1.35f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // pé direito
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(1.8f, 0.f, .5f);
    glScalef(1.5f, 1.5f, 3.f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // pé esquerdo
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.8f, 0.f, .5f);
    glScalef(1.5f, 1.5f, 3.f);
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
    gluLookAt(0.0f, 25.f, 45.0f,
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
    drawRobo();
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

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1200, 768);
    glutCreateWindow("Lucas novak - robot");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutSpecialFunc(pressKey);
    glutIgnoreKeyRepeat(1);
    glutSpecialUpFunc(releaseKey);

    // OpenGL init
    glEnable(GL_DEPTH_TEST);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
