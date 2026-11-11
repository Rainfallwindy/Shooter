#pragma once
#include "Bullet.h"
#include "raylib.h"
class Monster {
private:
	float x, y;
	float width;
	float length;
	float vx, vy;
	bool alive;
	int hp;
	int maxhp;
	int damage;
	Texture2D tex;
	float rotation;
public:
	Monster(float startx, float starty,float startwidth,float startlength, float startvx, float startvy, int starthp, int startdamage,Texture astand);
	void Draw();
	void Move(float playerx, float playery);
	bool TakeShoot(Bullet& Bullets);
	void TakeDamage(int damage);
	void DeadDraw();
	int GetHP();
	float GetHPX();
	float GetHPY();
	bool IsAlive();
	float GetX();
	float GetY();
	int GetDamage();
	float GetWidth();
	float GetLength();
};