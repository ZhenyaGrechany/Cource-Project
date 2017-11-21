#include "stdafx.h"
#include "Player.h"


Player::Player(const string &name_,int ihealth):name(name_),health(ihealth)
{

}


Player::~Player()
{

}

void Player::show()
{
	cout << "Name: " << name << endl;
}

int Player::getPow() const
{
	return 0;
}
