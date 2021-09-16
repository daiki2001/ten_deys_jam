#pragma once
#include "Map.h"
#include "TurnEffect.h"

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
	int direction;      //プレイヤーの移動方向
	bool trunFlag;      //曲がるかどうかの判定用フラグ
	int playerGraph[4]; //プレイヤーに使用する画像データ

	TurnEffect turnEffect; //ターン時の演出

public:
	Player();
	~Player() {};

	// 初期化
	void Init(int posX, int posY, int speed, int direction);
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
