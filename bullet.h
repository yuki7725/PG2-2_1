#pragma once
#include "transform.h"

class Bullet {
public:
	Transform transform_;
	int speed_;
	int radius_;
	bool isShot_;

public:
	Bullet(Transform transform, int s, int r, bool i);

	int GetPosX() { return transform_.x; };
	int GetPosY() { return transform_.y; };
	int GetRadius() { return radius_; };
	int GetSpeedX() { return speed_; };
	int GetIsShot() { return isShot_; };

	void SetIsShot(bool isShot);

	void Move();
	void Draw();
};