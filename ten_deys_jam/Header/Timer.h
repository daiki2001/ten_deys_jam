#pragma once
#include "DxLib.h"

#define GAME_TIMER_DEF 60

#define NUM_WIDTH (16)
#define NUM_HEIGHT (16)

//���Ԃ��Ǘ�����N���X�i�X�P���g���R�[�h�j
/*
�E�d�l
 6F �o�� 0.1�b����
 �\��������3���i00.0sec�j

 �E���ł�DrawFormatString�ł���
 �E���������Ń��\�[�X���g�p����ꍇ�̏������l���Ă����ė~����
 �E�]�͂�����Ȃ烊�\�[�X�Ή������Ă����Ɗ�����
*/

class Timer
{
public:
	//��������
	float time;
	//���Z����
	float addTime;
	//���Z���Ԍ����P�\
	float penaltyDef;
	//�t���[��
	int timerFrame;

	//�摜�`��p


	//�摜���g���ꍇ�̃��\�[�X
	int numGraph[10];


public:
	//�R���X�g���N�^
	Timer() {};

	//�������i�����o�ϐ��̃��Z�b�g�A�摜�̃��[�h�j
	void Init();

	//���Z�b�g�i�^�C�}�[�̃��Z�b�g�j
	void Reset(int resetTime);

	/// <summary>
	/// <para>���Z�^���Z�b�g�����i�S�[���Փˎ����s�j</para>
	/// �������Ԃɉ��Z���Ԃ����Z
	/// </summary>
	/// <param name="resetAdd"> ���Z���Ԃ̃��Z�b�g�l</param>
	/// <param name="resetPenalty"> �y�i���e�B�P�\���Ԃ̃��Z�b�g�l</param>
	void Add(float resetAdd,float resetPenalty);

	//�X�V�i�J�E���g�_�E���j
	void Update();

	/// <summary>
	/// <para>���l�`��֐�</para>
	/// <para>�������g�p����ꍇ�A�������𐮐��ϊ���</para>
	/// <para>�ʂ̐��l�Ƃ��Ĉ�������</para>
	/// </summary>
	/// <param name="tnum"> �`�悷�鐔�l</param>
	/// <param name="x"> �`�悷�鍶��x���W</param>
	/// <param name="y"> �`�悷�鍶��y���W</param>
	void DrawNum(int tnum,int x,int y);

	//�`��
	void Draw();

};

