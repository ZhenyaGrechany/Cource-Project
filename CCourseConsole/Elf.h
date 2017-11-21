#pragma once
#include "Player.h"
class Elf :
	public Player
{
	int power;
	
public:

	Elf(string name,int pow,int ihealth):Player(name,ihealth),power(pow)
	{
		cout << "c c!" << endl;
	}

	~Elf()
	{
		cout << "c d!" << endl;
	}

	void show()
	{
		Player::show();
		cout << "Power: " << power << endl;
	}

	void showPow()
	{
		cout << "Power: " << power << endl;
	}

	void getDamage(const Player &dmgr)
	{
		health = health - dmgr.getPow();
		cout << name << " damaged!!! " << "before attack "<< health + dmgr.getPow()
			<< " after attack " << health << endl;
	}

	int getPow() const
	{
		return power;
	}
};

