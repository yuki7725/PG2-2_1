#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy(Transform transform, int radius, int speed, int timer, bool isAlive) {
	transform_ = transform;
	speed_ = speed;
	radius_ = radius;
	timer_ = timer;
	isAlive_ = isAlive;
}

void Enemy::SetAlive(bool isAlive) {
	isAlive_ = isAlive;
}

void Enemy::SetSpeedX(bool speed) {
	speed_ = speed;
}

void Enemy::Move() {
	transform_.x += speed_;

	if (transform_.x - radius_ <= 0 || transform_.x + radius_ >= 1280) {
		speed_ *= -1;
	}
	if (isAlive_ == true) {
		timer_++;
	}
	if (timer_ >= 60) {
		isAlive_ = false;
		timer_ = 0;
		speed_ = 5;
	}

}

void Enemy::Draw() {
	if (isAlive_ == false) {
		Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	}
	else if (isAlive_ == true) {
		Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, BLACK, kFillModeSolid);
	}
}
