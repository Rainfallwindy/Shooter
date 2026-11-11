#pragma once
class Animator {
protected:
	float time;
	float changetime;
	bool change;
public:
	Animator(float changeTime);
	void Update();
	bool IsChange();
};
