#include "raylib.h"
#include "Bullet.h"
#include "Monster.h"
#include "Player.h"
void Realshoot(float playerx, float playery, std::vector<Bullet>& Bullets) {
	float mousex = GetMouseX();
	float mousey = GetMouseY();
	float dx = mousex - playerx;
	float dy = mousey - playery;
	float length = sqrt(dx * dx + dy * dy);
	if (length == 0) {
		length = 1;
	}
	float speed = 10.0f;
	float vx = (dx / length) * speed;
	float vy = (dy / length) * speed;

	Bullets.push_back(Bullet(playerx, playery, vx, vy, 10));
}