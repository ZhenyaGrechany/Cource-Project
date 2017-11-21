#pragma once
#include "Player.h"


class Orc:
	public Player
{
	int power;
public:
	Orc(string name, int pow, int ihealth);
	~Orc();

	void getDamage(const Player &damager);

	int getPow() const
	{
		return power;
	}

};

