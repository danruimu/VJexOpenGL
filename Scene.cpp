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

void render3Cubes(float alfa) {
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
}

void renderCylSphCyl(float alfa) {
	GLUquadricObj *quad;
	quad = gluNewQuadric();

	glColor3f(1.0f,0.0f,0.0f);
	glPushMatrix();
		glTranslatef(-3.0,0.0f,0.0f);
		gluCylinder(quad,1.0f,0.0f,3.0f,10,10);
	glPopMatrix();

	glColor3f(1.0f,1.0f,0.0f);
	glPushMatrix();
		glTranslatef(0.0,0.0f,0.0f);
		gluSphere(quad,0.5f,10,5);
	glPopMatrix();

	glColor3f(0.0f,1.0f,0.0f);
	glPushMatrix();
		glTranslatef(3.0,0.0f,0.0f);
		glRotatef(alfa,1.0,0.0f,0.0f);
		gluCylinder(quad,1.0f,1.0f,3.0f,20,20);
	glPopMatrix();
	
	gluDeleteQuadric(quad);
}

void renderSvastic(void) {
	glCallList(SVAS);
}

void Scene::render(void)
{
	glTranslatef(0.0f,0.0f,-20.0f);
	
	renderSvastic();

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

void Scene::buildSvastic(void) {
	glNewList(SVAS, GL_COMPILE);
		//L direction UP
		glBegin(GL_QUADS);
			//Top L
			//Front Face
			glColor3f(0,0,0);
			glNormal3f(0,0,-1);
			glVertex3f(0.5,0,1);
			glVertex3f(.5,4,1);
			glVertex3f(-.5,4,1);
			glVertex3f(-.5,0,1);

			glVertex3f(.5,3,1);
			glVertex3f(3,3,1);
			glVertex3f(3,4,1);
			glVertex3f(.5,4,1);
			
			//Back Face
			glNormal3f(0,0,1);
			glVertex3f(0.5,0,-1);
			glVertex3f(.5,4,-1);
			glVertex3f(-.5,4,-1);
			glVertex3f(-.5,0,-1);

			glVertex3f(.5,3,-1);
			glVertex3f(3,3,-1);
			glVertex3f(3,4,-1);
			glVertex3f(.5,4,-1);

			//Right face
			glNormal3f(1,0,0);
			glVertex3f(.5,0,-1);
			glVertex3f(.5,0,1);
			glVertex3f(.5,4,1);
			glVertex3f(.5,4,-1);

			glVertex3f(3,3,-1);
			glVertex3f(3,3,1);
			glVertex3f(3,4,1);
			glVertex3f(3,4,-1);

			//Left face
			glNormal3f(-1,0,0);
			glVertex3f(-.5,0,-1);
			glVertex3f(-.5,0,1);
			glVertex3f(-.5,4,1);
			glVertex3f(-.5,4,-1);

			//Top face
			glNormal3f(0,1,0);
			glVertex3f(-.5,4,-1);
			glVertex3f(3,4,-1);
			glVertex3f(3,4,1);
			glVertex3f(-.5,4,1);

			//Bottom face
			glNormal3f(0,-1,0);
			glVertex3f(.5,3,-1);
			glVertex3f(3,3,-1);
			glVertex3f(3,3,1);
			glVertex3f(.5,3,1);

			//Bottom L
			//Front Face
			glNormal3f(0,0,-1);
			glVertex3f(0.5,0,1);
			glVertex3f(.5,-4,1);
			glVertex3f(-.5,-4,1);
			glVertex3f(-.5,0,1);

			glVertex3f(-.5,-3,1);
			glVertex3f(-3,-3,1);
			glVertex3f(-3,-4,1);
			glVertex3f(-.5,-4,1);
			
			//Back Face
			glNormal3f(0,0,1);
			glVertex3f(0.5,0,-1);
			glVertex3f(.5,-4,-1);
			glVertex3f(-.5,-4,-1);
			glVertex3f(-.5,0,-1);

			glVertex3f(-.5,-3,-1);
			glVertex3f(-3,-3,-1);
			glVertex3f(-3,-4,-1);
			glVertex3f(-.5,-4,-1);

			//Left face
			glNormal3f(-1,0,0);
			glVertex3f(-.5,0,-1);
			glVertex3f(-.5,0,1);
			glVertex3f(-.5,-4,1);
			glVertex3f(-.5,-4,-1);

			glVertex3f(-3,-3,-1);
			glVertex3f(-3,-3,1);
			glVertex3f(-3,-4,1);
			glVertex3f(-3,-4,-1);

			//Right face
			glNormal3f(1,0,0);
			glVertex3f(.5,0,-1);
			glVertex3f(.5,0,1);
			glVertex3f(.5,-4,1);
			glVertex3f(.5,-4,-1);

			//Bottom face
			glNormal3f(0,-1,0);
			glVertex3f(.5,-4,-1);
			glVertex3f(-3,-4,-1);
			glVertex3f(-3,-4,1);
			glVertex3f(.5,-4,1);

			//Top face
			glNormal3f(0,1,0);
			glVertex3f(-.5,-3,-1);
			glVertex3f(-3,-3,-1);
			glVertex3f(-3,-3,1);
			glVertex3f(-.5,-3,1);

			//Transversals
			//Front Face
			glNormal3f(0,0,-1);
			glVertex3f(-4,.5,-1);
			glVertex3f(4,.5,-1);
			glVertex3f(4,-.5,-1);
			glVertex3f(-4,-.5,-1);

			glVertex3f(-4, .5, -1);
			glVertex3f(-3, .5, -1);
			glVertex3f(-3, 3, -1);
			glVertex3f(-4, 3, -1);

			//Back face
			glNormal3f(0,0,1);
			glVertex3f(-4,.5,1);
			glVertex3f(4,.5,1);
			glVertex3f(4,-.5,1);
			glVertex3f(-4,-.5,1);

			glVertex3f(-4, .5, 1);
			glVertex3f(-3, .5, 1);
			glVertex3f(-3, 3, 1);
			glVertex3f(-4, 3, 1);

		glEnd();
	glEndList();
}
