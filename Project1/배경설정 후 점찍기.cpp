//������ ��濡 ����� ����Ʈ�� ��µȴ�. POLYGON���� ����� ���� ������ ��, POINTS�� ���� ��´�. 
#include <GL/glut.h>

void Mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
	glEnd();

	glColor3f(1, 1, 0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2f(0.0, 0.0);
	glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Drawing Example");
	glutDisplayFunc(Mydisplay);
	glutMainLoop();
	return 0;
}