#include "Bullet.h"
#include <raylib.h>
Bullet::Bullet(float startx, float starty, float startspeedx, float startspeedy, int startdamage) {
	x = startx;
	y = starty;
	vx = startspeedx;
	vy = startspeedy;
	damage = startdamage;
	active = true;
}
void Bullet::Update() {
	if (!active) { return; }
	x = x + vx;
	y = y + vy;
	if (x > 1280 || x < 0 || y>960 || y < 0) {
		active = false;
	}
}
void Bullet::Draw() {
	if (active) {
		DrawCircle((int)x, (int)y, 5, RED);
	}
}
int Bullet::GetDamage() {
	return damage;
}
bool Bullet::IsActive() {
	return active;
}
void Bullet::Deactivate() {
	active = false;
}
float Bullet::GetX() { return x; }
float Bullet::GetY() { return y; }