#include "Application.h"
#include <iostream>

static void centerOrigin(sf::Text& text);

Application::Application() : 
	m_window(sf::VideoMode(480, 480), "Save the world with C++", sf::Style::Close),
	m_dataBaseName("db/test.db")
{
	m_font.loadFromFile("meta/Sansation.ttf");
	sf::Text add("Add", m_font);
	centerOrigin(add);
	add.setPosition(m_window.getView().getSize()/2.f + sf::Vector2f(0.f, -60.f));

	sf::Text update("Update", m_font);
	centerOrigin(update);
	update.setPosition(add.getPosition() + sf::Vector2f(0.f, 30.f));

	sf::Text remove("Remove", m_font);
	centerOrigin(remove);
	remove.setPosition(update.getPosition() + sf::Vector2f(0.f, 30.f));

	m_options.push_back(add);
	m_options.push_back(update);
	m_options.push_back(remove);

	InitDataBase();
}

void Application::run()
{
	while (m_window.isOpen())
	{
		processInput();
		update();
		render();
	}
}

void Application::processInput()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Application::update()
{
}

void Application::render()
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Cyan);

	m_window.clear();

	for (auto option : m_options)
	{
		m_window.draw(option);
	}
	m_window.display();
}

void Application::InitDataBase()
{
	if (!m_dataBase)
	{
		std::cout << "Opening " << m_dataBaseName << std::endl;
		sqlite3_open(m_dataBaseName.c_str(), &m_dataBase);

		if (m_dataBase)
		{
			std::cout << "Succesfully opened " << m_dataBaseName << std::endl;
		}
	}
}

void centerOrigin(sf::Text& text)
{
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}