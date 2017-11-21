#include "stdafx.h"
#include "Orc.h"


Orc::Orc(string name, int pow, int ihealth):
	Player(name, ihealth), power(pow)
{
}


Orc::~Orc()
{
}

void Orc::getDamage(const Player & damager)
{
	health = health - damager.getPow();
	cout << name << " damaged!!! " << "before attack " << health + damager.getPow()
		<< " after attack " << health << endl;
}
