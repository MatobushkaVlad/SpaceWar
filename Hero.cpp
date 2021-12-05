#include "Hero.hpp"

namespace he
{
	Hero::Hero(int x, int y, float r_x, float r_y)
	{
		m_x = x;
		m_y = y;
		m_r_x = r_x;
		m_r_y = r_y;
		m_hero = new sf::RectangleShape(sf::Vector2f(m_r_x, m_r_y));
		m_hero->setOrigin((m_x / 2), (m_y / 2));
		m_hero->setPosition(320, 1000);
		m_hero->setFillColor(sf::Color::Green);
	}

	Hero::~Hero() { delete m_hero; }

	sf::RectangleShape* Hero::GetH() { return m_hero; }
}