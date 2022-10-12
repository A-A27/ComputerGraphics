#include <GL/glut.h>

void mydisplay() {
	
	glutSolidTeapot(0.3); // 첫 주전자는 하얀색으로 정중앙에 하나 생성.
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); // 주전자가 반복해서 생성되는 것을 방지 -> 정중앙을 기준으로 변환되는 것을 출력하기 위해서 이 함수를 써야되는 것.

	glTranslatef(0.2, 0.0, 0.0); // 이동변환 x축으로 0.2만큼 이동
	glColor3f(1.0, 0.0, 0.0);
	glutSolidTeapot(0.3);

	glTranslatef(0.2, 0.0, 0.0); // 이동변환
	glRotatef(45, 0, 0, 1); // 회전변환
	glScalef(1.5, 1.5, 1.0); // 크기변환 
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