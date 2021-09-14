#pragma once

#define MAP_WIDTH (40)  //横の最大枚数
#define MAP_HEIGHT (40) //縦の最大枚数

// ↓のenumは属性別に分けた物で、何かに使っている訳では無い
enum Status
{
	NONE,       //空
	STRAIGHT,   //直進
	CORNER,     //曲がり角
	JUNCTION,   //交差点
	T_JUNCTION, //T字路
	WALL,       //壁
	GOAL        //ゴール
};

/// <summary>
/// CSVファイルの読み込み
/// </summary>
/// <param name="map"> 読み込んだCSVファイルの保存先 </param>
/// <param name="FilePath"> CSVファイルのパス </param>
/// <param name="LoadStopNumber"> ここに指定された値がヒットすると読み込みを終了する </param>
/// <returns> 0以外で失敗、0で成功 </returns>
int LoadCSV(int map[MAP_HEIGHT][MAP_WIDTH], const char* FilePath, int LoadStopNumber = -1);

/// <summary>
/// オフセット値を基準に敷き詰める(画像の枚数)
/// </summary>
/// <param name="map"> マップチップの配列 </param>
/// <param name="mapSize"> マップチップ一枚あたりの大きさ </param>
/// <param name="graphHandleArray"> 描画するグラフィックのハンドル配列 </param>
/// <param name="allNum"> 画像の枚数 </param>
/// <param name="transFlag"> 画像の透明度を有効にするかどうか </param>
/// <param name="offsetX"> オフセット値のx座標 </param>
/// <param name="offsetY"> オフセット値のy座標 </param>
void DrawMap(int map[MAP_HEIGHT][MAP_WIDTH], int mapSize, int graphHandleArray[], bool transFlag, int offsetX = 0, int offsetY = 0);
