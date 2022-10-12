//2개의 라인 나타내기.
#include <GL/glut.h>

void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(5.0); //set line width

	glBegin(GL_LINES);
	/*glVertex2f(-0.5, -0.5); 라인을 가로로 그린다.
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);*/
	glVertex2f(-0.5, -0.5); // 라인을 대각선(엑스자)으로 그린다.
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, 0.5);
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
