#include "Player.h"
void Player::update(Vector2f moveVector,float alfa)
{
	translate(moveVector);
	Vector2f rotVec = Vector2f(getPosition().x + (getSize().x / 2), getPosition().y + (getSize().y / 2));
	if(alfa!=0)
		rotate(rotVec, alfa);
		
}
void Player::draw(RenderWindow* window,float alfa)
{
	this->texture = textures->at(index);
	ConvexShape cs = ConvexShape(this->points.size());
	for (int i = 0; i < this->points.size(); i++)
	{
		cs.setPoint(i, points[i]);
	}
	cs.setTexture(&this->texture);
	cs.setRotation(alfa);
	window->draw(cs);
}