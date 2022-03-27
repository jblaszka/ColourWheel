#include "RBG.h"
#include "math.h"
using namespace sf;
using namespace std;
RBG::RBG(float a, float b) {
	point = VertexArray(Lines, 2);
	point[0].position = sf::Vector2f(a, b);
	point[1].position = sf::Vector2f(a, b);
	point[0].color = sf::Color(0, 0, 241);
	point[1].color = sf::Color(255, 0, 241);
}
void RBG::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->point, state);
}
void RBG::change_position(float a, float b, float c) {// , float c, float d) {
	float PI = 3.141592;
	point[0].position = sf::Vector2f(a, b);
	point[1].position = sf::Vector2f(a + 100 * sin(c * PI / 180), b + 100 * cos(c * PI / 180));
}

void RBG::change_color(int b) {// , float c, float d) {
	point[0].color = sf::Color(0, b, 241);
	point[1].color = sf::Color(255, b, 241);
	int a = point[0].color.r;
}
void RBG::change_blue(int niebieski) {// , float c, float d) {
	point[0].color.b = niebieski;
	point[1].color.b = niebieski;
}
