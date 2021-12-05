#pragma once
#include <SFML/Graphics.hpp>

namespace he
{
	class Hero
	{
		int m_x, m_y;
		float m_r_x, m_r_y;
		sf::RectangleShape* m_hero;

	public:
		Hero(int x, int y, float r_x, float r_y);

		~Hero();

		sf::RectangleShape* GetH();
	};


}