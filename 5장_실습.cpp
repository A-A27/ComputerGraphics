//
#include <GL/glut.h>

void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	glRotatef(30, 1, 1, 1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK); // �ĸ��� ������ ������ �����ϴ� ��.

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	glColor3f(1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	
	glEnd();
	
	glFlush(); //�ѷ����� ������ ȭ�鿡 ��Ÿ���� �ʴ´�.

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Kang Ahhyun");
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	
	glMatrixMode(GL_PROJECTION);
	
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}