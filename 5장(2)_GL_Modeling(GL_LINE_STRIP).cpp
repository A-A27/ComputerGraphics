//
#include <GL/glut.h>

void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(1.0);

	glBegin(GL_LINE_STRIP);
	/*glVertex2f(-0.5, -0.5); ppt 1
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);*/
	/*glVertex2f(-0.5, -0.5); ppt 2
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, 0.5);*/
	/*glVertex2f(-0.5, -0.5); ppt 3
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);*/
	glVertex2f(-0.5, -0.5); // ppt 4
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush(); //뿌려주지 않으면 화면에 나타나지 않는다.
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Kang Ahhyun");
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}