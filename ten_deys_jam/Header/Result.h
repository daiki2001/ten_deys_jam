#pragma once
#include "ISceneChanger.h"
#include "Sound.h"

class Result
{
public:
	int score;               //�X�R�A
	static int highScore[3]; //�n�C�X�R�A
	//int scoreGraph;          //�uScore:�v�̕����摜�f�[�^
	bool isGameSet;          //�Q�[�����I���������ǂ���
	int resultGraph[2];      //���U���g��ʂ̉摜�f�[�^
	int sceneSelect;         //���U���g��ʂ̉摜�f�[�^�̗v�f�ԍ�
	int animation;           //���U���g��ʂ̐����̉��o

	Sound scoreSE;  //�X�R�A�\����SE
	Sound selectSE; //�I������SE
	Sound decideSE; //���莞��SE

	Result(); //�R���X�g���N�^
	~Result() {};

	// ������
	void Init();
	/// <summary>
	/// �X�R�A�̉��Z
	/// </summary>
	/// <param name="goalCount"> �S�[�������� </param>
	/// <param name="level"> ���̃��x�� </param>
	/// <param name="time"> �S�[�����̎c�莞�� </param>
	/// <returns> ���Z�����X�R�A </returns>
	int AddScore(int goalCount, int level, float time);
	/// <summary>
	/// �Q�[���I�����̏���
	/// </summary>
	/// <param name="changer"> �V�[���؂�ւ����V�[���}�l�[�W���[�ɓ`����ϐ� </param>
	void GameSet(ISceneChanger* changer);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name="gameSet"> �Q�[���������Ă��邩�ǂ��� </param>
	/// <param name="goalCount"> �S�[�������� </param>
	/// <param name="level"> ���B�������x�� </param>
	void Draw(bool gameSet, int goalCount = 0, int level = 0);
};
