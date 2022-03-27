#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class RBG : public sf::Drawable
{
public:
	RBG(float a, float b);
	RBG() = delete;
	~RBG() = default;
	void change_position(float a, float b, float c);
	void change_color(int b);
	void change_blue(int niebieski);
private:
	VertexArray point;
	void draw(RenderTarget& target, RenderStates state) const override;
};


