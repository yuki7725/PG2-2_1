#pragma once
#include "Bullet.h"

class Player {
private:
	Transform transform_;
	int radius_;
	int speed_;
	int timer_;
	bool isHit_;

public:
	Bullet* bullet_;
	Player(Transform transform, int radius, int speed, int timer, bool isHit);
	~Player();

	int GetPosX() { return transform_.x; };
	int GetPosY() { return transform_.y; };
	int GetRadius() { return radius_; };
	int GetSpeedX() { return speed_; };
	int GetSpeedY() { return speed_; };
	int GetAlive() { return isHit_; };

	void SetAlive(bool isHit);

	void Move(char* keys, char* preKeys);
	void Draw();
};
