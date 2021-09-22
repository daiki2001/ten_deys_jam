#pragma once

struct TurnParticle
{
	float posX, posY; //���W
	float vecX, vecY; //�ړ��x�N�g��
	int   r;          //���a
	int   param;      //�u�����h�p�����[�^
	int   frame;      //�o�߃t���[��
	bool  isAlive;    //�`��t���O

	TurnParticle(); //�R���X�g���N�^
};

class TurnEffect
{
public:
	static const int particleNum = 5;       //�p�[�e�B�N���̌�
	TurnParticle turnParticle[particleNum]; //�p�[�e�B�N���ꗱ�̏��
	int x, y;                               //�v���C���[�̍�����W(�I�t�Z�b�g�l����)
	int direction;                          //�v���C���[�������Ă������
private:
	bool isEnd; //���o���I���������ǂ����̃t���O

public:
	TurnEffect();     //�R���X�g���N�^
	~TurnEffect() {}; //�f�X�g���N�^

	// �������ix, y:�v���C���[�̍�����W(�I�t�Z�b�g�l����)�Adirection:�v���C���[�������Ă�������j
	void Init(int x, int y, int direction);
	// �X�V
	void Update();
	// �`��ioffsetX, offsetY:�I�t�Z�b�g�l�j
	void Draw(int offsetX = 0, int offsetY = 0);

	// ���o���I�����Ă��邩�ǂ������擾����itrue�ŏI�����Ă���j
	bool GetEndFlag();
private:
	// �p�[�e�B�N���̐����in:turnParticle�̗v�f�ԍ��j
	void Create(int n);
};
