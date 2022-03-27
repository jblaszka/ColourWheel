#pragma once
#include <SFML/Graphics.hpp>
#include "CMY.h"
using namespace sf;
using namespace std;
class HSL : public sf::Drawable
{
public:
	HSL(float a, float b);
	HSL() = delete;
	~HSL() = default;
	void change_position(float a, float b, float c);
	void change_color(Color color);
	void change_color_Y(Color color);
	Color HSLtoRGB(int h, double s, double l);
	Vector3f RGBtoHSL(int r, int g, int b);
	Color returnColor(int x) { return point[x].color; }

private:
	VertexArray point;
	void draw(RenderTarget& target, RenderStates state) const override;
};


