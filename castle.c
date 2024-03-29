
// gcc castle.c -lglut -lGL -lGLU -lm -o castle && ./castle

#include <GL/glut.h>

// Rotation
static GLfloat yRot = 0.0f;
static GLfloat zRot = 0.0f;
static GLfloat xRot = 290;

// Change viewing volume and viewport.  Called when window is resized
void ChangeSize(int w, int h)
    {
    GLfloat fAspect;

    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Produce the perspective projection
    gluPerspective(35.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    }


// This function does any needed initialization on the rendering context.  Here it sets up and initializes the lighting for the scene.
void SetupRC(){

    // Light values and coordinates
    GLfloat  whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat  lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);    // Hidden surface removal
    glFrontFace(GL_CCW);        // Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);     // Do not calculate inside

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Black blue background
    glClearColor(0.25f, 0.25f, 0.50f, 1.0f);

}

// Respond to arrow keys (rotate snowman)
void SpecialKeys(int key, int x, int y){

    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;

    if(key == GLUT_KEY_UP)
        zRot -= 5;

    if(key == GLUT_KEY_DOWN)
        zRot += 5;

    yRot = (GLfloat)((const int)yRot % 360);
    xRot = (GLfloat)((const int)xRot % 360);
    zRot = (GLfloat)((const int)zRot);
    // Refresh the Window
    glutPostRedisplay();
}

// Called to draw scene
void RenderScene(void){

    GLUquadricObj *pObj;    // Quadric Object

    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Save the matrix state and do the rotations
    glPushMatrix();

	// Move object back and do in place rotation
	glTranslatef(0.0f, -1.0f, zRot);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);


	// Draw something
	pObj = gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);

	// grey
	glColor3f(0.6f, 0.6f, 0.6f);

	// Main tower Left Back
	gluCylinder(pObj, 0.8f, 0.8f, 3.0f, 26, 13);

        //

        //roof
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 3.0f);
        glutSolidCone(1.0f, 1.0f , 26, 13);
        glPopMatrix();

        //back wall
        glPushMatrix();
        glTranslatef(2.5f, 0.0f, 0.5f);
        glScalef(4.0, 1.0f, 1.0f);
        glutSolidCube(1.0f);
        glPopMatrix();

        //tower Right Back
        glPushMatrix();
        glTranslatef(5.0f, 0.0f, 0.0f);
        gluCylinder(pObj, 0.8f, 0.8f, 2.0f, 26, 13);

            //roof
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 2.0f);
            glutSolidCone(1.0f, 1.0f , 26, 13);
            glPopMatrix();

            // right wall
            glPushMatrix();
            glTranslatef(0.0f, -2.5f, 0.5f);
            glScalef(1.0, 4.0f, 1.0f);
            glutSolidCube(1.0f);
            glPopMatrix();

            //tower Right Front
            glPushMatrix();
            glTranslatef(0.0f, -5.0f, 0.0f);
            gluCylinder(pObj, 0.8f, 0.8f, 2.0f, 26, 13);

                //roof
                glPushMatrix();
                glTranslatef(0.0f, 0.0f, 2.0f);
                glutSolidCone(1.0f, 1.0f , 26, 13);
                glPopMatrix();

                // front wall right
                glPushMatrix();
                glTranslatef(-1.0f, 0.0f, 0.5f);
                glScalef(1.5, 1.0f, 1.0f);
                glutSolidCube(1.0f);
                glPopMatrix();


            glPopMatrix();

        glPopMatrix();

        //tower left front
        glPushMatrix();
        glTranslatef(0.0f, -5.0f, 0.0f);
        gluCylinder(pObj, 0.8f, 0.8f, 2.0f, 26, 13);

            //roof
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 2.0f);
            glutSolidCone(1.0f, 1.0f , 26, 13);
            glPopMatrix();

            // left wall
            glPushMatrix();
            glTranslatef(0.0f, 2.5f, 0.5f);
            glScalef(1.0, 4.0f, 1.0f);
            glutSolidCube(1.0f);
            glPopMatrix();

            // front wall
            glPushMatrix();
            glTranslatef(1.0f, 0.0f, 0.5f);
            glScalef(1.5, 1.0f, 1.0f);
            glutSolidCube(1.0f);

            // gate
            glPushMatrix();
            glTranslatef(1.0f, 0.0f, 0.0f);
            glScalef(0.5, 1.0f, 1.0f);
            glutSolidCube(1.0f);

                glPushMatrix();
                glTranslatef(0.75f, 0.0f, 0.25f);
                glScalef(0.5, 1.0f, 0.5f);
                glutSolidCube(1.0f);
                glPopMatrix();

                glPushMatrix();
                glTranslatef(-0.75f, 0.0f, 0.25f);
                glScalef(0.5, 1.0f, 0.5f);
                glutSolidCube(1.0f);
                glPopMatrix();
            glPopMatrix();

            glPopMatrix();

        glPopMatrix();



    // Restore the matrix state
    glPopMatrix();

    // Buffer swap
    glutSwapBuffers();

}

int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lucas novak - castle");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();

    return 0;
}

