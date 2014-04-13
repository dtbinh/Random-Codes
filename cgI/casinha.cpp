#include <stdlib.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

float translacaoX = 0.0;
float translacaoY = 0.0;

void desenhaCasinha()
{
    // Define a cor de desenho: azul
    glColor3f(1,0,0);

	glLineWidth(3);
    // Determina a espessura da linha que ser� desenhada
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.2f,0.1f);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f,0.22f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.2f,0.1f);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f(-0.2f,-0.1f);
        glVertex2f( 0.2f,-0.1f);
        glVertex2f( 0.2f, 0.1f);
    glEnd();
}

void desenhaEixos()
{
    glColor3f(1,1,1);

    glBegin(GL_LINES);
        glVertex2f(-1.0f, 0.0f);
        glVertex2f( 1.0f, 0.0f);
        glVertex2f( 0.0f, -1.0f);
        glVertex2f( 0.0f,  1.0f);
    glEnd();
}

// Fun��o callback de redesenho da janela de visualiza��o
void Desenha(void)
{
	// Limpa a janela de visualiza��o com a cor preta
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glLoadIdentity();

    desenhaEixos();

    glPopMatrix();

    glLoadIdentity();

    glTranslatef(translacaoX, translacaoY, 0.0f);

    desenhaCasinha();

	//Executa os comandos OpenGL
	glFlush();
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
    if (key == 'w')
		translacaoY += 0.1;
    if (key == 'a')
		translacaoX -= 0.1;
    if (key == 's')
		translacaoY -= 0.1;
    if (key == 'd')
		translacaoX += 0.1;

    //precisa para criar evento de teclado.
    glutPostRedisplay();

}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa(void)
{
	// Define a janela de visualiza��o 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}

// Programa Principal
int main(void)
{
	int argc = 0;
	char *argv[] = { (char *)"gl", 0 };

	glutInit(&argc,argv);

// Define do modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(500,500);

	// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Desenho de um tri�ngulo em 2D");

	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Desenha);

	// Registra a fun��o callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	// Chama a fun��o respons�vel por fazer as inicializa��es
	Inicializa();

	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();

	return 0;
}
