//서브 메뉴를 추가하면 change size로 나타나고 서브 메뉴 위에 마우스를 올리면 size 메뉴가 다시 나타난다.
#include <GL/glut.h>
#include <stdio.h>

GLboolean IsSphere = true;
GLboolean IsSmall = true;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);
	if (IsSphere)
		glutWireSphere(0.2, 15, 15); // 원구 (반지름, 중심통과선, 동심원)
	else
		glutWireTorus(0.1, 0.3, 40, 20);	//원환체 (안쪽반지름, 바깥쪽반지름, 단면선문근사화수, 윤곽선분근사화수)

	if (IsSphere && IsSmall)
		glutWireSphere(0.2, 5, 15);	//작은 원구
	else if (IsSphere && !IsSmall)
		glutWireSphere(0.4, 5, 15);	//큰 원구
	else if (!IsSphere && IsSmall)
		glutWireTorus(0.1, 0.3, 40, 20);	//작은 원환체
	else
		glutWireTorus(0.2, 0.3, 40, 20);	//큰 원환체

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

	GLint MySubMenuID = glutCreateMenu(MySubMenu);	//서브메뉴 미리 준비
	glutAddMenuEntry("Small One", 1);	//메뉴 구성 항목
	glutAddMenuEntry("Big One", 2);
	printf("MySubMenuID: %d", MySubMenuID);


	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);  //새로운 메뉴 만들기, 메인 메뉴 생성
	glutAddMenuEntry("Draw Sphere", 1);		//메뉴 구성 항목, 메뉴 하나 (1이 리턴)
	glutAddMenuEntry("Draw Torus", 2);
	glutAddSubMenu("Change Size", MySubMenuID);		//서브메뉴를 메인 메뉴에 attach
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	printf("MyMainMenuID: %d", MyMainMenuID);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}