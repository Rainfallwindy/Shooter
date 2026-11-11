#include "BulletHitBloodEffect.h"
BulletHitBloodEffect::BulletHitBloodEffect(float startx, float starty, Texture2D stex)
	:Effect(startx,starty,0.05f,4),tex(stex) { }

void BulletHitBloodEffect::Update(float dt) {
	if (!active)return;
	time = time + dt;
	if (time >= frametime) {
		time = 0.0f;
		frame++;
		if (frame >= totalframe) {
			active = false;
		}
	}
}
void BulletHitBloodEffect::Draw() {
	if (!active)return;
	float frameWidth = (float)tex.width / totalframe;
	float frameHeight = (float)tex.height;
	Rectangle source = { (float)frame * frameWidth, 0.0f, frameWidth, frameHeight };
	Vector2 pos = { x, y };

	DrawTextureRec(tex, source, pos, WHITE);
}