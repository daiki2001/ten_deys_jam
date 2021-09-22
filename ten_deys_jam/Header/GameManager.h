#pragma once
#include "Timer.h"
#include "GoalManager.h"
#include "GoalParticle.h"

//ゲーム内の時間、レベルなどを管理するクラス
//（レベルとタイムは別物
/*
・仕様




*/

class GameManager
{
public:
	//レベル
	int level = 1;//レベル
	//int goalCount = 0;//ゴール数

	//時間
	Timer timer;//タイマークラス
	float bonusTime = 10.0;//加算時間
	float penalTime = 10.0;//ボーナス時間減少猶予
	//加算時間表示演出用
	float addedTime;//加算された時間
	int tx, ty;
	int timerParam;//タイマー描画パラメータ

	//ゴール管理
	GoalManager gmanager;
	bool isHit = false;
	//ゲーム進行中フラグ
	bool isGameActive = true;

	//ゴールパーティクル
	GoalParticle gParticle;

	int uiGraph;

	//コンストラクタ
	GameManager() {};
	~GameManager() {};

	//初期化
	void Init(int mapdata[][40]);

	//更新
	void Update(float posx, float posy);

	//描画
	void Draw();

	//----------以下、機能別関数----------//
	
	/// <summary>
	/// <para>レベルの上昇と、それに伴う難易度上昇を行う</para>
	/// <para>レベルの上昇判定もここで行う</para>
	/// </summary>
	private : void LevelUP();

};

//数値描画関数

