#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include <math.h>

//シーン遷移
enum Scene {
		SCENE1,//タイトル
		SCENE2,//ゲーム
	};

int kWindowWidth = 1280; 
int kWindowHeight = 720; 
const char kWindowTitle[] = "GC1B_09_ナカノ_ユキ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {


	

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	Player* player = new Player({ 640,500 }, 32, 3, 0, false);

	Enemy* enemy = new Enemy({ 640,200 }, 16, 5, 0,false);

	int currentScene = Scene::SCENE1; //最初の背景

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (currentScene) {
		case Scene::SCENE1:
			if (keys[DIK_RETURN] && preKeys[DIK_RETURN]==0) {
				currentScene = Scene::SCENE2;
			}
			break;
		case Scene::SCENE2:
			player->Move(keys, preKeys);

			enemy->Move();

			//二点間の距離
			int distance_enemy_player_x = player->bullet_->GetPosX() - enemy->GetPosX();
			int distance_enemy_player_y = player->bullet_->GetPosY() - enemy->GetPosY();
			int distance3 = enemy->GetPosX() - player->GetPosX();
			int distance4 = enemy->GetPosY() - player->GetPosY();

			int a = (int)sqrtf((float)distance_enemy_player_x * (float)distance_enemy_player_x + (float)distance_enemy_player_y * (float)distance_enemy_player_y);
			int b = (int)sqrtf((float)distance3 * (float)distance3 + (float)distance4 * (float)distance4);

			if (a <= (player->bullet_->GetRadius() + enemy->GetRadius())) {
				enemy->SetAlive(true);
				enemy->SetSpeedX(0);
			}
			if (b <= (enemy->GetRadius() + player->GetRadius())) {
				player->SetAlive(true);
			}

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN]==0) {
				currentScene = Scene::SCENE1;
			}

			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (currentScene) {
		case Scene::SCENE1:

			Novice::ScreenPrintf(0, 20, "title Scene");

			break;

		case Scene::SCENE2:

			player->Draw();
			enemy->Draw();

			Novice::ScreenPrintf(0, 20, "game Scene");
			Novice::ScreenPrintf(0, 40, "WASD SPACE");

			break;
		}

		Novice::ScreenPrintf(0, 0, "Enter SceneChange %d",currentScene);
		Novice::ScreenPrintf(0, 0, "");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}