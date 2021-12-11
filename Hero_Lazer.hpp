#pragma once
#include <SFML/Graphics.hpp>

namespace hl
{
	class Hero_Lazer
	{
		int m_x, m_y;
		float m_r_x, m_r_y, m_velocity;
		sf::Texture m_texture;
		sf::Sprite* m_lazer;

	public:
		Hero_Lazer(int x, int y, float r_x, float r_y, float velocity);

		bool Setup();

		void Move();

		int GetY();

		void Set(int x, int y);

		sf::Sprite* GetHL();

		~Hero_Lazer();
	};
}
