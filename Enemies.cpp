#include "Enemies.hpp"
#include <iostream>

namespace en
{
	Enemies::Enemies(int x, int y, float r, float velocity)
	{
		m_x = x;
		m_y = y;
		m_r = r;
		m_velocity = velocity;
	}

	bool Enemies::Setup()
	{
		if (!m_texture.loadFromFile("Textures/Enemies_texture.png"))
		{
			std::cout << "Error with enemies's texture!!!" << std::endl;
			return false;
		}
		m_enemy = new sf::Sprite();
		m_enemy->setTexture(m_texture);
		m_enemy->setOrigin(m_r, m_r);
		m_enemy->setPosition((m_x - m_r), (m_y + m_r));
		return true;
	}

	Enemies::~Enemies() { delete m_enemy; }

	sf::Sprite* Enemies::GetE() { return m_enemy; }

	void Enemies::SetVelocity(int velocity)
	{
		m_velocity = velocity;
	}

	void Enemies::Move()
	{
		m_y += m_velocity;
		m_enemy->setPosition(m_x, m_y);
	}

	void Enemies::SetY(int y)
	{
		m_y = y;
		m_enemy->setPosition(m_x, m_y);
	}

	int Enemies::GetY() { return m_y; }

	int Enemies::GetX() { return m_x; }
}