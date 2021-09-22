#pragma once
#include "Timer.h"
#include "GoalManager.h"
#include "GoalParticle.h"

//�Q�[�����̎��ԁA���x���Ȃǂ��Ǘ�����N���X
//�i���x���ƃ^�C���͕ʕ�
/*
�E�d�l




*/

class GameManager
{
public:
	//���x��
	int level = 1;//���x��
	//int goalCount = 0;//�S�[����

	//����
	Timer timer;//�^�C�}�[�N���X
	float bonusTime = 10.0;//���Z����
	float penalTime = 10.0;//�{�[�i�X���Ԍ����P�\
	//���Z���ԕ\�����o�p
	float addedTime;//���Z���ꂽ����
	int tx, ty;
	int timerParam;//�^�C�}�[�`��p�����[�^

	//�S�[���Ǘ�
	GoalManager gmanager;
	bool isHit = false;
	//�Q�[���i�s���t���O
	bool isGameActive = true;

	//�S�[���p�[�e�B�N��
	GoalParticle gParticle;

	int uiGraph;

	//�R���X�g���N�^
	GameManager() {};
	~GameManager() {};

	//������
	void Init(int mapdata[][40]);

	//�X�V
	void Update(float posx, float posy);

	//�`��
	void Draw();

	//----------�ȉ��A�@�\�ʊ֐�----------//
	
	/// <summary>
	/// <para>���x���̏㏸�ƁA����ɔ�����Փx�㏸���s��</para>
	/// <para>���x���̏㏸����������ōs��</para>
	/// </summary>
	private : void LevelUP();

};

//���l�`��֐�

