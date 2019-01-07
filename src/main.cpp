#include <iostream>
//#include "world.h"
#include "tester.h"
#include "Resource.h"
#include "mesh_2d.h"
#include <windows.h>
#include <GL/glut.h>

int WORLD_SIZE = 200;
int Width = 1000, Height = 800;
Mesh_2d mesh = Mesh_2d(Point({WORLD_SIZE, WORLD_SIZE}), Node());

// void display()
// {
// 	glClear(GL_COLOR_BUFFER_BIT);

// 	glBegin(GL_POLYGON);
// 	glVertex2f(-0.5, -0.5);
// 	glVertex2f(-0.5, 0.5);
// 	glVertex2f(0.5, 0.5);
// 	glVertex2f(0.5, -0.5);
// 	glEnd();

// 	glFlush();
// }

void key_reaction(unsigned char key, int x, int y)
{
	//world.sendData();
	mesh.step();
	glutPostRedisplay();
}

void display()
{
	glClearColor(0.3, 0.5, 1, 1);
	float max = 0;
	for (int i(0); i < WORLD_SIZE; i++)
		for (int j(0); j < WORLD_SIZE; j++)
			if (mesh.get_node_energy({i, j}) > max)
				max = mesh.get_node_energy({i, j});
	float a = (Height - 200) / WORLD_SIZE, x = -Width / 2 + 200, y = -Height / 2 + 100, c;
	glBegin(GL_QUADS);
	for (int i(0); i < WORLD_SIZE; i++)
		for (int j(0); j < WORLD_SIZE; j++)
		{
			c = mesh.get_node_energy({i, j});
			glColor3f(0.3 - c / 8, 0.5 - c / 2, 1 - c / 3);
			glVertex2f(x + i * a, y + j * a);
			glVertex2f(x + i * a + a, y + j * a);
			glVertex2f(x + i * a + a, y + j * a + a);
			glVertex2f(x + i * a, y + j * a + a);
		}
	glEnd();
	glFinish();
}

void reshape(int Width, int Height)
{
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-Width / 2, Width / 2, -Height / 2, Height / 2, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.3, 0.5, 1, 1);
}

int main(int argc, char **argv)
{
	mesh.add_energy_to_node({15, 15}, Energy(500.));
	mesh.add_energy_to_node({100, 15}, Energy(500.));
	mesh.add_energy_to_node({150, 150}, Energy(500.));

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("ai_box");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key_reaction);
	glutMainLoop();
	// if (!Tester::run_all_tests())
	// {
	// 	return EXIT_FAILURE;
	// }

	//Resource ec;
	// Mesh_2d mesh = Mesh_2d(Point({10, 10}), Node());
	// mesh.print_mesh();
	// std::cout << "total: " << mesh.get_total_energy_value() << std::endl;
	// std::cout << std::endl;

	// mesh.add_energy_to_node({1, 1}, Energy(9.));
	// mesh.print_mesh();
	// std::cout << "total: " << mesh.get_total_energy_value() << std::endl
	// 		  << std::endl;

	// for (int i = 0; i < 100; ++i)
	// {
	// 	mesh.step();
	// 	mesh.print_mesh();
	// 	std::cout << "total: " << mesh.get_total_energy_value() << std::endl
	// 			  << std::endl;
	// }

	//Mesh_2d_configuration config = Mesh_2d_configuration("mesh_config.txt");
	//Mesh_2d mesh = Mesh_2d(config);

	// Space space = Space(7, 7);
	// Time wTime = Time(1.0);
	// World world = World(&wTime, &space);

	// world.space->add_energy_to_node(3, 3, 1000.0);

	// Organism plant = Organism(50.0, 5, 5, &space);
	// world.plant = &plant;

	// int nStepsToLive;
	// std::cout << "Enter number of steps to live" << std::endl;
	// std::cin >> nStepsToLive;
	// world.live(nStepsToLive);

	return 0;
}
