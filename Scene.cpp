#include "Scene.h"
#include "gl/glut.h"


Scene::Scene(void)
{
	alfa = 0.05;
}


Scene::~Scene(void)
{
	//nothing to do here
}

void Scene::render(void)
{
	glTranslatef(-1.0f,0.0f,-10.0f);

	//glColor3f(1.0f, 1.0f, 0.0f);

	//3 base triangles
	glPushMatrix();
		glRotatef(alfa,0,0,1);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);	//red
		glVertex3f(3.0f, -1.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);	//green
		glVertex3f(2.0f, -3.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);	//blue
		glVertex3f(4.0f, -3.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(alfa,0,0,-1);
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 0.0f);	//black
		glVertex3f(1.0f, -1.0f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);	//white
		glVertex3f(0.0f, -3.0f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);	//white
		glVertex3f(2.0f, -3.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(alfa,0,0,1);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);	//red
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);	//blue
		glVertex3f(-2.0f, -3.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);	//green
		glVertex3f(0.0f, -3.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//2 middle triangle
		glRotatef(alfa,0,1,0);
	glBegin(GL_TRIANGLES);
		glColor3f(0.5f, 0.0f, 0.0f);	//dark red
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 0.5f, 0.0f);	//dark green
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 0.5f);	//dark blue
		glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(alfa,0,-1,0);
	glBegin(GL_TRIANGLES);
		glColor3f(0.5f, 0.0f, 0.0f);	//dark red
		glVertex3f(2.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 0.5f);	//dark blue
		glVertex3f(1.0f, -1.0f, 0.0f);
		glColor3f(0.0f, 0.5f, 0.0f);	//dark green
		glVertex3f(3.0f, -1.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//1 top triangle
		glRotatef(alfa,1,-1,1);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 1.0f, 0.0f);	//yellow
		glVertex3f(1.0f, 3.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 1.0f);	//magenta
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 1.0f);	//cyan
		glVertex3f(2.0f, 1.0f, 0.0f);
	glEnd();
	glPopMatrix();

	//1 yellow square
	glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-2.0f, -3.5f, 0.0f);
		glVertex3f(4.0f, -3.5f, 0.0f);

		glVertex3f(4.0f, -3.5f, 0.0f);
		glVertex3f(4.0f, 3.5f, 0.0f);

		glVertex3f(4.0f, 3.5f, 0.0f);
		glVertex3f(-2.0f, 3.5f, 0.0f);

		glVertex3f(-2.0f, 3.5f, 0.0f);
		glVertex3f(-2.0f, -3.5f, 0.0f);
	glEnd();
	alfa+=0.02;
}
