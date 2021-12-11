#pragma once
#include <SFML/Graphics.hpp>

namespace en
{
	class Enemies
	{
		int m_x, m_y;
		float m_r, m_velocity;
		sf::Texture m_texture;
		sf::Sprite* m_enemy;

	public:
		Enemies(int x, int y, float r, float velocity);

		bool Setup();

		~Enemies();

		sf::Sprite* GetE();

		//Установка значения скорости
		void SetVelocity(int velocity);

		//Движение
		void Move();

		void SetY(int y);

		int GetY();

		int GetX();
		
	};


}