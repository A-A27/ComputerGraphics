// Viewport를 기준으로 사각형을 만들게 된다. 두 사각형의 Viewport의 좌표값이 아래와 같이 설정되는 것이 맞는지 확인해봐야한다.
#include <GL/glut.h>

void MyDisplay() {					//디스플레이 콜백함수
	glClear(GL_COLOR_BUFFER_BIT);	//GL 상태변수 설정
	glViewport(0, 0, 150, 150);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);			//입력 기본요소 정의
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();

	glViewport(150, 150, 150, 150);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);			//입력 기본요소 정의
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);			//GLUT 윈도우 함수
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");

	glClearColor(0.5, 0.0, 0.7, 1.0);//GL 상태변수 설정, 배경색을 보라색으로
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);		//GLUT 콜백함수 등록
	glutMainLoop();					//이벤트 루프 진입
	return 0;
}