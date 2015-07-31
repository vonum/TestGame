#ifndef _CHASER_
#define _CHASER_

#include <cmath>
#include "player.hpp"

class Chaser
{
    private:

        sf::CircleShape body;


    public:

        Chaser(int x, int y) { body.setFillColor(sf::Color::Cyan); body.setRadius(25); body.setPosition(x*750, y*550);  }
        sf::CircleShape getShape() { return body; }
        void movement(Player& pl)
        {
            float x = body.getPosition().x;
            float y = body.getPosition().y;

            float alpha = atan2(pl.plPos().y - body.getPosition().y, pl.plPos().x - body.getPosition().x);

            x += cos(alpha)*0.03;
            y += sin(alpha)*0.03;

            body.setPosition(x, y);

        }

        bool colWithPlayer(Player& pl1)
        {
            if(pl1.plPos().x < body.getPosition().x - 100)
                return false;
            if(pl1.plPos().x > body.getPosition().x + 50)
                return false;
            if(pl1.plPos().y < body.getPosition().y - 100)
                return false;
            if(pl1.plPos().y > body.getPosition().y + 50)
                return false;
            return true;
        }


};

#endif // _CHASER_
