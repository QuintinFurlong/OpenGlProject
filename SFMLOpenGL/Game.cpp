#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
	tracker = 0;
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x /
		window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	isRunning = true;
}

void Game::update()
{
	cout << "Update up" << endl;
	tracker++;
	if (tracker > 10)
	{
		tracker = 0;
	}
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_ACCUM_BUFFER_BIT);
	glBegin(GL_POINTS); {
		glVertex3f(-1.0, 1.0, -5.0);
	}
	glEnd();
	glBegin(GL_LINES); {
		glVertex3f(-1.2, 1.0, -5.0);
		glVertex3f(-1.2, 2.0, -5.0);
		glVertex3f(-0.9, 2.0, -5.0);
		glVertex3f(-0.9, 1.0, -5.0);
	}
	glEnd();
	glBegin(GL_LINE_STRIP); {
		glVertex3f(-0.7, 1.0, -5.0);
		glVertex3f(-0.7, 2.0, -5.0);
		glVertex3f(-0.3, 2.0, -5.0);
		glVertex3f(-0.3, 1.0, -5.0);
	}
	glEnd();
	glBegin(GL_LINE_LOOP); {
		glVertex3f(0.7, 1.0, -5.0);
		glVertex3f(0.7, 2.0, -5.0);
		glVertex3f(0.3, 2.0, -5.0);
	}
	glEnd();
	glBegin(GL_TRIANGLES); {
		glVertex3f(-2.0, 2.0, -5.0);
		glVertex3f(-1.5, 2.0, -5.0);
		glVertex3f(-2.0, 1.5, -5.0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP); {
		glVertex3f(1.5, 2.0, -5.0);
		glVertex3f(1.7, 2.0, -5.0);
		glVertex3f(1.3, 1.5, -5.0);
		glVertex3f(1.9, 1.5, -5.0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN); {
		glVertex3f(0.0, 0.0, -5.0);
		glVertex3f(0.5, 0.0, -5.0);
		glVertex3f(0.0, 0.5, -5.0);
		glVertex3f(-0.5, 0.0, -5.0);
		glVertex3f(0.0, -0.5, -5.0);
	}
	glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(-2.0, 0.5, -5.0);
		glVertex3f(-1.0, 0.5, -5.0);
		glVertex3f(-1.0, -0.5, -5.0);
		glVertex3f(-2.0, -0.5, -5.0);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP); {
		glVertex3f(1.75, 0.2, -5.0);
		glVertex3f(1.6, 0.2, -5.0);
		glVertex3f(1.6, 0.4, -5.0);
		glVertex3f(1.75, 0.4, -5.0);
		glVertex3f(1.45, 0.4, -5.0);
		glVertex3f(1.45, 0.2, -5.0);
		glVertex3f(1.6, 0.0, -5.0);
		glVertex3f(1.45, 0.0, -5.0);
		glVertex3f(1.6, -0.2, -5.0);
		glVertex3f(1.45, -0.2, -5.0);
		glVertex3f(1.6, -0.4, -5.0);
		glVertex3f(1.45, -0.4, -5.0);
		glVertex3f(1.3, -0.2, -5.0);
		glVertex3f(1.3, -0.4, -5.0);
	}
	glEnd();

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

