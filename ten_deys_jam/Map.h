#pragma once
#include "egudai_CSV.h"

class Map
{
public:
	//マップデータ
	int map[MAP_HEIGHT][MAP_WIDTH];
	//マップに使用する画像データ
	int mapGraph[14];

public:
	//コンストラクタ
	Map() {};
	//初期化
	void Init();
	//更新
	void Update() {};
	//描画
	void Draw();

};

