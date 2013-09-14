#include "Scene.h"
#include "gl/glut.h"


Scene::Scene(void)
{
	//nothing to do here
}


Scene::~Scene(void)
{
	//nothing to do here
}

void Scene::render(void)
{
	glTranslatef(0.0f,0.0f,-10.0f);

	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(3.0f, 1.0f, 0.0f);
		glVertex3f(2.0f, -1.0f, 0.0f);
		glVertex3f(4.0f, -1.0f, 0.0f);
	glEnd();
}
