#ifndef _CLOCK_
#define _CLOCK_

class Clock
{
    private:

        sf::Clock clk;

    public:

        Clock() {}
        void restart() { clk.restart(); }
        sf::Time getTime() { return clk.getElapsedTime(); }

};





#endif // _CLOCK_
