#ifndef _TEXT_
#define _TEXT_

#include <string>

class Text
{

    private:

        sf::Text txt;
        sf::Font font;

    public:

        Text(sf::String str)
        {
            txt.setString(str);
            txt.setCharacterSize(50);
            txt.setColor(sf::Color::Red);
            txt.setPosition(500, 500);
            txt.setStyle(sf::Text::Bold);
            font.loadFromFile("Calibri.ttf");
            txt.setFont(font);
        }
        void setText(sf::String& str) { txt.setString(str); }
        sf::Text& getText() { return txt; }

};








#endif // _TEXT_
