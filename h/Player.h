#pragma once
#include <vector>
#include "Bullet.h"
class Player {
private:
	float x, y;
	float r;
	float vx, vy;
	bool alive;
	int hp;
	int maxhp;
public:
	Player(float startx, float starty, float startr, float startspeedx, float startspeedy, int starthp);
	void Draw();
	void DeadDraw();
	bool TakeHit(float monsterx, float monstery, bool monsterAlive);
	void TakeDamage(int damage);
	void Move();
	void Shoot(std::vector<Bullet>& bullet);
	int GetHP();
	float GetR();
	float GetHPX();
	float GetHPY();
	bool IsAlive();
	float GetX();
	float GetY();
};