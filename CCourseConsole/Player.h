#include <string>
#include <iostream>

using namespace std;

#pragma once
class Player
{
protected:
	string name;
	int health;

public:
	Player(const string &name,int ihealth);
	virtual ~Player();

	void show();


	virtual void getDamage(const Player &damager) {};
	virtual int getPow() const;
};

