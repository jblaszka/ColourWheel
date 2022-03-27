#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class HSV : public sf::Drawable
{
public:
	HSV(float a, float b);
	HSV() = delete;
	~HSV() = default;
	void change_position(float a, float b, float c);
	void change_color(Color color);
	void change_v(int niebieski);
	Color zmiana(int h, double s, double v);
	Vector3f powrot(int r, int g, int b);
	Color returnColor(int x) { return point[x].color; }
	void change_color_Y(Color color);

private:
	VertexArray point;
	void draw(RenderTarget& target, RenderStates state) const override;
};


