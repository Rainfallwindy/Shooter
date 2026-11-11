#include "raylib.h"
#include "Bullet.h"
#include "Monster.h"
#include "Player.h"
Monster::Monster(float startx, float starty,float startwidth,float startlength, float startvx, float startvy, int starthp, int startdamage) {
	x = startx;
	y = starty;
	width = startwidth;
	length = startlength;
	vx = startvx;
	vy = startvy;
	hp = starthp;
	maxhp = starthp;
	damage = startdamage;
	alive = true;
}
void Monster::Draw() {
	DrawRectangle((int)x, (int)y, length, width, BLACK);
}
void Monster::Move(float playerx, float playery) {
	if (!alive) return;
	float f = 0.9f;
	float speed = 6.0f;
	float dx = playerx - x;
	float dy = playery - y;
	float len = sqrt(dx * dx + dy * dy);
	if (len < 1.0f) return;
	vx = (dx / len) * speed * f;
	vy = (dy / len) * speed * f;
	if (vx > len) {
		vx = len;
	}
	if (vy > len) {
		vy = len;
	}
	x = x + vx;
	y = y + vy;
}
bool Monster::TakeShoot(Bullet& Bullets) {
	float dx = fabs(Bullets.GetX() - x);
	float dy = fabs(Bullets.GetY() - y);
	if (dx < 20 && dy < 20) {
		return true;
	}
	else { return false; }
}
void Monster::TakeDamage(int damage) {
	hp = hp - damage;
	if (hp <= 0) {
		hp = 0;
		alive = false;
	}
}
void Monster::DeadDraw() {
	DrawText("Monster Defeated!", (int)x + 20, (int)y + 20, 20, RED);
}
int Monster::GetHP() {
	return hp;
}
bool Monster::IsAlive() {
	if (hp <= 0)return false;
	return true;
}
float Monster::GetX() {
	return x;
}
float Monster::GetY() {
	return y;
}
int Monster::GetDamage() {
	return damage;
}
float Monster::GetHPX() {
	return x ;
}
float Monster::GetHPY() {
	return y - width / 2;
}
float Monster::GetWidth() {
	return width;
}
float Monster::GetLength() {
	return length;
}