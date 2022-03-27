#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Slider1.h"
#include <vector>
#include "SliderTest.h"
#include <iostream>
#include "RBG.h"
#include "HSV.h"

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
    window.setFramerateLimit(60);
    int angle = 0;
    vector<HSV> circleHSV;
    HSV hsv(400.f, 400.f);
    float srodekX = 400.f;
    float srodekY = 400.f;

    //zmienne od Dawida
    int niebieski = 0;
    RBG rbg(200.f, 150.f);
    vector<RBG> linie;
    float a = 200.f;
    float b = 150.f;
    float x = 600.f;
    float g = 0;
    float c = 0;
    float d = 0;
    float h = 0;


    Sliderek sliderTest;

    while (window.isOpen())
    {
        MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        sf::Event event;
        //window.clear(sf::Color::White);


        while (c < 360) {
            rbg.change_color(g);
            rbg.change_position(a, b, c);
            linie.push_back(rbg);
            c = c + (360. / 1028.);

            rbg.change_position(a, b, c);
            linie.push_back(rbg);
            c = c + (360. / 1028.);

            rbg.change_position(a, b, c);
            linie.push_back(rbg);
            c = c + (360. / 1028.);

            rbg.change_position(a, b, c);
            linie.push_back(rbg);
            c = c + (360. / 1028.);
            g++;

        }


        while (angle < 360) {
            color = hsv.zmiana(angle, 1.0, 1.0);
            hsv.change_color(color);

            hsv.change_position(srodekX, srodekY, angle);
            circleHSV.push_back(hsv);
            angle = angle + (360. / 2048.);

            hsv.change_position(srodekX, srodekY, angle);
            circleHSV.push_back(hsv);
            angle = angle + (360. / 2048.);

            hsv.change_position(srodekX, srodekY, angle);
            circleHSV.push_back(hsv);
            angle = angle + (360. / 2048.);

            hsv.change_position(srodekX, srodekY, angle);
            circleHSV.push_back(hsv);
            angle = angle + (360. / 2048.);

            hsv.change_position(srodekX, srodekY, angle);
            circleHSV.push_back(hsv);
            angle = angle + (360. / 2048.);

            hsv.change_position(srodekX, srodekY, angle);
            circleHSV.push_back(hsv);
            angle = angle + (360. / 2048.);

            hsv.change_position(srodekX, srodekY, angle);
            circleHSV.push_back(hsv);
            angle = angle + (360. / 2048.);

            hsv.change_position(srodekX, srodekY, angle);
            circleHSV.push_back(hsv);
            angle = angle + (360. / 2048.);

            angle++;

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
                    std::cout << sliderTest.returnPosition() << std::endl;
                    for (int i = 0; i < 1028; i++) {
                        linie[i].change_blue(sliderTest.returnPosition());
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

        //window.draw(slider);

        window.clear(sf::Color(247, 235, 247));
        window.draw(sliderTest);

        for (vector <RBG> ::iterator it = linie.begin(); it != linie.end(); ++it) {
            window.draw(*it);
        }

        for (vector <HSV> ::iterator it = circleHSV.begin(); it != circleHSV.end(); ++it) {
            window.draw(*it);
        }

        window.display();
    }
}