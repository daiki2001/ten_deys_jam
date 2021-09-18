#pragma once
#include <utility>

class Goal
{
public:
	//ゴールの実際の位置(マップチップ座標)(x,y);
	std::pair<int, int> pos = std::make_pair(0, 0);
	//ゴール画像
	int flagGraph[6];//旗
	int effectGraph[6];//ゴールエフェクト

	//経過フレーム
	int frame = 0;
	//描画番号
	int gnum = 0;

public:
	//コンストラクタ
	Goal() {
		Init();
	}

	//初期化
	void Init();

	//更新
	void Update();

	//描画
	void Draw();

};

