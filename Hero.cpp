#include "Hero.hpp"
#include <iostream>

namespace he
{
	Hero::Hero(int x, int y, float r_x, float r_y)
	{
		m_x = x;
		m_y = y;
		m_r_x = r_x;
		m_r_y = r_y;
	}

	bool Hero::Setup()
	{
		if (!m_texture.loadFromFile("Textures/Hero_texture.png"))
		{
			std::cout <<"Error with hero's texture!!!" << std::endl;
			return false;
		}
		m_hero = new sf::Sprite();
		m_hero->setTexture(m_texture);
		m_hero->setOrigin((m_r_x / 2), (m_r_y / 2));
		m_hero->setPosition(m_x, m_y);
		return true;
	}

	Hero::~Hero() 
	{  
		if (m_hero != nullptr)
			delete m_hero;
	}

	sf::Sprite* Hero::GetH() { return m_hero; }

	int Hero::GetY() { return m_y; }
}