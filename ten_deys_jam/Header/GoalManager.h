#pragma once
#include <vector>
#include "Goal.h"

using namespace std;

//ゴールオブジェクトを管理するクラス。
//ゴールの各種処理を行う

class GoalManager
{
public:
	//ゴールオブジェクト
	Goal goal;
	//ロードしたマップのゴール位置を格納するコンテナ(x,y)
	vector<pair<int, int>> goalBuffer;
	//ゴールカウンター
	int goalCount = 0;

	

public:
	//コンストラクタ
	GoalManager() {};

	//初期化（マップデータを読み込んで、ゴール位置格納コンテナに格納）
	void Init(int mapData[][40]);

	/// <summary>
	/// 更新処理
	/// プレイヤーとゴールの衝突判定
	/// 衝突時のゴール再生成
	/// </summary>
	/// <param name="posX">ゴールと判定を取るオブジェクトのX座標</param>
	/// <param name="posY">ゴールと判定を取るオブジェクトのY座標</param>
	///	<param name="isHit">ゴールとの衝突判定を返却</param>
	void Update(float posX, float posY, bool &isHit);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

};

