//4���� �� ��Ÿ����.
#include <GL/glut.h>

void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10);

	glBegin(GL_LINE_LOOP);
	/*glVertex2f(-0.5, -0.5); ppt 1
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.5, 0.6);
	glVertex2f(-0.3, 0.6);*/
	glVertex2f(-0.5, -0.5); //ppt 2
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.3, 0.5);
	glVertex2f(0.0, -0.8);
	glVertex2f(0.3, 0.5);


	glEnd();
	glFlush(); //�ѷ����� ������ ȭ�鿡 ��Ÿ���� �ʴ´�.
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Kang Ahhyun");
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}