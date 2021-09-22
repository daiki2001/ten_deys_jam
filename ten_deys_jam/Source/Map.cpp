#include "./../Header/Map.h"
#include "DxLib.h"

void Map::Init()
{
	//マップCSVの読み込み
	LoadCSV(map, "Resources/alphamap.csv");

	//マップ画像の読み込み
	LoadDivGraph("Resources/Sprite-0001.png", 14, 14, 1, 16, 16, mapGraph);

}

void Map::Draw()
{
	//マップ描画関数を使用して描画
	DrawMap(map, 16, mapGraph, true);
}
