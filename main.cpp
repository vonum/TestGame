#include <SFML/Graphics.hpp>
#include <iostream>
#include "screen.hpp"
#include "player.hpp"
#include "eventHandling.hpp"
#include "environment.hpp"
#include "chaser.hpp"
#include "game.hpp"
#include "text.hpp"
#include <string>
#include "clock.hpp"

int main()
{
    /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }*/

    Screen scr;
    Player pl1, pl2(1);
    Environment env;
    Chaser ch1(0,0),ch2(1,1);
    Clock clk;
    clk.restart();
    sf::Time t1;


    while(scr.sIsOpen())
    {

        sf::Event event;

            while(scr.sPollEvent(event))
            {
                eventHandling(event, pl1, pl2, scr);

            }


        game(scr, pl1, pl2, ch1, ch2, env);
        t1 = clk.getTime();
        //std::cout << t1.asSeconds() << std::endl;
        if(t1.asSeconds() >= 5)
        {
             std::cout << "pls";
             scr.sRotate();
             clk.restart();
        }
    }

    return 0;
}
