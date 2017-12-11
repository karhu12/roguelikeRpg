#include "stdafx.h"
#include "enemy.h"
#include "general.h"

void Enemy::enemyValues() {
	this->health = randomNumber(10, 10);
	this->minDamage = randomNumber(1, 2);
	this->maxDamage = randomNumber(3, 5);
	this->accuracy = randomNumber(60, 35);
	this->alive = true;
}