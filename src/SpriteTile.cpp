/*
 * SpriteTile.cpp
 *
 *  Created on: Mar 16, 2014
 *      Author: amr
 */

#include "SpriteTile.h"

SpriteTile::SpriteTile(unsigned nr, unsigned x, unsigned y, unsigned size) :
	Tile(nr, x, y, size)
{
	// TODO Auto-generated constructor stub

}

void SpriteTile::setSprite(sf::Sprite spr)
{
	sprite = spr;
}

const sf::Sprite& SpriteTile::getSprite()
{
	return sprite;
}

void SpriteTile::setPosition(unsigned x, unsigned y)
{
	sprite.SetX(x);
	sprite.SetY(y);
}

void SpriteTile::setX(unsigned x)
{
	// argument powinien być float, ale moze unsigned tez zadziala
	sprite.SetX(x);
}

void SpriteTile::setY(unsigned y)
{
	// argument powinien być float, ale moze unsigned tez zadziala
	sprite.SetY(y);
}

unsigned SpriteTile::getX()
{
	return 0;
}

unsigned SpriteTile::getY()
{
	return 0;
}

bool SpriteTile::contains(unsigned x, unsigned y)
{
	//TODO implement
	return false;
}

void SpriteTile::draw(sf::RenderWindow& window)
{
}
