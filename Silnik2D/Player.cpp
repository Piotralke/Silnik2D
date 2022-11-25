#include "Player.h"
void Player::update(Vector2f moveVector,float alfa)
{
	translate(moveVector);
	Vector2f rotVec = Vector2f(getPosition().x + (getSize().x / 2), getPosition().y + (getSize().y / 2));
	if(alfa!=0)
		rotate(rotVec, alfa);
}
