#include <GL/glut.h>

GLfloat MyVertices_pyramid[12][3] = { { 0.0,0.5,0.0},{ -0.5,-0.5,0.5},{ 0.5,-0.5,0.5},{ 0.0,0.5,0.0},{ 0.5,-0.5,0.5},
{ 0.5,-0.5,-0.5}, { 0.0,0.5,0.0}, { 0.5,-0.5,-0.5}, { -0.5,-0.5,-0.5}, { 0.0,0.5,0.0}, { -0.5,-0.5,-0.5}, { -0.5,-0.5,0.5} };

GLfloat MyColors_pyramid[12][3] = { {1.0,0.0,0.0},{0.0,1.0,0.0}, {0.0,0.0,1.0},{1.0,0.0,0.0},{0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,0.0,0.0},{0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,0.0,0.0},{0.0,1.0,0.0}, {0.0,0.0,1.0} };

GLfloat MyVertexList_pyramid[12] = { 0,1,2, 3,4,5, 6,7,8, 9,10,11 }; // 앞 -> 오 -> 왼 -> 뒤

void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnableClientState(GL_COLOR_ARRAY); // color 배열 enable
	glEnableClientState(GL_VERTEX_ARRAY);

	glColorPointer(3, GL_FLOAT, 0, MyColors_pyramid); //첫번째 요소 : 한 점에서 유효한 숫자 갯수
	glVertexPointer(3, GL_FLOAT, 0, MyVertices_pyramid);

	glRotatef(30, 1, 1, 1);

	for (GLint i = 0; i < 4; i++)
		glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_BYTE, &MyVertexList_pyramid[3 * i]);
	// Bottom ? glDrawElements(GL_POLYGON,4,GL_UNSIGNED_BYTE, )
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Kang Ahhyun");
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);

	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}