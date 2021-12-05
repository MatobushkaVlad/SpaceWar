#pragma once
#include <SFML/Graphics.hpp>

namespace en
{
	class Enemies
	{
		int m_x, m_y;
		float m_r, m_velocity;
		sf::CircleShape* m_enemy;

	public:
		Enemies(int x, int y, float r, float velocity);

		~Enemies();

		sf::CircleShape* GetE();

		//��������� �������� ��������
		void SetVelocity(int velocity);

		//��������
		void Move();

		void SetY(int y);

		int GetY();
		
	};


}