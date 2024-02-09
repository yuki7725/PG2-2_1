#pragma once
#include "transform.h"

class Enemy {
public:

	Enemy(Transform transform, int radius, int speed,int timer, bool isAlive);

	int GetPosX() { return transform_.x; };
	int GetPosY() { return transform_.y; };
	int GetRadius() { return radius_; };
	int GetSpeedX() { return speed_; };
	int GetAlive() { return isAlive_; };

	void SetAlive(bool isAlive);
	void SetSpeedX(bool Speed);

	void Move();

	void Draw();

private:
	Transform transform_;
	int speed_;
	int radius_;
	int timer_;
	bool isAlive_;
};