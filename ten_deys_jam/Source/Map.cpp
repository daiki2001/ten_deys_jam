#include "./../Header/Map.h"
#include "DxLib.h"

void Map::Init()
{
	//�}�b�vCSV�̓ǂݍ���
	LoadCSV(map, "Resources/alphamap.csv");

	//�}�b�v�摜�̓ǂݍ���
	LoadDivGraph("Resources/Sprite-0001.png", 14, 14, 1, 16, 16, mapGraph);

}

void Map::Draw()
{
	//�}�b�v�`��֐����g�p���ĕ`��
	DrawMap(map, 16, mapGraph, true);
}
