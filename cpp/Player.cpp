#include <iostream>
#include <vector>
#include <cmath>
#include "Player.h"
#include "raylib.h"
#include "Bullet.h"
#include "Common.h"
#include "Animator.h"
Player::Player(float startx, float starty, float startr, float startspeedx, float startspeedy, int starthp, Texture2D astand, Texture2D awalk, Texture ashoot)
	:animator(0.2f)
{
	x = startx;
	y = starty;
	vx = startspeedx;
	vy = startspeedy;
	r = startr;
	hp = starthp;
	maxhp = starthp;    
	alive = true;
	stand = astand;
	walk = awalk;
	shoot = ashoot;
	state = STAND;
	rotation = 0.0f;
}
void Player::State() {
	state = STAND;
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		state = SHOOT;
	}
	else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_S) || IsKeyDown(KEY_W)) {
		state = WALK;
		animator.Update();
	}
	else {
		state = STAND;
	}
}
void Player::Draw() {
	Texture2D currentTexture;
	if (alive && state == SHOOT) {
		currentTexture = shoot;
	}
	else if (alive&&state == WALK) {
		if (animator.IsChange()) {
			currentTexture = walk;
		}
		else {
			currentTexture = stand;
		}
	}
	else if (alive && state == STAND) {
		currentTexture = stand;
	}
	Rectangle sourceRec = { 0.0f, 0.0f, (float)currentTexture.width, (float)currentTexture.height };
	Rectangle destRec = { x, y, (float)currentTexture.width, (float)currentTexture.height };
	Vector2 origin = { (float)currentTexture.width / 2, (float)currentTexture.height / 2 };
	DrawTexturePro(currentTexture, sourceRec, destRec, origin, rotation, WHITE);
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
	float dx = GetMouseX() - x;
	float dy = GetMouseY() - y;
	rotation = atan2(dy, dx) * RAD2DEG;
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
float Player::GetR() {
	return r;
}
float Player::GetHPX() {
	return x - r;
}
float Player::GetHPY() {
	return y - r - r / 2;
}
