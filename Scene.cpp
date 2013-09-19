#include "Scene.h"
#include <gl/GLaux.h>
#include <gl/glut.h>


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
	glTranslatef(0.0f,0.0f,-10.0f);
	
	glColor3f(1.0f,0.0f,0.0f);
	glPushMatrix();
		glTranslatef(2.0f,0.0f,0.0f);
		glCallList(CUBE);
	glPopMatrix();

	glColor3f(0.0f,1.0f,0.0f);
	glPushMatrix();
		glTranslatef(-2.0f,0.0f,0.0f);
		glCallList(CUBE);
	glPopMatrix();

	glColor3f(0.0f,0.0f,1.0f);
	glPushMatrix();
		glTranslatef(0.0f,2.5f,0.0f);
		glRotatef(alfa,0.0f,1.0f,0.0f);
		glCallList(CUBE);
	glPopMatrix();

	glColor3f(1.0f,1.0f,0.0f);
	glPushMatrix();
		glTranslatef(0.0f,-2.0f,0.0f);
		glScalef(1.5f,0.5f,1.0f);
		glCallList(CUBE);
	glPopMatrix();

	alfa+=0.02;
}

void Scene::buildCube(void)
{
	glNewList(CUBE, GL_COMPILE);
		glBegin(GL_QUADS);
			//Top face
			glNormal3f(0,1,0);
			glVertex3f(-1,1,-1);
			glVertex3f(-1,1,1);
			glVertex3f(1,1,1);
			glVertex3f(1,1,-1);
			// Bottom Face
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f( 1.0f, -1.0f, -1.0f);
			glVertex3f( 1.0f, -1.0f,  1.0f);
			glVertex3f(-1.0f, -1.0f,  1.0f);
			// Front Face
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3f(-1.0f, -1.0f,  1.0f);
			glVertex3f( 1.0f, -1.0f,  1.0f);
			glVertex3f( 1.0f,  1.0f,  1.0f);
			glVertex3f(-1.0f,  1.0f,  1.0f);
			// Back Face
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f,  1.0f, -1.0f);
			glVertex3f( 1.0f,  1.0f, -1.0f);
			glVertex3f( 1.0f, -1.0f, -1.0f);
			// Right face
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3f( 1.0f, -1.0f, -1.0f);
			glVertex3f( 1.0f,  1.0f, -1.0f);
			glVertex3f( 1.0f,  1.0f,  1.0f);
			glVertex3f( 1.0f, -1.0f,  1.0f);
			// Left Face
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f,  1.0f);
			glVertex3f(-1.0f,  1.0f,  1.0f);
			glVertex3f(-1.0f,  1.0f, -1.0f);
		glEnd();
	glEndList();
}
