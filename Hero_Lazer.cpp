#include "Hero_Lazer.hpp"
#include <iostream>

namespace hl
{
	Hero_Lazer::Hero_Lazer(int x, int y, float r_x, float r_y, float velocity)
	{
		m_x = x;
		m_y = y;
		m_r_x = r_x;
		m_r_y = r_y;
		m_velocity = velocity;
	}

	bool Hero_Lazer::Setup()
	{
		if (!m_texture.loadFromFile("Textures/Hero_lazer.png"))
		{
			std::cout << "Error with hero_lazer's texture!!!" << std::endl;
			return false;
		}
		m_lazer = new sf::Sprite();
		m_lazer->setTexture(m_texture);
		m_lazer->setOrigin((m_r_x / 2), (m_r_y / 2));
		m_lazer->setPosition(m_x, m_y);
		return true;
	}

	void Hero_Lazer::Move()
	{
		m_y -= m_velocity;
		m_lazer->setPosition(m_x, m_y);
	}

	int Hero_Lazer::GetY() { return m_y; }

	void Hero_Lazer::Set(int x, int y)
	{
		m_x = x;
		m_y = y;
		m_lazer->setPosition(m_x, m_y);
	}

	int Hero_Lazer::GetX() { return m_x; }

	float Hero_Lazer::GetL() { return m_r_x; }

	sf::Sprite* Hero_Lazer::GetHL() { return m_lazer; }

	Hero_Lazer::~Hero_Lazer()
	{
		if (m_lazer != nullptr)
			delete m_lazer;
	}
}