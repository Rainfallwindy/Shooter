#pragma once
class Bullet {
private:
	float x, y;
	float vx, vy;
	int damage;
	bool active;
public:
	Bullet(float startx, float starty, float startspeedx, float startspeedy, int startdamage);
	void Update();
	void Draw();
	int GetDamage();
	float GetX();
	float GetY();
	bool IsActive();
	void Deactivate();
};
