#include <GL/glut.h>

void mydisplay() {
	
	glutSolidTeapot(0.3); // ù �����ڴ� �Ͼ������ ���߾ӿ� �ϳ� ����.
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); // �����ڰ� �ݺ��ؼ� �����Ǵ� ���� ���� -> ���߾��� �������� ��ȯ�Ǵ� ���� ����ϱ� ���ؼ� �� �Լ��� ��ߵǴ� ��.

	glTranslatef(0.2, 0.0, 0.0); // �̵���ȯ x������ 0.2��ŭ �̵�
	glColor3f(1.0, 0.0, 0.0);
	glutSolidTeapot(0.3);

	glTranslatef(0.2, 0.0, 0.0); // �̵���ȯ
	glRotatef(45, 0, 0, 1); // ȸ����ȯ
	glScalef(1.5, 1.5, 1.0); // ũ�⺯ȯ 
	glColor3f(0.0, 1.0, 0.0);
	glutSolidTeapot(0.3);

	
	glFlush();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Kang");
	
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}