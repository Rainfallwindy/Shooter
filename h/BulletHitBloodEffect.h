#pragma once
#include "raylib.h"
#include "Effect.h"
class BulletHitBloodEffect :public Effect {
private:
	Texture2D tex;
public:
	BulletHitBloodEffect(float startx, float starty, Texture2D stex);
	void Update(float x)override;
	void Draw()override;
};