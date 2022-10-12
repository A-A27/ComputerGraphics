#include <GL/glut.h>

GLfloat MyVertices[5][3] =
{ {0,0.25,0}, {-0.25, -0.25, 0.25},{0.25, -0.25, 0.25} ,{0.25, -0.25, -0.25} ,{-0.25, -0.25, -0.25} };
GLfloat MyColors[5][3] =
{ {1.0,1.0,1.0}, {1.0,0.0,1.0},{0.0,0.0,1.0},
{0.0,1.0,0.0} ,{0.0,1.0,1.0}  };
GLubyte MyVertexList[16] = { 0,1,2, 0,2,3, 0,3,4, 0,4,1, 1,4,3,2 };
void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, MyColors);
	glVertexPointer(3, GL_FLOAT, 0, MyVertices);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(30.0, 1.0, 1.0, 1.0);

	for (GLint i = 0; i < 5; i++)
		if (i == 4)
			glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[3 * i]);
		else
			glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_BYTE, &MyVertexList[3 * i]);
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Kang Ahhyun");
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);

	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}