#include "raylib.h"
#include "Bullet.h"
#include "Player.h"
#include "Monster.h"
#include "Common.h"
#include "BulletHitBloodEffect.h"
#include <cmath>
#include <vector>
#include <algorithm>
enum GameState {
	Menu,
	Playing,
	GameOver,
	Setting
};

int main() {
	std::vector<Bullet>Bullets;
	InitWindow(1280, 960, "Game");
	Texture2D JIEstand = LoadTexture("assets/manBlue_stand.png");
	Texture2D JIEwalk = LoadTexture("assets/manBlue_hold.png");
	Texture2D JIEshoot = LoadTexture("assets/manBlue_gun.png");
	//以上为人物加载

	Texture2D Sstand = LoadTexture("assets/zoimbie1_hold.png");
	//以上为怪物加载

	Texture2D BloodEffect = LoadTexture("assets/fx/blood/1.png");
	//以上为特效加载 

	Player JIE{ 500,500,20,6.0,6.0,50 ,JIEstand,JIEwalk,JIEshoot };   //人物初始化

	Monster S{ 200,200,20,20,3,3,200,10,Sstand };          //怪物初始化

	std::vector<Effect*>Effects;      //特效基类指针，多态管理

	SetTargetFPS(60);
	GameState currentState = Menu;


	while (!WindowShouldClose()) {
		if (currentState == Menu) {                                       //菜单界面
			if (IsKeyPressed(KEY_ENTER)) {
				currentState = Playing;
			}
		}
		else if (currentState == Playing) {
			if (!JIE.IsAlive()) {
				currentState = GameOver;
			}
		}
		else if (currentState == GameOver) {
			if (IsKeyPressed(KEY_R)) {
				currentState = Menu;
				JIE = Player{ 500,500,20,6.0,6.0,50,JIEstand,JIEwalk,JIEshoot };                 //对象初始化
				S = Monster{ 200,200,20,20,3,3,200,10 ,Sstand };
				Bullets.clear();
				for (auto e : Effects) {
					delete e;         //特效删除
				}

				Effects.clear();      //子弹删除
			}
		}

		BeginDrawing();                                 //开始渲染
		ClearBackground(RAYWHITE);


		if (currentState == Menu) {
			DrawText("MY SHOOTER", 450, 300, 60, DARKBLUE);
			DrawText("Press ENTER to Start", 480, 400, 30, GRAY);
		}
		else if (currentState == Playing) {
			if (JIE.IsAlive()) {
				JIE.State();             //移动 射击 状态
				JIE.Move();
				JIE.Shoot(Bullets);
			}
			S.Move(JIE.GetX(), JIE.GetY());
			for (int i = 0;i < Bullets.size();i++) {
				Bullets[i].Update();
			}
			Bullets.erase(
				std::remove_if(Bullets.begin(), Bullets.end(), [](Bullet& b) {
					return !b.IsActive();                          //子弹清理
					}),
				Bullets.end()
			);


			float dt = GetFrameTime();
			for (int i = 0; i < Effects.size(); i++) {
				Effects[i]->Update(dt); // 特效多态调用
			}



			for (auto it = Effects.begin(); it != Effects.end(); ) {
				if (!(*it)->IsActive()) {
					delete* it;             // 堆内存删除
					it = Effects.erase(it);
				}
				else {
					++it;
				}
			}


			if (S.IsAlive()) {
				for (int i = 0;i < Bullets.size();i++) {
					if (Bullets[i].IsActive() && S.TakeShoot(Bullets[i])) {
						S.TakeDamage(Bullets[i].GetDamage());                        //子弹射击怪物判断
						Bullets[i].Deactivate();
						Effects.push_back(new BulletHitBloodEffect(S.GetX(), S.GetY(), BloodEffect));
					}
				}
			}



			if (JIE.IsAlive()) {
				if (JIE.TakeHit(S.GetX(), S.GetY(), S.IsAlive())) {
					JIE.TakeDamage(S.GetDamage());                       //玩家受伤判断
				}
			}



			if (S.IsAlive()) {                  //S怪物渲染
				S.Draw();
			}


			if (JIE.IsAlive()) {                       //JIE玩家渲染
				JIE.Draw();
			}



			for (int i = 0;i < Bullets.size();i++) {
				if (Bullets[i].IsActive()) {        //子弹渲染
					Bullets[i].Draw();
				}
			}
			for (int i = 0; i < Effects.size(); i++) {
				Effects[i]->Draw(); // 特效渲染
			}
		}
		else if (currentState == GameOver) {
			if (S.IsAlive()) S.Draw();
			DrawText("GAME OVER", 450, 350, 60, RED);
			DrawText("Press R to Restart", 480, 450, 30, DARKGRAY);
		}
		EndDrawing();
	}                                      //结束渲染
		UnloadTexture(JIEstand);
		UnloadTexture(JIEwalk);
		UnloadTexture(JIEshoot);          //纹理卸载 
		UnloadTexture(Sstand);
		UnloadTexture(BloodEffect);
		for (auto e : Effects) {
			delete e; // 特效删除，防止内存泄漏
		}
	CloseWindow();
	return 0;
}