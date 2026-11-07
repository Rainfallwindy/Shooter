#pragma once
#include <vector>
#include "Bullet.h"
class Player {
private:
	float x, y;
	float vx, vy;
	bool alive;
	int hp;
public:
	Player(float startx, float starty, float startspeedx, float startspeedy, int starthp);
	void Draw();
	void DeadDraw();
	bool TakeHit(float monsterx, float monstery, bool monsterAlive);
	void TakeDamage(int damage);
	void Move();
	void Shoot(std::vector<Bullet>& bullet);
	int GetHP();
	bool IsAlive();
	float GetX();
	float GetY();
};