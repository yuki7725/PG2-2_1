#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet(Transform transform, int speed, int radius, bool isShot) {
	transform_ = transform;
	speed_ = speed;
	radius_ = radius;
	isShot_ = isShot;
}

void Bullet::SetIsShot(bool isShot) {
	isShot_ = isShot;
}

void Bullet::Move() {
	if (isShot_ == true) {
		transform_.y -= speed_;
		if (transform_.y <= 0) {
			isShot_ = false;
		}
	}
}

void Bullet::Draw() {
	if (isShot_ == true) {
		Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}