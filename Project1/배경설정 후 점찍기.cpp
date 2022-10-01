//빨간색 배경에 노란색 포인트가 출력된다. POLYGON으로 배경을 먼저 설정한 후, POINTS로 점을 찍는다. 
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