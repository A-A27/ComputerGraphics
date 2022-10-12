#include <GL/glut.h>

void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glRotated(10, 1, 1, 0);
	glutWireSphere(0.5, 10, 6);
	glutSolidSphere(0.5, 10, 6);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Kang Ahhyun");
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);

	glMatrixMode(GL_PROJECTION);

	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}