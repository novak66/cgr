
// gcc snowman.c -lglut -lGL -lGLU -lm -o snowman && ./snowman

#include <GL/glut.h>

// Rotation
static GLfloat yRot = 0.0f;
static GLfloat xRot = 0.0f;

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
        xRot += 5.0f;

    if(key == GLUT_KEY_DOWN)
        xRot -= 5.0f;

    yRot = (GLfloat)((const int)yRot % 360);
    xRot = (GLfloat)((const int)xRot % 360);

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
	glTranslatef(0.0f, -1.0f, -5.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);

	// Draw something
	pObj = gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);

	// white
	glColor3f(1.0f, 1.0f, 1.0f);

	// Main Body
	gluSphere(pObj, 0.48f, 26, 13);  // Bottom

	// Mid section
    glPushMatrix();
	glTranslatef(0.0f, 0.6f, 0.0f);
	gluSphere(pObj, 0.36f, 26, 13);
	glPopMatrix();

	// Head
	glPushMatrix(); // save transform matrix state
		glTranslatef(0.0f, 1.1f, 0.0f);
		gluSphere(pObj, 0.24f, 26, 13);
	glPopMatrix(); // restore transform matrix state

	// Nose (orange)
	glColor3f(1.0f, 0.4f, 0.51f);
	glPushMatrix();
		glTranslatef(0.0f, 1.1f, 0.2f);
		gluCylinder(pObj, 0.04f, 0.0f, 0.3f, 26, 13);
	glPopMatrix();

	// Eyes (black)
    //left eye
    glColor3f(0.0f, 0.0f, 0.0f); //Black
    glPushMatrix();
        glTranslatef(0.1f, 1.15f, 0.2f);
        gluSphere(pObj, 0.05f, 26, 13);
	glPopMatrix();

    //right eye
    glColor3f(0.0f, 0.0f, 0.0f); //Black
    glPushMatrix();
        glTranslatef(-0.1f, 1.15f, 0.2f);
        gluSphere(pObj, 0.05f, 26, 13);
	glPopMatrix();

	// Hat
    glColor3f(0.0f, 0.0f, 0.0f); //Black
    glPushMatrix();
        glTranslatef(0, 1.35f, 0.0f);
        glRotatef(-90, 1.0f, 0.0f, 0.0f);
        glutSolidCylinder( 0.20f  , 0.3f, 26, 13);
    glPopMatrix();

	// Hat brim
    glColor3f(0.0f, 0.0f, 0.0f); //Black
    glPushMatrix();
        glTranslatef(0, 1.25f, 0.0f);
        glRotatef(-90, 1.0f, 0.0f, 0.0f);
        glutSolidCylinder(0.24f  , 0.1f, 26, 13);
    glPopMatrix();

    //buttons
    glColor3f(0.0f, 0.0f, 0.0f); //Black
    glPushMatrix();
        glTranslatef(0.0f, 0.8f, 0.32f);
        gluSphere(pObj, 0.03f, 26, 13);
	glPopMatrix();

    glColor3f(0.0f, 0.0f, 0.0f); //Black
    glPushMatrix();
        glTranslatef(0.0f, 0.6f, 0.37f);
        gluSphere(pObj, 0.03f, 26, 13);
	glPopMatrix();

    glColor3f(0.0f, 0.0f, 0.0f); //Black
    glPushMatrix();
        glTranslatef(0.0f, 0.3f, 0.37f);
        gluSphere(pObj, 0.03f, 26, 13);
	glPopMatrix();

    glColor3f(0.0f, 0.0f, 0.0f); //Black
    glPushMatrix();
        glTranslatef(0.0f, 0.1f, 0.48f);
        gluSphere(pObj, 0.03f, 26, 13);
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
    glutCreateWindow("Lucas novak - snowman");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();

    return 0;
}

