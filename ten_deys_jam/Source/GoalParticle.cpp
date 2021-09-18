#pragma once
#include "./../Header/GoalParticle.h"
#include "DxLib.h"

GoalParticle::GoalParticle()
{
	//パーティクル生成
	grain = new Particle[MAX_GRAIN];
	//パーティクルリソースの読み込み
}

GoalParticle::~GoalParticle()
{
	delete[] grain;
}

void GoalParticle::Init()
{
	//パーティクルのパラメーターの初期化
	for (int i = 0; i < MAX_GRAIN; i++) {
		InitParticle(grain[i], 0, 0, 0, 0, 8, 8, 255, std::make_tuple<int, int, int>(255, 255, 255));
	}
}

void GoalParticle::Spawn(float x, float y)
{
	float rad = (360.0f / MAX_GRAIN);//粒の射出角度
	rad = rad * (DX_PI / 180);//ラジアン角に変換
	for (int i = 0; i < MAX_GRAIN; i++) {//全パーティクルを出現
		//初期化（出現座標とサイズ設定）
		InitParticle(grain[i], x, y, 0, 0, 4, 4, 255, std::make_tuple<int, int, int>(255, 255, 255));
		//ベクトル計算(円周上の点を求める要領)
		grain[i].vecX = 10 * cosf(rad * i);
		grain[i].vecY = 10 * sinf(rad * i);
		//描画フラグ有効化
		grain[i].isAlive = true;
	}
}

void GoalParticle::Update()
{
	//パーティクル更新処理
	for (int i = 0; i < MAX_GRAIN; i++) {
		if (grain[i].isAlive == true) {//パーティクルが有効な時

			grain[i].frame++;
			//座標を移動
			grain[i].posX += grain[i].vecX;
			grain[i].posY += grain[i].vecY;

			if (grain[i].frame % 2 == 0) {//2f毎に
				//描画パラメータ減少
				grain[i].param -= 5;
			}
			if (grain[i].frame % 102 == 0) {//102f経過時
				grain[i].isAlive = false;//パーティクル無効化
			}
		}
	}

}

void GoalParticle::Draw()
{
	if (grain[0].isAlive == true) {
		for (int i = 0; i < MAX_GRAIN; i++) {
			if (grain[i].isAlive == true) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, grain[i].param);
				DrawCircle(grain[i].posX, grain[i].posY, grain[i].width, GetColor(255, 255, 255));
			}
		}
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}
