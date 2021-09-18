#pragma once
#include "Map.h"
#include "TurnEffect.h"
#include "CurveEffect.h"
#include "CurvePoint.h"

class Player
{
public:
	// 進行方向
	enum Direction
	{
		UP,
		LEFT,
		DOWN,
		RIGHT
	};

	int posX, posY;     //プレイヤーの座標(左上基準)
	int speed;          //プレイヤーの移動速度
	int maxSpeed;       //プレイヤーの最高速度
	int direction;      //プレイヤーの移動方向
	bool turnFlag;      //曲がるかどうかの判定用フラグ
	int playerGraph[4]; //プレイヤーに使用する画像データ

	TurnEffect turnEffect;   //ターン時の演出
	CurveEffect curveEffect; //カーブ時の演出
	CurvePoint curvePoint;   //どこで曲がるかの演出

public:
	Player();
	~Player() {};

	// 初期化
	void Init(int posX, int posY, int maxSpeed, int direction);
	// 更新
	void Update(Map* map);
	// 描画
	void Draw(int offsetX = 0, int offsetY = 0);
	// 当たり判定
	// <returns> プレイヤーの左上座標が今いるマップの要素番号 </returns>
	int Collision(Map* map);

private:
	// 移動
	void Move();
};
