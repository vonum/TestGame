#ifndef _PLAYER_
#define _PLAYER_

#include "environment.hpp"
//#include "chaser.hpp"

enum State {MOVE_L, MOVE_R, JUMP, MOVE_U, MOVE_D, STAND };

class Player
{

    private:

        int health;
        sf::CircleShape circle;
        int id;
        State state;
        bool dead;
        float prev_pos;

        void moveLeft(){ circle.move(-0.1, 0); }
        void moveRight() { circle.move(0.1, 0); }
        void moveUp() { circle.move(0, -0.1); }
        void moveDown() { circle.move(0, 0.1); }

    public:

        Player() { circle.setRadius(50); circle.setPosition(0, 500); circle.setFillColor(sf::Color::Blue); state = STAND; health = 5; dead = false;}
        Player(int i) { circle.setRadius(50); circle.setPosition(0, 500); circle.setFillColor(sf::Color::Yellow); state = STAND; health = 5; }

        sf::Vector2f plPos() { return circle.getPosition(); }
        void colWithField()
        {
            if(circle.getPosition().x <= 0)
                circle.setPosition(0, circle.getPosition().y);
            if(circle.getPosition().x >= 700)
                circle.setPosition(700, circle.getPosition().y);
            if(circle.getPosition().y <= 0)
                circle.setPosition(circle.getPosition().x, 0);
            if(circle.getPosition().y >= 500)
                circle.setPosition(circle.getPosition().x, 500);

        }
        void killPlayer() { dead = true; }
        bool isDead() { return dead; }
        void gravity() { circle.move(0, 0.01); }
        void setState(int id)
        {
            switch(id)
            {
                case 0  :   state = STAND;
                            break;

                case 1  :   state = MOVE_L;
                            break;

                case 2  :   state = MOVE_R;
                            break;

                case 3  :   state = MOVE_D;
                            break;

                case 4  :   state = MOVE_U;
                            break;

                default :   break;


            }
        }
        bool colWithGoal(Environment& env)
        {
            if(circle.getPosition().x < env.goalPos().x - 100)
                return false;
            if(circle.getPosition().x > env.goalPos().x + 20)
                return false;
            if(circle.getPosition().y > env.goalPos().y + 20)
                return false;
            if(circle.getPosition().y < env.goalPos().y - 100)
                return false;
            return true;

        }

        void movement()
        {
            switch(getState())
            {
                case MOVE_L :   moveLeft();
                                break;

                case MOVE_R :   moveRight();
                                break;

                case MOVE_D :   moveDown();
                                break;

                case MOVE_U :   moveUp();
                                break;

                default :   break;
            }
        }


        State getState() { return state; }
        sf::CircleShape getShape() { return circle; }

};

#endif // _PLAYER_
