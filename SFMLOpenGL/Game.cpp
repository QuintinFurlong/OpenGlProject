#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)
{
}

Game::~Game() {}

void Game::run()
{
	srand(time(nullptr));
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
	glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
}

void Game::update()
{
	cout << "Update up" << endl;
	rotationAngle = 0.01;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		glTranslatef(0.001f, 0.0f, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		glTranslatef(-0.001f, 0.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		glTranslatef(0.0f, 0.001f, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		glTranslatef(0.0f, -0.001f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
	{
		glTranslatef(0.0f, 0.0f, 0.001f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
	{
		glTranslatef(-0.0f, 0.0f, -0.001f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		glRotatef(rotationAngle, 1.0f, 0.0f, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		glRotatef(rotationAngle, -1.0f, 0.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		glRotatef(rotationAngle, 0.0f, -1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		glRotatef(rotationAngle, 0.0f, 0.0f, -1.0f);
	}
			
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		glScalef(1.0001f, 1.0f, 1.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
	{
		glScalef(0.9999f, 1.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		glScalef(1.0f, 1.0001f, 1.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		glScalef(1.0f, 0.9999f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		glScalef(1.0f, 1.0f, 1.0001f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
	{
		glScalef(1.0f, 1.0f, 0.9999f);
	}
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_ACCUM_BUFFER_BIT);
	glBegin(GL_POLYGON); {
		for (float x = -2; x < 2; x += .01)
		{
			for (float y = -2; y < 2; y += .01)
			{
				glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
				glVertex3f(x, y, -5.0);
			}
		}
	}
	window.display();
	glEnd();
	glBegin(GL_LINES); {
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-1.2, 1.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-1.2, 2.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-0.9, 2.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-0.9, 1.0, -5.0);
	}
	glEnd();
	glBegin(GL_LINE_STRIP); {
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-0.7, 1.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-0.7, 2.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-0.3, 2.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-0.3, 1.0, -5.0);
	}
	glEnd();
	glBegin(GL_LINE_LOOP); {
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(0.7, 1.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(0.7, 2.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(0.3, 2.0, -5.0);
	}
	glEnd();
	glBegin(GL_TRIANGLES); {
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-2.0, 2.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-1.5, 2.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-2.0, 1.5, -5.0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP); {
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.5, 2.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.7, 2.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.3, 1.5, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.9, 1.5, -5.0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN); {
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(0.0, 0.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(0.5, 0.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(0.0, 0.5, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-0.5, 0.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(0.0, -0.5, -5.0);
	}
	glEnd();
	glBegin(GL_QUADS); {
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-2.0, 0.5, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-1.0, 0.5, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-1.0, -0.5, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-2.0, -0.5, -5.0);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP); {
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.75, 0.2, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.6, 0.2, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.6, 0.4, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.75, 0.4, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.45, 0.4, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.45, 0.2, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.6, 0.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.45, 0.0, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.6, -0.2, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.45, -0.2, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.6, -0.4, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.45, -0.4, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.3, -0.2, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(1.3, -0.4, -5.0);
	}
	glEnd();
	glBegin(GL_POLYGON); {
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-0.2, -0.6, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(0.2, -0.6, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(0.6, -1, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(0.6, -1.4, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(0.2, -1.8, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-0.2, -1.8, -5.0);
		glColor3f((rand() % 25) / 10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-0.6, -1.4, -5.0);
		glColor3f((rand() % 25)/10, (rand() % 25) / 10, (rand() % 25) / 10);
		glVertex3f(-0.6, -1, -5.0);
	}
	glEnd();

	
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

//#include <Game.h>
//
// // Uncomment for Part 2
// // ********************
//bool flip = false;
//int current = 1;
// // ********************
//
////  Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)
//
//Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)
//{
//	 // Uncomment for Part 2
//	 // ********************
//	 index = glGenLists(primatives);
//	 // ********************
//}
//
//Game::~Game() {}
//
//void Game::run()
//{
//
//	initialize();
//
//	Event event;
//
//	while (isRunning) {
//
//		cout << "Game running..." << endl;
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//			{
//				isRunning = false;
//			}
//		}
//		update();
//		draw();
//	}
//
//}
//
//void Game::initialize()
//{
//	isRunning = true;
//
//	 // Uncomment for Part 2
//	 // ********************
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
//	glMatrixMode(GL_MODELVIEW);
//
//
//	glNewList(index, GL_COMPILE);
//	glBegin(GL_TRIANGLES);
//	{
//		glColor3f(0.0f, 0.0f, 1.0f);
//		glVertex3f(0.0, 2.0, -5.0);
//		glVertex3f(-2.0, -2.0, -5.0);
//		glVertex3f(2.0, -2.0, -5.0);
//	}
//	glEnd();
//	glEndList();
//
//	glNewList(index + 1, GL_COMPILE);
//	glBegin(GL_TRIANGLES);
//	{
//		glColor3f(0.0f, 1.0f, 0.0f);
//		glVertex3f(0.2, 0.0, -2.0);
//		glVertex3f(-2.0, -2.0, -2.0);
//		glVertex3f(2.0, -2.0, -2.0);
//	}
//	glEnd();
//	glEndList();
//
//	 // Uncomment for Part 2
//	 // ********************
//}
//
//void Game::update()
//{
//
//	 // Uncomment for Part 2
//	 // ********************
//	elapsed = clock.getElapsedTime();
//
//	if (elapsed.asSeconds() >= 1.0f)
//	{
//		clock.restart();
//
//		if (!flip)
//		{
//			flip = true;
//			current++;
//			if (current > primatives)
//			{
//				current = 1;
//			}
//		}
//		else
//			flip = false;
//	}
//
//	if (flip)
//	{
//		rotationAngle += 0.005f;
//
//		if (rotationAngle > 360.0f)
//		{
//			rotationAngle -= 360.0f;
//		}
//	}
//	 // ********************
//
//	cout << "Update up" << endl;
//}
//
//void Game::draw()
//{
//
//	 // Uncomment for Part 2
//	 // ********************
//	cout << "Draw up" << endl;
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	//Investigate Here!!!!!
//
//	cout << "Drawing Primative " << current << endl;
//	glCallList(current);
//	 // Uncomment for Part 2
//	 // ********************
//
//	window.display();
//
//}
//
//void Game::unload()
//{
//	cout << "Cleaning up" << endl;
//}
//
