#include "./../Header/GoalManager.h"
#include "./../Header/egudai_CSV.h"
#include "./../Header/NY_random.h"

void GoalManager::Init(int mapData[][40])
{
	//受け取ったマップデータからゴール位置を取り出す
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			if (mapData[y][x] != 12 && mapData[y][x] != 0) {//ゴール予定地だった場合（ここの数値を変えると、ゴール生成位置の変更可能）
				//ゴール予定地のマップチップ座標をpair型コンテナに格納
				pair<int, int> buff = make_pair(x, y);
				goalBuffer.push_back(buff);
			}
		}
	}
	//カウント初期化
	goalCount = 0;

	//ゴールオブジェクトにゴール位置を設定
	goal.pos = goalBuffer[NY_random::intrand_sl(goalBuffer.size() - 1, 0)];

}

void GoalManager::Update(float posX, float posY,bool &isHit)
{
	//プレイヤー座標をマップチップ座標に変換
	int x = posX / 16;
	int y = posY / 16;//YはUI分ずらす

	//プレイヤーとゴールの衝突判定
	if (x == goal.pos.first && y == goal.pos.second) {//衝突している
		//衝突時の追加処理はここに
		goalCount++;//カウント加算

		//ゴールオブジェクトの再設定
		goal.pos = goalBuffer[NY_random::intrand_sl(goalBuffer.size() - 1, 0)];
		isHit = true;//衝突を返却
	}
	else {
		isHit = false;//非衝突を返却
	}
	//ゴールオブジェクト更新
	goal.Update();
}

void GoalManager::Draw()
{
	//ゴールオブジェクトの描画
	goal.Draw();

}
