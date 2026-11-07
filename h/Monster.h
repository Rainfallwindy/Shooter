#pragma once
#include "Bullet.h"
class Monster {
private:
	float x, y;
	float vx, vy;
	bool alive;
	int hp;
	int damage;
public:
	Monster(float startx, float starty, float startvx, float startvy, int starthp, int startdamage);
	void Draw();
	void Move(float playerx, float playery);
	bool TakeShoot(Bullet& Bullets);
	void TakeDamage(int damage);
	void DeadDraw();
	int GetHP();
	bool IsAlive();
	float GetX();
	float GetY();
	int GetDamage();
};