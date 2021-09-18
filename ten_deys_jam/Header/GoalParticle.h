#pragma once
#include "Particle.h"

#define MAX_GRAIN (60)//�p�[�e�B�N���̍ő吶����

class GoalParticle
{
public:
	//�p�[�e�B�N���̗��i���I�����j
	Particle *grain;
	//�p�[�e�B�N�����\�[�X
	int grainGraph;

public:
	//�R���X�g���N�^
	GoalParticle();
	//�f�X�g���N�^
	~GoalParticle();

	//������
	void Init();

	/// <summary>
	/// �p�[�e�B�N���o���A�`��J�n�i�~�`�ɕ��o�j
	/// </summary>
	/// <param name="x"> �o�����Wx</param>
	/// <param name="y"> �o�����Wy</param>
	void Spawn(float x, float y);

	//�X�V
	void Update();

	//�`��
	void Draw();


};

