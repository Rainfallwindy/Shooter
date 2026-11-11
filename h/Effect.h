#pragma once
#include "raylib.h"
class Effect {
protected:
	float x, y;
	float time;
	float frametime;
	int frame;
	int totalframe;
	bool active;
public:
	Effect(float sx, float sy, float sframetime, int total)
		:x(sx), y(sy), frametime(sframetime), totalframe(total), time(0.0f), frame(0), active(true) {}
	virtual ~Effect() = default;
	virtual void Update(float x) = 0;
	virtual void Draw() = 0;

	bool IsActive() const { return active; }
};