#include <iostream>
//#include "world.h"
#include "tester.h"
#include "Resource.h"
#include "mesh_2d.h"
#include <windows.h>
#include <GL/glut.h>

bool flag = false;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();

	glFlush();
}

void key_reaction(unsigned char key, int x, int y)
{
	if (flag)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_POLYGON);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
		glEnd();

		glFlush();
		flag = false;
	}
	else
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_POLYGON);
		glVertex2f(-0.8, -0.8);
		glVertex2f(-0.8, 0.8);
		glVertex2f(0.8, 0.8);
		glVertex2f(0.8, -0.8);
		glEnd();

		glFlush();
		flag = true;
	}
}

void init()
{
	glClearColor(0.000, 0.110, 0.392, 0.0); // JMU Gold

	glColor3f(0.314, 0.314, 0.000); // JMU Purple

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Test");
	glutDisplayFunc(display);
	glutKeyboardFunc(key_reaction);
	init();
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
