#ifndef _SCREEN_
#define _SCREEN_

#include "chaser.hpp"

enum Gamestate { MENU, PAUSE, IN_GAME };

class Screen
{

    private:

        Gamestate gamestate;
        sf::RenderWindow window;
        sf::Texture background;
        sf::Sprite b_sprite;


    public:

        Screen()
        {
            background.loadFromFile("background.jpg");
            b_sprite.setTexture(background);
            window.create(sf::VideoMode(800,600),"Bullshit Game");
        }

        void sRotate() { sf::View view = window.getView(); view.rotate(30); window.setView(view); }

        void sClear() { window.clear(); }
        bool sIsOpen() { window.isOpen(); }
        void sDisplay() { window.display(); }
        void sDrawBackground() { window.draw(b_sprite); }

        void sDraw(sf::CircleShape shape) { window.draw(shape); }
        void sDraw(sf::Text& txt) { window.draw(txt); }
        bool sPollEvent(sf::Event& event) { window.pollEvent(event); }
        void sClose() { window.close(); }

};


#endif // _SCREEN_
