//2���� ���� ��Ÿ����.
#include <GL/glut.h>

void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(5.0); //set line width

	glBegin(GL_LINES);
	/*glVertex2f(-0.5, -0.5); ������ ���η� �׸���.
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);*/
	glVertex2f(-0.5, -0.5); // ������ �밢��(������)���� �׸���.
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, 0.5);
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