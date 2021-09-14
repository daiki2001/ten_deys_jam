#pragma once

#define MAP_WIDTH (40)  //���̍ő喇��
#define MAP_HEIGHT (40) //�c�̍ő喇��

// ����enum�͑����ʂɕ��������ŁA�����Ɏg���Ă����ł͖���
enum Status
{
	NONE,       //��
	STRAIGHT,   //���i
	CORNER,     //�Ȃ���p
	JUNCTION,   //�����_
	T_JUNCTION, //T���H
	WALL,       //��
	GOAL        //�S�[��
};

/// <summary>
/// CSV�t�@�C���̓ǂݍ���
/// </summary>
/// <param name="map"> �ǂݍ���CSV�t�@�C���̕ۑ��� </param>
/// <param name="FilePath"> CSV�t�@�C���̃p�X </param>
/// <param name="LoadStopNumber"> �����Ɏw�肳�ꂽ�l���q�b�g����Ɠǂݍ��݂��I������ </param>
/// <returns> 0�ȊO�Ŏ��s�A0�Ő��� </returns>
int LoadCSV(int map[MAP_HEIGHT][MAP_WIDTH], const char* FilePath, int LoadStopNumber = -1);

/// <summary>
/// �I�t�Z�b�g�l����ɕ~���l�߂�(�摜�̖���)
/// </summary>
/// <param name="map"> �}�b�v�`�b�v�̔z�� </param>
/// <param name="mapSize"> �}�b�v�`�b�v�ꖇ������̑傫�� </param>
/// <param name="graphHandleArray"> �`�悷��O���t�B�b�N�̃n���h���z�� </param>
/// <param name="allNum"> �摜�̖��� </param>
/// <param name="transFlag"> �摜�̓����x��L���ɂ��邩�ǂ��� </param>
/// <param name="offsetX"> �I�t�Z�b�g�l��x���W </param>
/// <param name="offsetY"> �I�t�Z�b�g�l��y���W </param>
void DrawMap(int map[MAP_HEIGHT][MAP_WIDTH], int mapSize, int graphHandleArray[], bool transFlag, int offsetX = 0, int offsetY = 0);
