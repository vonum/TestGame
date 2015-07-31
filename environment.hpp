#ifndef _ENV_
#define _ENV_

class Environment
{

    private:

        sf::RectangleShape obstacle[5];
        sf::CircleShape goal;


    public:

        Environment()
        {
             goal.setFillColor(sf::Color::Red);
             goal.setRadius(10);
             goal.setPosition(rand()%801, rand()%601);
        }
        void spawn() { goal.setPosition(rand()%801, rand()%601); }
        sf::CircleShape drawGoal() { return goal; }
        sf::RectangleShape* drawObstacles() { return obstacle; }
        sf::Vector2f goalPos() { return goal.getPosition(); }


};










#endif // _ENV_
