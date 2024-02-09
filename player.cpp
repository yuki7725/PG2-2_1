#include "Novice.h"
#include "Player.h"
#include "Bullet.h"

Player::Player(Transform transform, int radius, int speed, int timer, bool isHit) {
	transform_ = transform;
	radius_ = radius;
	speed_ = speed;
	timer_ = timer;
	isHit_ = isHit;

	bullet_ = new Bullet({ 0,0 }, 10, 10, false);
}
Player::~Player() {
	delete bullet_;
}

void Player::SetAlive(bool isHit) {
	isHit_ = isHit;
}

void Player::Move(char* keys, char* preKeys) {

	if (keys[DIK_W] && preKeys[DIK_W]) {
		transform_.y -= speed_;
	}
	if (keys[DIK_S] && preKeys[DIK_S]) {
		transform_.y += speed_;
	}
	if (keys[DIK_A] && preKeys[DIK_A]) {
		transform_.x -= speed_;
	}
	if (keys[DIK_D] && preKeys[DIK_D]) {
		transform_.x += speed_;
	}
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && bullet_->isShot_ == false) {
		bullet_->transform_ = transform_;
		bullet_->isShot_ = true;
	}
	bullet_->Move();

	if (keys[DIK_R] && preKeys[DIK_R]) {
		isHit_ = false;
	}
	if (isHit_ == true) {
		timer_++;
	}
	if (timer_ >= 60) {
		isHit_ = false;
		timer_ = 0;
	}
}

void Player::Draw() {
	if (isHit_ == false) {
		Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
	else if (isHit_ == true) {
		Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, BLACK, kFillModeSolid);

	}
	bullet_->Draw();
}
