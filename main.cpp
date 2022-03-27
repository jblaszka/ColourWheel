#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "SliderTest.h"
#include "RBG.h"
#include "HSV.h"
#include "HSL.h"
#include "CMY.h"
#include <SFML/Window.hpp>
#include "drawCircle.h"

int main()
{
    sf::Clock clock;
    sf::Time time = sf::Time::Zero;
    unsigned int FPS = 0, frame_counter = 0;
    sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close);
    //inicjalizacja 
    clock.restart().asMilliseconds();
    sf::Vector2f MousePosition;
    bool click = false;

    //moje zmienne
    sf::Color color(212, 184, 249, 255);
    //do hsv
    float angle = 0;
    vector<HSV> circleHSV;
    int stala = 0;
    double pasekW = 0;
    

    //do hsl
    vector<HSL> circleHSL;

    //Zmienne kolory
    sf::Color testKolor;
    sf::Color testKolor2;
    sf::Color testKolor3;
    sf::Color testKolor4;



    //zmienne od Dawida
    int niebieski = 0;
    RBG rbg(200.f, 150.f);
    vector<RBG> linie;
    float a = 200.f;
    float b = 150.f;
    float x = 600.f;
    float g = 0;
    float c = 0;

    //zmienne do CMY
    float srodekX4 = 500.f;
    float srodekY4 = 150.f;
    CMY cmy(srodekX4,srodekY4);
    vector<CMY> ciercleCMY;
    float rosnaca = 0;
    float angleCMY = 0;

    Sliderek sliderTest;
    DrawCircle circleTest;

    circleTest.makeHSL(500.f, 450.f);
    circleHSL = circleTest.oddajeHSL();
    vector<int> colors = circleTest.oddajeKolor();

    circleTest.makeHSV(200.f, 450.f);
    circleHSV = circleTest.oddajeHSV();
    vector<int> colors2 = circleTest.oddajeKolorHSV();



    while (window.isOpen())
    {
        MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        sf::Event event;
        //window.clear(sf::Color::White);
       

        while (c < 360) {
            rbg.change_color(g);
            rbg.change_position(a, b, c);
            linie.push_back(rbg);
            c = c + (360. / 1022.);

            rbg.change_position(a, b, c);
            linie.push_back(rbg);
            c = c + (360. / 1022.);

            rbg.change_position(a, b, c);
            linie.push_back(rbg);
            c = c + (360. / 1022.);

            rbg.change_position(a, b, c);
            linie.push_back(rbg);
            c = c + (360. / 1022.);
            g++;
        }

        while (angleCMY < 360) {
            cmy.change_color(rosnaca);
            cmy.change_position(srodekX4, srodekY4, angleCMY);
            ciercleCMY.push_back(cmy);
            angleCMY = angleCMY + (360. / 1022.);

            cmy.change_position(srodekX4, srodekY4, angleCMY);
            ciercleCMY.push_back(cmy);
            angleCMY = angleCMY + (360. / 1022.);

            cmy.change_position(srodekX4, srodekY4, angleCMY);
            ciercleCMY.push_back(cmy);
            angleCMY = angleCMY + (360. / 1022.);

            cmy.change_position(srodekX4, srodekY4, angleCMY);
            ciercleCMY.push_back(cmy);
            angleCMY = angleCMY + (360. / 1022.);
            rosnaca++;
        }
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: window.close(); break;

            case sf::Event::MouseButtonPressed:
                click = true;
                break;


            case sf::Event::MouseMoved:
                if (click) {
                    sliderTest.position(MousePosition.x, MousePosition.y);
                    for (int i = 0; i < 1022; i++) {
                        linie[i].change_blue(sliderTest.returnPosition());
                        ciercleCMY[i].change_y(255-sliderTest.returnPosition());
                    }

                    for (int k = 0; k < 1440; k++) {
                        pasekW = (sliderTest.returnPosition() / 255.);
                        testKolor = circleHSL[k].HSLtoRGB(colors[k], 1., pasekW);
                        testKolor2 = circleHSL[k].HSLtoRGB(0, 0., pasekW);
                        circleHSL[k].change_color(testKolor);
                        circleHSL[k].change_color_Y(testKolor2);
                    }

                    for (int k = 0; k < 1440; k++) {
                        pasekW = (sliderTest.returnPosition() / 255.);
                        testKolor3 = circleHSV[k].zmiana(colors2[k], 1., pasekW);
                        testKolor4 = circleHSV[k].zmiana(0, 0., pasekW);
                        circleHSV[k].change_color(testKolor3);
                        circleHSV[k].change_color_Y(testKolor4);
                    }

                }
                break;

            case sf::Event::MouseButtonReleased:
                click = false;
                break;
            }
        }
        //tu wyrysowaæ wszystko na ekran

        //tu wypisaæ na ekran wartoœæ FPS
        if (clock.getElapsedTime().asSeconds() >= 1.0f)
        {
            FPS = (unsigned int)((float)frame_counter / clock.getElapsedTime().asSeconds());
            clock.restart();
            frame_counter = 0;
        }
        frame_counter++;
        
        sliderTest.setFPS(FPS);


        window.clear(sf::Color(247, 235, 247));
        window.draw(sliderTest);

        for (vector <RBG> ::iterator it = linie.begin(); it != linie.end(); ++it) {
            window.draw(*it);
        }

        for (vector <HSV> ::iterator it = circleHSV.begin(); it != circleHSV.end(); ++it) {
            window.draw(*it);
        }

        for (vector <HSL> ::iterator it = circleHSL.begin(); it != circleHSL.end(); ++it) {
            window.draw(*it);
        }

        for (vector <CMY> ::iterator it = ciercleCMY.begin(); it != ciercleCMY.end(); ++it) {
            window.draw(*it);
        }
        
        window.display();
    }
}