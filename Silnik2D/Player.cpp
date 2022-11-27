#include "Player.h"
#include <iostream>
void Player::update(Vector2f moveVector)
{
	translate(moveVector);
	Vector2f rotVec = Vector2f(getPosition().x + (getSize().x / 2), getPosition().y + (getSize().y / 2));

		
}
void Player::draw(RenderWindow* window,float alfa)
{
	this->texture = textures->at(index);
	
	for (int i = 0; i < this->points.size(); i++)
	{
		cs.setPoint(i, points[i]);
	}
	cs.setPosition(this->getPosition());
	cs.setOrigin(this->getPosition().x + (this->getSize().x / 2), this->getPosition().y + (this->getSize().y / 2));

	cs.setTexture(&this->texture);
	if(alfa!=0)
		cs.setRotation(alfa+90);
	window->draw(cs);
}
