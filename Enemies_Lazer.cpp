#include "Enemies_Lazer.hpp"
#include <iostream>

namespace el
{
	Enemies_Lazer::Enemies_Lazer(int x, int y, float r_x, float r_y, float velocity)
	{
		m_x = x;
		m_y = y;
		m_r_x = r_x;
		m_r_y = r_y;
		m_velocity = velocity;
	}

	bool Enemies_Lazer::Setup()
	{
		if (!m_texture.loadFromFile("Textures/Enemy_lazer.png"))
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
	
	void Enemies_Lazer::Move()
	{
		m_y += m_velocity;
		m_lazer->setPosition(m_x, m_y);

	}

	int Enemies_Lazer::GetY() { return m_y; }

	void Enemies_Lazer::SetY(int y)
	{
		m_y = y;
		m_lazer->setPosition(m_x, m_y);
	}

	sf::Sprite* Enemies_Lazer::GetEL() { return m_lazer; }

	Enemies_Lazer::~Enemies_Lazer() { delete m_lazer; }
}