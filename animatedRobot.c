#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// anglex of rotation for the camera direction
float anglex = 0.0f;
float angley = 0.0f;
// actual vector representing the camera's direction
// when no key is being presses
float deltaAnglex = 0.0f;
float deltaAngley = 0.0f;

float rotationHeadX = 0.0f;
float rotationHeadY = 0.0f;

float rotationLeftLeg = 0.0f;
float rotationRightLeg = 0.0f;

float rotationElbow = 0.0f;
float rotationRightArm = 0.0f;
float rotationLeftArm = 0.0f;

int yes = 0;
int no = 0;
int animationYesInteraction = 0;
int animationNoInteraction = 0;

int walk = 0;
int animationWalkInteration = 0;

int animationWalkHandInteration = 0;

int stop = 0;

void animationStop()
{
    if (rotationElbow == .0f && rotationRightArm == .0f && rotationRightLeg == .0f)
    {
        stop = 0;
    }

    if (rotationElbow > 0.f)
    {
        rotationElbow -= 1.5f;
    }
    if (rotationRightArm > 0)
    {
        rotationRightArm -= 1.f;
        rotationLeftArm += 1.f;
    }
    if (rotationRightArm < 0)
    {
        rotationRightArm += 1.f;
        rotationLeftArm -= 1.f;
    }
    if (rotationRightLeg > 0)
    {
        rotationRightLeg -= 1.f;
        rotationLeftLeg += 1.f;
    }
    if (rotationRightLeg < 0)
    {
        rotationRightLeg += 1.f;
        rotationLeftLeg -= 1.f;
    }
}

void animationWalk()
{
    if (rotationRightLeg <= 20 && animationWalkInteration == 0)
    {
        rotationRightLeg += 1.f;
        rotationLeftLeg -= 1.f;
    }
    else
    {
        animationWalkInteration = 1;
        if (rotationRightLeg >= -20 && animationWalkInteration == 1)
        {
            rotationRightLeg -= 1.f;
            rotationLeftLeg += 1.f;
        }
        else
        {
            animationWalkInteration = 0;
        }
    }
}

void animationWalkHand()
{
    if (rotationElbow <= 30)
    {
        rotationElbow += 1.5f;
    }
    if (rotationLeftArm <= 20 && animationWalkHandInteration == 0)
    {
        rotationLeftArm += 1.f;
        rotationRightArm -= 1.f;
    }
    else
    {
        animationWalkHandInteration = 1;
        if (rotationLeftArm >= -20)
        {
            rotationLeftArm -= 1.f;
            rotationRightArm += 1.f;
        }
        else
        {
            animationWalkHandInteration = 0;
        }
    }
}

void animationYes()
{
    if ((rotationHeadY <= 30.0f) && animationYesInteraction == 0)
    {
        rotationHeadY += 1.f;
    }
    else
    {
        animationYesInteraction = 1;
        if (rotationHeadY >= 0.0 && animationYesInteraction == 1)
        {
            rotationHeadY -= 1.f;
        }
        else
        {
            yes = 0;
            animationYesInteraction = 0;
        }
    }
}

void animationNo()
{
    if (rotationHeadX <= 30.0f && animationNoInteraction == 0)
    {
        rotationHeadX += 1.f;
    }
    else
    {
        animationNoInteraction = (animationNoInteraction == 2) ? 2 : 1;
        if (rotationHeadX >= -30.0 && animationNoInteraction == 1)
        {
            rotationHeadX -= 1.f;
        }
        else
        {
            animationNoInteraction = 2;
            if (rotationHeadX != 0.0)
            {
                rotationHeadX += 1.f;
            }
            else
            {
                no = 0;
                animationNoInteraction = 0;
            }
        }
    }
}

void changeSize(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
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

    // Pelvis
    glPushMatrix();
    // corpo
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(0.0f, 13.f, 0.f);
    glScalef(5.0f, 8.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Spine
    glPushMatrix();
    // Spine Chest
    glPushMatrix();
    // Neck
    glPushMatrix();
    // bola pescoço
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 17.25f, 0.f);
    gluSphere(pObj, .5f, 40, 30);
    // cabeça
    glRotatef(rotationHeadX, 0, 1, 0);
    glRotatef(rotationHeadY, 1, 0, 0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(0.0f, 2.f, 0.f);
    glScalef(3.0f, 3.f, 2.0f);
    glutSolidCube(1.0f);
    glScalef(1 / 3.0f, 1 / 3.f, 1 / 2.0f);

    // olho direito
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.7f, .25f, 1.1f);
    glScalef(.75f, .5f, .0f);
    glutSolidCube(1.0f);
    glScalef(1 / .75f, 1 / .5f, .0f);

    // olho esquerdo
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.4f, .0f, .0f);
    glScalef(.75f, .5f, .0f);
    glutSolidCube(1.0f);
    glScalef(1 / .75f, 1 / .5f, .0f);

    // boca
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(.7f, -1.f, .0f);
    glScalef(1.5f, .3f, .0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Right arm
    glPushMatrix();
    // primeira bola braço direito
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(3.3f, 16.5f, .0f);
    gluSphere(pObj, .8f, 40, 30);

    // antebraço direito
    glColor3f(0.6f, 0.6f, 0.6f);
    glRotatef(rotationRightArm, 1, 0, 0);
    glTranslatef(0.0f, -2.f, 0.0f);
    glScalef(1.0f, 3.f, 1.0f);
    glutSolidCube(1.0f);
    glScalef(1 / 1.0f, 1 / 3.f, 1 / 1.0f);

    // segunda bola braço direito
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.f, -1.675f, 0.f);
    gluSphere(pObj, .35f, 40, 30);

    // braço direito
    glRotatef(rotationElbow, -1, 0, 0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(0.f, -1.675f, 0.f);
    glScalef(.75f, 3.f, .75f);
    glutSolidCube(1.0f);
    glScalef(1 / .75f, 1 / 3.f, 1 / .75f);

    // mão direita
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.f, -1.625f, 0.f);
    glScalef(.5f, 0.25f, 0.5f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Left arm
    glPushMatrix();
    // primeira bola braço esquerdo
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-3.3f, 16.5f, .0f);
    gluSphere(pObj, .8f, 40, 30);

    // antebraço esquerdo
    glColor3f(0.6f, 0.6f, 0.6f);
    glRotatef(rotationLeftArm, 1, 0, 0);
    glTranslatef(0.0f, -2.f, 0.0f);
    glScalef(1.0f, 3.f, 1.0f);
    glutSolidCube(1.0f);
    glScalef(1 / 1.0f, 1 / 3.f, 1 / 1.0f);

    // segunda bola braço esquerdo
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.f, -1.675f, 0.f);
    gluSphere(pObj, .35f, 40, 30);

    // braço esquerdo
    glRotatef(rotationElbow, -1, 0, 0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(0.f, -1.675f, 0.f);
    glScalef(.75f, 3.f, .75f);
    glutSolidCube(1.0f);
    glScalef(1 / .75f, 1 / 3.f, 1 / .75f);

    // mão esquerda
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.f, -1.625f, 0.f);
    glScalef(.5f, 0.25f, 0.5f);
    glutSolidCube(1.0f);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // Perna Direita
    glPushMatrix();
    // primeira bola perna direita
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(1.8f, 8.7f, 0.f);
    gluSphere(pObj, .35f, 40, 30);

    // coxa direita
    glRotatef(rotationRightLeg, 1, 0, 0);
    glTranslatef(0, -2.1f, 0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glScalef(1.5f, 3.5f, 2.0f);
    glutSolidCube(1.0f);
    glScalef(1 / 1.5f, 1 / 3.5f, 1 / 2.0f);

    // joelho direito
    glRotatef(10, 1, 0, 0);
    glTranslatef(0, -1.925f, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluSphere(pObj, .35f, 40, 30);

    // perna direita
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(0, -1.925f, 0);
    glScalef(1.35f, 3.5f, 1.35f);
    glutSolidCube(1.0f);
    glScalef(1 / 1.35f, 1 / 3.5f, 1 / 1.35f);

    // pe direito
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0, -2.125f, .5f);
    glScalef(1.5f, .75f, 3.f);
    glutSolidCube(1.0f);
    glScalef(1 / 1.5f, 1 / .75f, 1 / 3.f);
    glPopMatrix();

    // perna esquerda
    glPushMatrix();
    // primeira bola perna esquerda
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.8f, 8.7f, 0.f);
    gluSphere(pObj, .35f, 40, 30);

    // coxa esquerda
    glRotatef(rotationLeftLeg, 1, 0, 0);
    glTranslatef(0, -2.1f, 0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glScalef(1.5f, 3.5f, 2.0f);
    glutSolidCube(1.0f);
    glScalef(1 / 1.5f, 1 / 3.5f, 1 / 2.0f);

    // joelho esquerdo
    glRotatef(10, 1, 0, 0);
    glTranslatef(0, -1.925f, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluSphere(pObj, .35f, 40, 30);

    // perna esquerda
    glColor3f(0.6f, 0.6f, 0.6f);
    glTranslatef(0, -1.925f, 0);
    glScalef(1.35f, 3.5f, 1.35f);
    glutSolidCube(1.0f);
    glScalef(1 / 1.35f, 1 / 3.5f, 1 / 1.35f);

    // pe esquerdo
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0, -2.125f, .5f);
    glScalef(1.5f, .75f, 3.f);
    glutSolidCube(1.0f);
    glScalef(1 / 1.5f, 1 / .75f, 1 / 3.f);
    glPopMatrix();

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

    if (yes)
    {
        animationYes();
    }
    else
    {
        rotationHeadY = 0;
    }
    if (no)
    {
        animationNo();
    }
    else
    {
        rotationHeadX = 0;
    }
    if (walk)
    {
        animationWalk();
        animationWalkHand();
    }
    if (stop)
    {
        animationStop();
    }

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

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'y':
    case 'Y':
        yes = 1;
        no = 0;
        break;
    case 'n':
    case 'N':
        no = 1;
        yes = 0;
        break;
    case 'w':
    case 'W':
        walk = 1;
        stop = 0;
        break;
    case 's':
    case 'S':
        walk = 0;
        stop = 1;
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

void idle()
{
    glutPostRedisplay();
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
    glutIdleFunc(idle);
    glutSpecialFunc(pressKey);
    glutIgnoreKeyRepeat(1);
    glutSpecialUpFunc(releaseKey);
    glutKeyboardFunc(keyboard);

    // OpenGL init
    glEnable(GL_DEPTH_TEST);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
