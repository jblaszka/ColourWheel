#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class CMY : public sf::Drawable
{
public:
	CMY(float a, float b);
	CMY() = delete;
	~CMY() = default;
	void change_position(float a, float b, float c);
	void change_color(int b);
	void change_y(int y);
private:
	VertexArray point;
	void draw(RenderTarget& target, RenderStates state) const override;
};


