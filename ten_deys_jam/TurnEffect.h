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
	static const int particleNum = 5;
	TurnParticle turnParticle[particleNum];
	int x, y;              //�v���C���[�̍�����W(�I�t�Z�b�g�l����)
	int direction;         //�v���C���[�������Ă������
private:
	bool isEnd;

public:
	TurnEffect();
	~TurnEffect() {};

	void Init(int x, int y, int direction);
	void Update();
	void Draw(int offsetX = 0, int offsetY = 0);

	bool GetEndFlag();
private:
	void Create(int n);
};
