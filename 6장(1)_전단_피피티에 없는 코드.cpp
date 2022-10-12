#include <GL/glut.h>
#include <stdio.h>

void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glColor3f(1.0, 0.0, 0.0);
	GLfloat x0 = 0.0;
	GLfloat y0 = 0.0;
	GLfloat x1 = 0.5;
	GLfloat y1 = 0.5;

	glBegin(GL_POLYGON);
		glVertex2f(x0, y0);
		glVertex2f(x1, y0);
		glVertex2f(x1, y1);
		glVertex2f(x0, y1);
	glEnd();

	GLfloat opt;
	GLfloat sh = 0.0;
	GLfloat x0_New; 
	GLfloat x1_New;
	GLfloat x2_New;
	GLfloat x3_New;

	GLfloat y0_New;
	GLfloat y1_New;
	GLfloat y2_New;
	GLfloat y3_New;

	printf("1 = shear y(수평전단),  2 = shear x(수직전단) \n");
	printf("enter you option");
	scanf_s("%f", &opt);

	if (opt == 1)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		printf("enter the parameter\n");
		scanf_s("%f", &sh);

		x0_New = x0 + sh * y0;
		x1_New = x1 + sh * y0;
		x2_New = x1 + sh * y1;
		x3_New = x0 + sh * y1;

		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
			glVertex2f(x0_New, y0);
			glVertex2f(x1_New, y0);
			glVertex2f(x2_New, y1);
			glVertex2f(x3_New, y1);
		glEnd();
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT);
		printf("enter the parameter\n");
		scanf_s("%f", &sh);

		y0_New = sh * x0 + y0;
		y1_New = sh * x1 + y0;
		y2_New = sh * x1 + y1;
		y3_New = sh * x0 + y1;

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
			glVertex2f(x0, y0_New);
			glVertex2f(x1, y1_New);
			glVertex2f(x1, y2_New);
			glVertex2f(x0, y3_New);
		glEnd();
	}
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Kang");

	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}