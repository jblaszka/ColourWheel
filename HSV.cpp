#include "HSV.h"
#include "math.h"
#include <iostream>

using namespace sf;
using namespace std;

HSV::HSV(float a, float b) {
	point = VertexArray(Lines, 2);
	point[0].position = sf::Vector2f(a, b);
	point[1].position = sf::Vector2f(a, b);
	point[0].color = sf::Color(0, 0, 241);
	point[1].color = sf::Color(255, 0, 241);
}

Color HSV::zmiana(int h, double s, double v) {
    double hp = h / 60.0;
    double c = s * v;
    double x = c * (1 - std::abs(std::fmod(hp, 2) - 1));
    double m = v - c;
    double r = 0, g = 0, b = 0;
    if (hp <= 1) {
        r = c;
        g = x;
    }
    else if (hp <= 2) {
        r = x;
        g = c;
    }
    else if (hp <= 3) {
        g = c;
        b = x;
    }
    else if (hp <= 4) {
        g = x;
        b = c;
    }
    else if (hp <= 5) {
        r = x;
        b = c;
    }
    else {
        r = c;
        b = x;
    }
    r += m;
    g += m;
    b += m;
    return  Color (r * 255, g * 255, b * 255);
}

Vector3f HSV::powrot(int rr, int gg, int bb) {

    double hue, sat;

    double maxval, minval;
    Vector3f hsv;

    double R = rr / 255.0;
    double G = gg / 255.0;
    double B = bb / 255.0;


    minval = min(R, G);
    minval = min(minval, B);   //Min. value of RGB
    maxval = max(R, G);
    maxval = max(maxval, B);
    double difference = maxval - minval;

    double red, green, blue;
    red = R;
    green = G;
    blue = B;


    if (difference == 0) {
        hue = 0;
    }
    else if (red == maxval) {
        hue = fmod(((60 * ((green - blue) / difference)) + 360), 360.0);
    }
    else if (green = maxval) {
        hue = fmod(((60 * ((blue - red) / difference)) + 120), 360.0);
    }
    else if (blue = maxval) {
        hue = fmod(((60 * ((red - green) / difference)) + 240), 360.0);
        
    }
    if (maxval == 0) {
        sat = 0;
    }
    else {
        sat = 100 * (difference / maxval);
    }
    hsv.x = (hue);
    hsv.y = (sat);
    hsv.z = (maxval * 100);
    return(hsv);

}

void HSV::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->point, state);
}

void HSV::change_position(float a, float b, float c) {// , float c, float d) {
	float PI = 3.141592;
	point[0].position = sf::Vector2f(a, b);
	point[1].position = sf::Vector2f(a + 100 * sin(c * PI / 180), b + 100 * cos(c * PI / 180));
}

void HSV::change_color(Color color) {// , float c, float d) {
	point[0].color = sf::Color(255, 255, 255);
	point[1].color = color;
}
void HSV::change_v(int v) {// , float c, float d) {
	//point[0].color.b = v;
	point[1].color.b = v;
}

void HSV::change_color_Y(Color color) {
    point[0].color = color;
}





