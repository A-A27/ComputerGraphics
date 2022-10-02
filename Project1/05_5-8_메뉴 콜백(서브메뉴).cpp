//���� �޴��� �߰��ϸ� change size�� ��Ÿ���� ���� �޴� ���� ���콺�� �ø��� size �޴��� �ٽ� ��Ÿ����.
#include <GL/glut.h>
#include <stdio.h>

GLboolean IsSphere = true;
GLboolean IsSmall = true;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);
	if (IsSphere)
		glutWireSphere(0.2, 15, 15); // ���� (������, �߽������, ���ɿ�)
	else
		glutWireTorus(0.1, 0.3, 40, 20);	//��ȯü (���ʹ�����, �ٱ��ʹ�����, �ܸ鼱���ٻ�ȭ��, �������бٻ�ȭ��)

	if (IsSphere && IsSmall)
		glutWireSphere(0.2, 5, 15);	//���� ����
	else if (IsSphere && !IsSmall)
		glutWireSphere(0.4, 5, 15);	//ū ����
	else if (!IsSphere && IsSmall)
		glutWireTorus(0.1, 0.3, 40, 20);	//���� ��ȯü
	else
		glutWireTorus(0.2, 0.3, 40, 20);	//ū ��ȯü

	glFlush();
}

void MyMainMenu(int entryID) {
	if (entryID == 1)
		IsSphere = true;
	else if (entryID == 2)
		IsSphere = false;
	else if (entryID == 3)
		exit(0);
	glutPostRedisplay();
}

void MySubMenu(int entryID) {
	if (entryID == 1)
		IsSmall = true;
	else if (entryID == 2)
		IsSmall = false;
	else if (entryID == 3)
		exit(0);
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MyMainMenu");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLint MySubMenuID = glutCreateMenu(MySubMenu);	//����޴� �̸� �غ�
	glutAddMenuEntry("Small One", 1);	//�޴� ���� �׸�
	glutAddMenuEntry("Big One", 2);
	printf("MySubMenuID: %d", MySubMenuID);


	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);  //���ο� �޴� �����, ���� �޴� ����
	glutAddMenuEntry("Draw Sphere", 1);		//�޴� ���� �׸�, �޴� �ϳ� (1�� ����)
	glutAddMenuEntry("Draw Torus", 2);
	glutAddSubMenu("Change Size", MySubMenuID);		//����޴��� ���� �޴��� attach
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	printf("MyMainMenuID: %d", MyMainMenuID);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}