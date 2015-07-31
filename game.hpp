#ifndef _GAME_
#define _GAME_


void game(Screen& scr, Player& pl1, Player& pl2, Chaser& ch1, Chaser& ch2, Environment& env)
{

    if(!pl1.isDead())
    {

        pl1.movement();
        pl1.colWithField();
        pl1.gravity();
        ch1.movement(pl1);

        if(ch1.colWithPlayer(pl1) || ch2.colWithPlayer(pl1))
            pl1.killPlayer();

    }
    if(!pl2.isDead())
    {

        pl2.movement();
        pl2.colWithField();
        pl2.gravity();
        ch2.movement(pl2);

        if(ch1.colWithPlayer(pl2) || ch2.colWithPlayer(pl2))
            pl2.killPlayer();
    }

    if(pl1.colWithGoal(env) || pl2.colWithGoal(env))
            env.spawn();



    scr.sClear();
    scr.sDrawBackground();
    scr.sDraw(env.drawGoal());
    scr.sDraw(ch1.getShape());
    scr.sDraw(ch2.getShape());
    if(!pl1.isDead())
        scr.sDraw(pl1.getShape());
    if(!pl2.isDead())
        scr.sDraw(pl2.getShape());
    scr.sDisplay();


}











#endif // _GAME_
