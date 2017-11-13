#include "Classes_SFML.h"



void main()
{
	srand(time(0));

	Player p("Samir", 1500);
	p.setMoveSpeed(6);
	p.getSprite().setPosition(300, 300);
	p.setAction(Idle);
	p.setState(Normal);
	p.setDmg(150, 250);
	p.setParams(700, 200, 100);

	AssembledGame::get().addHero(p);
	AssembledGame::get().addScorpion(40);

	AssembledGame::get().game();
}