#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "font.h"


class Sliderek : public sf::Drawable
{
public:
	Sliderek()
	{	
		//font do pisania
		font.loadFromMemory(font_data, font_data_size);
		text = new sf::Text;
		text->setFont(font);
		text->setCharacterSize(14);
		text->setFillColor(sf::Color::Black);
		

		//suwak jego wyglad
		vertices = new sf::VertexArray(sf::Quads, 4);

		(*vertices)[0].position = sf::Vector2f(735.f, 10.f);
		(*vertices)[1].position = sf::Vector2f(780.f, 10.f);
		(*vertices)[2].position = sf::Vector2f(780.f, 265.f);
		(*vertices)[3].position = sf::Vector2f(735.f, 265.f);

		(*vertices)[0].color = sf::Color::Black;
		(*vertices)[1].color = sf::Color::Black;
		(*vertices)[2].color = sf::Color::White;
		(*vertices)[3].color = sf::Color::White;

		//ramka
		ramka = new sf::VertexArray(sf::Quads, 4);

		(*ramka)[0].position = sf::Vector2f(733.f, 8.f);
		(*ramka)[1].position = sf::Vector2f(782.f, 8.f);
		(*ramka)[2].position = sf::Vector2f(782.f, 267.f);
		(*ramka)[3].position = sf::Vector2f(733.f, 267.f);

		(*ramka)[0].color = sf::Color::Red;
		(*ramka)[1].color = sf::Color::Red;
		(*ramka)[2].color = sf::Color::Red;
		(*ramka)[3].color = sf::Color::Red;



		//przesuwacz 
		line = new sf::VertexArray(sf::Lines, 2);

		(*line)[0].position = sf::Vector2f(735.f, 50.f);
		(*line)[1].position = sf::Vector2f(780.f, 50.f);

		(*line)[0].color = sf::Color::Red;
		(*line)[1].color = sf::Color::Red;
	}

	void position(float x, float y) {
		if (x > 735 || x < 280) {
			if (y > 265)
			{
				y = 265;
				(*line)[0].position = sf::Vector2f(735.f, y);
				(*line)[1].position = sf::Vector2f(780.f, y);
			}
			else if (y < 10)
			{
				y = 10;
				(*line)[0].position = sf::Vector2f(735.f, y);
				(*line)[1].position = sf::Vector2f(780.f, y);
			}
			else {
				(*line)[0].position = sf::Vector2f(735.f, y);
				(*line)[1].position = sf::Vector2f(780.f, y);
			}
		}
	}

	float returnPosition() {
		return ((*line)[1].position.y-10);
	}

	void outtextxy(sf::RenderTarget& target, float x, float y, const std::string& str) const
	{
		text->setPosition(x, y);
		text->setString(str);
		target.draw(*text);
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		outtextxy(target, 735, 300, m_fps + " FPS");

		target.draw(*ramka);
		target.draw(*vertices);
		target.draw(*line);
	}

	void setFPS(unsigned int& fps) {
		m_fps = std::to_string(fps);
	}


private:
	sf::Font font;
	sf::Text* text;
	sf::VertexArray* vertices;
	sf::VertexArray* line;
	sf::VertexArray* ramka;
	std::string m_fps;
};