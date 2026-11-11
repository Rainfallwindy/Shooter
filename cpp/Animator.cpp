#include "Animator.h"
#include "raylib.h"
Animator::Animator(float changeTime) {
	time = 0.0f;
	changetime = changeTime;
	change = true;
}
void Animator::Update() {
	time -= GetFrameTime();
	if (time <= 0.0f) {
		change = !change;
		time = changetime;                                                                    
	}
}
bool Animator::IsChange() {
	return change;
}