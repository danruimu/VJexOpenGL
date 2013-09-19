// TresD.cpp : Defines the entry point for the console application.
//

#include <windows.h> 
#include <gl/glut.h>
#include "Scene.h"

//Delete console
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

Scene scene;

//OpenGL initializations
void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	//background color
}

//Rendering
void render(void)   
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	scene.render();

    glutSwapBuffers();					//Swap makes rendering visible
}

//Reshaping handler (required even in fullscreen-only modes)
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Calculate the aspect ratio and set the clipping volume
	gluPerspective(45, (float)w/(float)h, 0.1, 10000.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//Keyboard handler (normal keys)
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27:	exit(0);
					break;
	}
}

//Keyboard handler for special keys (like arrow keys and function keys)
void special_keys(int a_keys, int x, int y)
{
	/*switch (a_keys)
	{
	}*/
}

void mouse(int button,int status,int x, int y){
	if(status == GLUT_UP)glutSetCursor(GLUT_CURSOR_NONE);				// Make the default cursor disappear
	if(status == GLUT_DOWN)glutSetCursor(GLUT_CURSOR_CROSSHAIR);				// Make the default cursor disappear
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);							// GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);	// Display mode (rgb and double buffered)
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("My great game!");
	/*
	glutGameModeString("1024x768:24");				// Select the 640x480 in 16bpp mode
	glutEnterGameMode();
	*/
	glutSetCursor(GLUT_CURSOR_NONE);				// Make the default cursor disappear

	init();											// Initialization
	glutDisplayFunc(render);						// Register the display function
	glutReshapeFunc(reshape);						// Register the Reshape handler
	glutKeyboardFunc(keyboard);						// Register the keyboard handler
	glutSpecialFunc(special_keys);					// Register special keys handler
	glutMouseFunc(mouse);
	glutIdleFunc(render);
	glutMainLoop();									// Go to GLUT main loop
}
