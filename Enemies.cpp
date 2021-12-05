#include "Enemies.hpp"

namespace en
{
	Enemies::Enemies(int x, int y, float r, float velocity)
	{
		m_x = x;
		m_y = y;
		m_r = r;
		m_velocity = velocity;
		m_enemy = new sf::CircleShape(m_r);
		m_enemy->setOrigin(m_r, m_r);
		m_enemy->setPosition((m_x - m_r), (m_y + m_r));
		//Color
		m_enemy->setFillColor(sf::Color::White);
	}

	Enemies::~Enemies() { delete m_enemy; }

	sf::CircleShape* Enemies::GetE() { return m_enemy; }

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
}