//마우스 우클릭 시 메뉴가 뜨고, Sphere or Torus 선택 시 해당 도형의 그림이 그려진다.
#include <GL/glut.h>

GLboolean IsSphere = true;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);
	if (IsSphere)
		glutWireSphere(0.2, 15, 15);
	else
		glutWireTorus(0.1, 0.3, 40, 20);
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

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Example Drawing");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw Torus", 2);
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}