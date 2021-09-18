#pragma once
#include "Map.h"
#include "TurnEffect.h"
#include "CurveEffect.h"
#include "CurvePoint.h"

class Player
{
public:
	// �i�s����
	enum Direction
	{
		UP,
		LEFT,
		DOWN,
		RIGHT
	};

	int posX, posY;     //�v���C���[�̍��W(����)
	int speed;          //�v���C���[�̈ړ����x
	int maxSpeed;       //�v���C���[�̍ō����x
	int direction;      //�v���C���[�̈ړ�����
	bool turnFlag;      //�Ȃ��邩�ǂ����̔���p�t���O
	int playerGraph[4]; //�v���C���[�Ɏg�p����摜�f�[�^

	TurnEffect turnEffect;   //�^�[�����̉��o
	CurveEffect curveEffect; //�J�[�u���̉��o
	CurvePoint curvePoint;   //�ǂ��ŋȂ��邩�̉��o

public:
	Player();
	~Player() {};

	// ������
	void Init(int posX, int posY, int maxSpeed, int direction);
	// �X�V
	void Update(Map* map);
	// �`��
	void Draw(int offsetX = 0, int offsetY = 0);
	// �����蔻��
	// <returns> �v���C���[�̍�����W��������}�b�v�̗v�f�ԍ� </returns>
	int Collision(Map* map);

private:
	// �ړ�
	void Move();
};
