#pragma once
#include "Map.h"

class CurvePoint
{
public:
	int posX, posY;     //曲がる場所の座標
	int direction;      //プレイヤーの進行方向
	bool turnRightFlag; //右折かどうかのフラグ
	int frame;          //フレームカウンタ
	int animation;      //アニメーションカウンタ
	int graphArray[9];  //画像データ
	bool drawFlag;      //描画するかどうか

public:
	CurvePoint(); //コンストラクタ
	~CurvePoint() {};

	// 初期化
	void Init();
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="posX"> プレイヤーのX座標(オフセット値無し) </param>
	/// <param name="posY"> プレイヤーのY座標(オフセット値無し) </param>
	/// <param name="direction"> プレイヤーの進行方向 </param>
	/// <param name="turnFlag"> プレイヤーに曲がる意思があるかどうか </param>
	/// <param name="turnRightFlag"> 右折するかどうか </param>
	/// <param name="map"> マップ </param>
	void Update(int posX, int posY, int direction, bool turnFlag, Map* map);
	// 描画（offsetX, offsetY:オフセット値）
	void Draw(int offsetX = 0, int offsetY = 0);
};
