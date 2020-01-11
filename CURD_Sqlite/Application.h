#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Application
{
public:
	Application();
	void run();
	void processInput();
	void update();
	void render();
private:
	sf::RenderWindow m_window;
	sf::Font m_font;
	std::vector<sf::Text> m_options;
};

