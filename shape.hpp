#pragma once
#include <SFML/Graphics.hpp>

namespace kr
{
	class Rectangle 
	{
	public:
		Rectangle(int x, int y, int m_w, int m_h, float velocity);

		//деструктор
		~Rectangle();

		sf::RectangleShape* Get();


		void Move();

		void SetY(int y);

		int GetY();

		void SetVelocity(int velocity);

		void Stop();

	private:
		int m_x, m_y, m_w, m_h;
		float m_velocity;
		sf::RectangleShape* m_rectangle;
	};

}