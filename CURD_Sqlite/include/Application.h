#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "sqlite3.h"

class Application
{
public:
	Application();
	void run();
	void processInput();
	void update();
	void render();

	void InitDataBase();
private:
	sf::RenderWindow m_window;
	sf::Font m_font;
	std::vector<sf::Text> m_options;
	sqlite3* m_dataBase;

	const std::string m_dataBaseName;
};

