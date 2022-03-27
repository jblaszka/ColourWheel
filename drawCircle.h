#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "HSL.h"
#include "HSV.h"
#include "SliderTest.h"
using namespace sf;
using namespace std;


class DrawCircle
{
	public:

		void makeHSL(float srodekX, float srodekY)
		{
            float angle2 = 0;
            int stala2 = 0;
            while (angle2 < 360) {
                sf::Color colorHSL = hslCircle.HSLtoRGB(stala2, 1, 0.5);
                hslCircle.change_color(colorHSL);

                hslCircle.change_position(srodekX, srodekY, angle2);
                circleHSL.push_back(hslCircle);
                colorX.push_back(stala2);
                angle2 = angle2 + 0.25;

                hslCircle.change_position(srodekX, srodekY, angle2);
                circleHSL.push_back(hslCircle);
                colorX.push_back(stala2);
                angle2 = angle2 + 0.25;

                hslCircle.change_position(srodekX, srodekY, angle2);
                circleHSL.push_back(hslCircle);
                colorX.push_back(stala2);
                angle2 = angle2 + 0.25;

                hslCircle.change_position(srodekX, srodekY, angle2);
                circleHSL.push_back(hslCircle);
                colorX.push_back(stala2);
                angle2 = angle2 + 0.25;
                stala2++;
            }
		}

        vector <HSL> oddajeHSL() {
            return circleHSL;
        }

        vector <int> oddajeKolor() {
            return colorX;
        }

        void makeHSV(float srodekX, float srodekY)
        {
            float angle2 = 0;
            int stala2 = 0;
            while (angle2 < 360) {
                sf::Color colorHSV = hsvCircle.zmiana(stala2, 1.0, 1.0);
                hsvCircle.change_color(colorHSV);

                hsvCircle.change_position(srodekX, srodekY, angle2);
                circleHSV.push_back(hsvCircle);
                colorX2.push_back(stala2);
                angle2 = angle2 + 0.25;

                hsvCircle.change_position(srodekX, srodekY, angle2);
                circleHSV.push_back(hsvCircle);
                colorX2.push_back(stala2);
                angle2 = angle2 + 0.25;

                hsvCircle.change_position(srodekX, srodekY, angle2);
                circleHSV.push_back(hsvCircle);
                colorX2.push_back(stala2);
                angle2 = angle2 + 0.25;

                hsvCircle.change_position(srodekX, srodekY, angle2);
                circleHSV.push_back(hsvCircle);
                colorX2.push_back(stala2);
                angle2 = angle2 + 0.25;
                stala2++;
            }
        }

        vector <HSV> oddajeHSV() {
            return circleHSV;
        }

        vector <int> oddajeKolorHSV() {
            return colorX2;
        }



private:
	vector<HSL> circleHSL;
    HSL hslCircle = HSL(500.f, 450.f);
    sf::Color color;
    Vector3f test;
    vector<int> colorX;

    vector<HSV> circleHSV;
    HSV hsvCircle = HSV(500.f, 450.f);
    sf::Color color2;
    Vector3f test2;
    vector<int> colorX2;

};