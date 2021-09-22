#include "./../Header/GameManager.h"

void GameManager::Init(int mapdata[][40])
{
	//レベル
	level = 1;

	//タイマー
	timer.Init();
	timer.Reset(20);

	addedTime = 0;
	penalTime = 10.0;
	bonusTime = 15.0;//初期は15秒

	//ゴール管理
	gmanager.Init(mapdata);
	isHit = false;

	//ゴールパーティクル
	gParticle.Init();

	uiGraph = LoadGraph("Resources/UI.png");
}

void GameManager::Update(float posx,float posy)
{
	if (timer.time > 0) {
		timer.Update();
		gmanager.Update(posx, posy, isHit);
		if (isHit == true) {//ゴールと衝突
			//加算される時間を保持
			addedTime = timer.addTime;
			//タイマー加算
			timer.Add(bonusTime, penalTime);
			
			LevelUP();//レベル管理

			//ゴールパーティクル生成
			gParticle.Spawn(posx + 8, posy + 60 + 8);
			//加算時間表示演出処理
			tx = posx, ty = posy;//座標を設定
			timerParam = 255;//描画パラメータ初期化
		}
	}
	//加算時間表示演出は時間に係わらず行う
	ty--;
	if (timer.timerFrame % 6 == 0 && timerParam > 0) { timerParam -= 15; }

	//パーティクル更新
	gParticle.Update();
}

void GameManager::Draw()
{
	DrawGraph(640, 0, uiGraph, true);
	//タイマー描画
	timer.Draw();
	//レベル描画
	timer.DrawNum(level, 0, 20, 16, 16);//あとで数値描画関数は別にする
	timer.DrawNum(gmanager.goalCount, 100, 20, 16, 16);

	//加算時間表示
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, timerParam);
	timer.DrawNum(addedTime * 10, tx, ty, 16, 16);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	//ゴール描画
	gmanager.Draw();
	//パーティクル描画
	gParticle.Draw();
}

void GameManager::LevelUP()
{
	if (gmanager.goalCount % 2 == 0) {//2回ゴールする毎
		//レベル上昇
		level++;
		//加算時間の減少（下限5秒）
		if (bonusTime > 5.0) {
			bonusTime -= 1.0;
		}
	}
}
