#pragma once
#include "egudai_CSV.h"

class Map
{
public:
	//�}�b�v�f�[�^
	int map[MAP_HEIGHT][MAP_WIDTH];
	//�}�b�v�Ɏg�p����摜�f�[�^
	int mapGraph[14];

public:
	//�R���X�g���N�^
	Map() {};
	//������
	void Init();
	//�X�V
	void Update() {};
	//�`��
	void Draw();

};

