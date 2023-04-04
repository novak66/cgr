#include <GL/glut.h>
#include <math.h>

GLfloat angle = 0.0; // Ângulo para a rotação do boneco de neve

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glDisable(GL_CULL_FACE);
    gluLookAt(0.0, 0.0, 5.0, // Posição da câmera
              0.0, 0.0, 0.0, // Ponto para onde a câmera aponta
              0.0, 1.0, 0.0); // Vetor de orientação da câmera


    glRotatef(angle, 0.0, 1.0, 0.0); // Rotação do boneco de neve em torno do eixo y

    // Desenha o corpo do boneco de neve
    glColor3f(1.0, 1.0, 1.0); // Define a cor para branco
    glutSolidSphere(0.5, 20, 20); // Desenha uma esfera com raio 0.5

    // Desenha a cabeça do boneco de neve
    glTranslatef(0.0, 0.7, 0.0); // Translada a esfera para cima do corpo
    glutSolidSphere(0.3, 20, 5); // Desenha uma esfera menor com raio 0.3

    // Desenha os olhos do boneco de neve
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); // Define a cor para preto
    glTranslatef(-0.1, 0.1, 0.25); // Translada para a posição do olho esquerdo
    glutSolidSphere(0.05, 10, 10); // Desenha uma esfera pequena para o olho esquerdo

    glTranslatef(0.2, 0.0, 0.0); // Translada para a posição do olho direito
    glutSolidSphere(0.05, 10, 10); // Desenha uma esfera pequena para o olho direito
    glPopMatrix();

    // Desenha o nariz do boneco de neve
    glColor3f(1.0, 0.0, 0.0); // Define a cor para vermelho
    glTranslatef(0.0, -0.1, 0.25); // Translada para a posição do nariz
    glutSolidCone(0.1, 0.3, 10, 10); // Desenha um cone para o nariz

    glutSwapBuffers();
}


void reshape(GLsizei width, GLsizei height) {
if (height == 0) height = 1;
GLfloat aspect = (GLfloat)width / (GLfloat)height;
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0, aspect, 0.1, 100.0);
glMatrixMode(GL_MODELVIEW);
}

void SpecialKeys(int key, int x, int y){

    if(key == GLUT_KEY_LEFT)
        angle -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
        angle += 5.0f;

    angle = (GLfloat)((const int)angle % 360);

    // Refresh the Window
    glutPostRedisplay();
}



int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE);
glutInitWindowSize(800, 600);
glutInitWindowPosition(100, 100);
glutCreateWindow("Boneco de Neve");
glutDisplayFunc(display);
glutSpecialFunc(SpecialKeys);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
