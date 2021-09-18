#pragma once
#include "Particle.h"

#define MAX_GRAIN (60)//パーティクルの最大生成数

class GoalParticle
{
public:
	//パーティクルの粒（動的生成）
	Particle *grain;
	//パーティクルリソース
	int grainGraph;

public:
	//コンストラクタ
	GoalParticle();
	//デストラクタ
	~GoalParticle();

	//初期化
	void Init();

	/// <summary>
	/// パーティクル出現、描画開始（円形に放出）
	/// </summary>
	/// <param name="x"> 出現座標x</param>
	/// <param name="y"> 出現座標y</param>
	void Spawn(float x, float y);

	//更新
	void Update();

	//描画
	void Draw();


};

