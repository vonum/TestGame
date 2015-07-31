#ifndef _EVENTS_
#define _EVENTS_


void eventHandling(sf::Event& event,Player& pl1, Player& pl2, Screen& scr)
{


    if(event.type == sf::Event::Closed)
        scr.sClose();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        scr.sClose();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            //pl1.moveLeft();
            pl1.setState(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            //pl1.moveRight();
            pl1.setState(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            //pl1.moveDown();
            pl1.setState(3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            //pl1.moveUp();
            pl1.setState(4);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            //pl1.moveLeft();
            pl2.setState(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            //pl1.moveRight();
            pl2.setState(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            //pl1.moveDown();
            pl2.setState(3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            //pl1.moveUp();
            pl2.setState(4);
}








#endif // _EVENTS_
