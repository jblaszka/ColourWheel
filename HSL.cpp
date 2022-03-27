#include "HSL.h"
#include "math.h"
#include <iostream>
#include "CMY.h"

using namespace std;

using namespace sf;
using namespace std;
HSL::HSL(float a, float b) {
	point = VertexArray(Lines, 2);
	point[0].position = sf::Vector2f(a, b);
	point[1].position = sf::Vector2f(a, b);
	point[0].color = sf::Color(255, 255, 255);
	point[1].color = sf::Color(255, 0, 241);
}

Color HSL::HSLtoRGB(int h, double s, double l){
    double hp = h / 60.0;
    double c = (1 - std::abs(2*l - 1))*s;
    double x = c * (1 - std::abs(std::fmod(hp, 2) - 1));
    double m = l - (c/2);
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

    //cout << "KOLOR R    "<< r * 255 << endl;
    //cout << "KOlOR G    "<<  g * 255 << endl;
    //cout << "KOLOR B    "<< b * 255 << endl;
    return  Color(r * 255, g * 255, b * 255);
}

Vector3f HSL::RGBtoHSL(int rr, int gg, int bb) {

    double hue, sat;

    double maxval, minval;
    Vector3f hsl;

    double R = rr / 255.0;
    double G = gg / 255.0;
    double B = bb / 255.0;


    minval = min(R, G);
    minval = min(minval, B);   //Min. value of RGB
    maxval = max(R, G);
    maxval = max(maxval, B);

    double difference = maxval - minval;

    double lumi = (minval + maxval) / 2;
    hsl.z = lumi;

    //cout << hsl.z << endl;
    if (difference == 0) {
        sat = 0;
        hue = 0;
    }

    if (lumi <= 0.5) {
        sat = (maxval - minval) / (maxval + minval);
    }

    if (lumi > 0.5) {
        sat = (maxval - minval) / (2-maxval + minval);
    }

    if (maxval == R) {
        hue = (G - B) / (maxval - minval);
    }
    if (maxval == G) {
        hue = 2 +(( B - R) / (maxval - minval));
    }
    if (maxval == B) {
        hue = (4+ ( R - G) / (maxval - minval));

    }
    int liczbaX, liczbaY, liczbaZ;
    hue = hue * 60;
    hsl.x = hue;
    hsl.y = sat;
    
    //cout << "ZMIANA" << endl;
    //cout << hsl.x << endl;
    //cout << hsl.y << endl;
    //cout << hsl.z << endl;

    return(hsl);

}


void HSL::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->point, state);
}

void HSL::change_position(float a, float b, float c) {// , float c, float d) {
	float PI = 3.141592;
	point[0].position = sf::Vector2f(a, b);
	point[1].position = sf::Vector2f(a + 100 * sin(c * PI / 180), b + 100 * cos(c * PI / 180));
}

void HSL::change_color(Color color) {// , float c, float d) {
	//point[0].color = sf::Color(255, 255, 255);
	point[1].color = color;
}

void HSL::change_color_Y(Color color) {
    point[0].color = color;
}
