#pragma once
#include <SFML/Graphics.hpp>

namespace he
{
	class Hero
	{
		int m_x, m_y;
		float m_r_x, m_r_y;
		sf::Texture m_texture;
		sf::Sprite* m_hero;

	public:
		Hero(int x, int y, float r_x, float r_y);

		bool Setup();

		~Hero();

		sf::Sprite* GetH();

		int GetY();

		int GetX();

		void SetX(int x);

		void SetY(int y);

		void Move(float x, float y);
	};

}