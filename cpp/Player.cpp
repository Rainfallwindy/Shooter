#include <iostream>
#include <vector>
#include <cmath>
#include "Player.h"
#include "raylib.h"
#include "Bullet.h"
#include "Common.h"
Player::Player(float startx, float starty, float startspeedx, float startspeedy, int starthp) {
	x = startx;
	y = starty;
	vx = startspeedx;
	vy = startspeedy;
	hp = starthp;
	alive = true;
}
void Player::Draw() {
	if (alive) {
		DrawCircle((int)x, (int)y, 20, BLUE);
	}
}
void Player::DeadDraw() {
	DrawText("GAME OVER", 500, 500, 50, RED);
}
bool Player::TakeHit(float monsterx, float monstery, bool monsterAlive) {
	if (!monsterAlive) return false;
	float dx = fabs(x - monsterx);
	float dy = fabs(y - monstery);
	if (dx < 20 && dy < 20) {
		return true;
	}
	else {
		return false;
	}
}
void Player::TakeDamage(int damage) {
	hp = hp - damage;
	if (hp <= 0) {
		hp = 0;
		alive = false;
	}
}
void Player::Move() {
	if (IsKeyDown(KEY_A)) {
		x = x - vx;
	}
	if (IsKeyDown(KEY_D)) {
		x = x + vx;
	}
	if (IsKeyDown(KEY_S)) {
		y = y + vy;
	}
	if (IsKeyDown(KEY_W)) {
		y = y - vy;
	}
}
void Player::Shoot(std::vector<Bullet>&bullet) {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Realshoot(x, y, bullet);
	}
}
int Player::GetHP() {
	return hp;
}
bool Player::IsAlive() {
	if (hp <= 0)return false;
	return true;
}
float Player::GetX() {
	return x;
}
float Player::GetY() {
	return y;
}