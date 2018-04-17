#include "world.h"
#include <iostream>
//#include "GL/glut.h"
/*
int Width = 1000, Height = 800;
World world;
void Display()
{
	glClearColor(0.3, 0.5, 1, 1);

	float max = 0;
	for (int i(0); i < WORLD_SIZE; i++)
		for (int j(0); j < WORLD_SIZE; j++)
			if (world.mesh[i][j].energy > max)
				max = world.mesh[i][j].energy;

	float a = (Height - 200) / WORLD_SIZE, x = -Width / 2 + 200, y = -Height / 2 + 100, c;

	glBegin(GL_QUADS);
	for (int i(0); i < WORLD_SIZE; i++)
		for (int j(0); j < WORLD_SIZE; j++)
		{
			c = world.mesh[i][j].energy;
			glColor3f(0.3 - c/8, 0.5 - c/2, 1 -c/3);
			glVertex2f(x + i*a, y + j*a);
			glVertex2f(x + i*a + a, y + j*a);
			glVertex2f(x + i*a + a, y + j*a + a);
			glVertex2f(x + i*a, y + j*a + a);
		}
	glEnd();
	glFinish();
}

void Reshape(int Width, int Height)
{
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-Width / 2, Width / 2, -Height / 2, Height / 2, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.3, 0.5, 1, 1);
}

void Mouse(int button, int state, GLint x, GLint y)
{
	if (state == GLUT_DOWN)return;
	world.sendData();
	glutPostRedisplay();
}
*/

int main(int argc, char **argv) {
	Space space(10, 10);
	space.printMesh();
	space.addEnergyToNode(5, 5, 100.0);
	space.step();
	space.printMesh();

	World world = World(Time(1.0), Space(15, 15));
	/*
	world.addEnergyToNode(1, 1, 20.0);
	world.addEnergyToNode(6, 10, 20.0);
	world.addEnergyToNode(4, 15, 20.0);
	world.addEnergyToNode(10, 10, 80.0);
	world.addEnergyToNode(4, 8, 500.0);
	*/
	/*
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("aiBox");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMouseFunc(Mouse);
	glutMainLoop();
	*/
	return 0;
}
