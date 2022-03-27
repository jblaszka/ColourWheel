#include "CMY.h"
#include "math.h"
using namespace sf;
using namespace std;
CMY::CMY(float a, float b) {
	point = VertexArray(Lines, 2);
	point[0].position = sf::Vector2f(a, b);
	point[1].position = sf::Vector2f(a, b);
	point[0].color = sf::Color(0, 0, 100);
	point[1].color = sf::Color(255, 0, 110);
}
void CMY::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->point, state);
}
void CMY::change_position(float a, float b, float c) {// , float c, float d) {
	float PI = 3.141592;
	point[0].position = sf::Vector2f(a, b);
	point[1].position = sf::Vector2f(a + 100 * sin(c * PI / 180), b + 100 * cos(c * PI / 180));
}

void CMY::change_color(int b) {// , float c, float d) {
	point[0].color = sf::Color(255, b, 0);
	point[1].color = sf::Color(0, b, 0);
}

void CMY::change_y(int y) {// , float c, float d) {
	point[0].color.b = y;
	point[1].color.b = y;
}
