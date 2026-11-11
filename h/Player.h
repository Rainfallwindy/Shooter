#pragma once
#include <vector>
#include "Animator.h"
#include "raylib.h"
#include "Bullet.h"
enum PlayerState {
	STAND,
	WALK,
	SHOOT
};
class Player {
private:
	float x, y;
	float r;
	float vx, vy;
	bool alive;
	int hp;
	int maxhp;
	Texture2D stand;
	Texture2D walk;
	Texture2D shoot;
	PlayerState state;
	float rotation;
	Animator animator;
public:
	Player(float startx, float starty, float startr, float startspeedx, float startspeedy, int starthp, Texture2D astand, Texture2D awalk, Texture ashoot);
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
	void State();
};