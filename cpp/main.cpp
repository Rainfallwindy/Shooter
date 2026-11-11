#include "raylib.h"
#include "Bullet.h"
#include "Player.h"
#include "Monster.h"
#include "Common.h"
#include <cmath>
#include <vector>
#include <algorithm>
int main() {
	Player JIE{ 500,500,20,6.0,6.0,50 };
	Monster S{ 200,200,20,20,3,3,200,10 };
	std::vector<Bullet>Bullets;
	InitWindow(1280, 960, "Game");
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		if (JIE.IsAlive()) {
			JIE.Move();
			JIE.Shoot(Bullets);
		}
		S.Move(JIE.GetX(), JIE.GetY());
		for (int i = 0;i < Bullets.size();i++) {
			Bullets[i].Update();
		}
		Bullets.erase(
			std::remove_if(Bullets.begin(), Bullets.end(), [](Bullet& b) {
				return !b.IsActive();
				}),
			Bullets.end()
		);
		if (S.IsAlive()) {
			for (int i = 0;i < Bullets.size();i++) {
				if (Bullets[i].IsActive() && S.TakeShoot(Bullets[i])) {
					S.TakeDamage(Bullets[i].GetDamage());
					Bullets[i].Deactivate();
				}
			}
		}
		if (JIE.IsAlive()) {
			if (JIE.TakeHit(S.GetX(), S.GetY(), S.IsAlive())) {
				JIE.TakeDamage(S.GetDamage());
			}
		}
		BeginDrawing();
		ClearBackground(RAYWHITE); 
		if (S.IsAlive()) {
			S.Draw();
		}
		if (JIE.IsAlive()) {
			JIE.Draw();
		}
		if (!S.IsAlive()) {
			S.DeadDraw();
		}
		if (!JIE.IsAlive()) {
			JIE.DeadDraw();
		}
		for (int i = 0;i < Bullets.size();i++) {
			if (Bullets[i].IsActive()) {
				Bullets[i].Draw();
			}
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}