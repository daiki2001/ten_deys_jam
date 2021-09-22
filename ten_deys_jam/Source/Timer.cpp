#include "./../Header/Timer.h"
#include <DxLib.h>
#include <cmath>

int Timer::numGraph[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int Timer::dotGraph = 0;

void Timer::Init()
{
	//�������Ԃ�������
	time = 30.0;
	//���Z���ԏ�����
	addTime = 10.0f;
	//�y�i���e�B�P�\������
	penaltyDef = 10.0f;
	//�t���[��������
	timerFrame = 0;
	//���\�[�X�ǂݍ���
	LoadDivGraph("Resources/num.png", 10, 10, 1, 16, 16, numGraph);
	dotGraph = LoadGraph("Resources/dot.png");
}

void Timer::Reset(int resetTime)
{
	time = resetTime;
}

void Timer::Add(float resetAdd, float resetPenalty)
{
	//�������Ԃɉ��Z���Ԃ����Z
	time += addTime;
	if (time >= 30.0) {//60�b�ȏ�̎�
		time = 30.0;
	}

	//���Z���ԃ��Z�b�g
	addTime = resetAdd;
	//�y�i���e�B�P�\�����Z�b�g
	penaltyDef = resetPenalty;
}

void Timer::Update()
{
	//�c��b�����v�Z
	timerFrame++;

	if (timerFrame % 6 == 0) {//6f����

		if (time > 0.0) {//���Z����5�ȏォ�A�������Ԃ�����
			time -= 0.1;//�������Ԃ�����
		}
	}
}

void Timer::DrawNum(int tnum, int x, int y, int width, int height)
{
	int i, BeamWidth, xp;

	// Num���\�i���ŉ����ɂȂ邩���ׂ�
	BeamWidth = 0;
	for (i = 10; tnum >= i; i *= 10) BeamWidth++;

	// ��ʍ���ɃO���t�B�b�N�ŕ`��
	// x �͐����O���t�B�b�N��`����`�̍��[�̍��W�ł�
	xp = BeamWidth * width;

	for (i = 0; i <= BeamWidth; i++)
	{
		// �����̕`��(���ߐF����)
		// NumHandle �z��ɂ͗v�f�ԍ��O�ɂ́w�O�x�̃O���t�B�b�N���ʔԍ���
		// �P�ɂ́w�P�x�̃O���t�B�b�N���ʔԍ��������Ă���̂ŁA
		// DrawGraph( 0 , 0 , NumHandle[ 0 ] , TRUE ) ; �Ƃ����
		// �w�O�x�̃O���t�B�b�N��`��ł��邱�Ƃ����Y��Ȃ�
		DrawExtendGraph(x + xp, y, x + xp + width, y + height, numGraph[tnum % 10], TRUE);

		// �`��w���W���ړ�
		x -= width;

		// �P�ԉ��̌����`�悵�I������̂ňꌅ������
		tnum /= 10;
	}
}

void Timer::DrawFnum(float tnum, int x, int y, int width, int height)
{
	int i, BeamWidth, xp, os;

	//�����`��p�I�t�Z�b�g
	os = 6;

	//�����𐮐����Ə������ɕ���
	float inum, fnum;
	fnum = std::modf(tnum, &inum);
	//��������10�{���ăL���X�g
	int fn = static_cast<int>(fnum * 10);
	//�������̌����𒲂ׂ�
	BeamWidth = 0;
	int inu = static_cast<int>(inum);
	for (i = 10; inu >= i; i *= 10) BeamWidth++;

	// ��ʍ���ɃO���t�B�b�N�ŕ`��
	// x �͐����O���t�B�b�N��`����`�̍��[�̍��W�ł�
	xp = BeamWidth * width;

	for (i = 0; i <= BeamWidth; i++)
	{
		// �����̕`��(���ߐF����)
		// NumHandle �z��ɂ͗v�f�ԍ��O�ɂ́w�O�x�̃O���t�B�b�N���ʔԍ���
		// �P�ɂ́w�P�x�̃O���t�B�b�N���ʔԍ��������Ă���̂ŁA
		// DrawGraph( 0 , 0 , NumHandle[ 0 ] , TRUE ) ; �Ƃ����
		// �w�O�x�̃O���t�B�b�N��`��ł��邱�Ƃ����Y��Ȃ�

		if (i == 0) {
			DrawExtendGraph(x + xp, y, x + xp + width, y + height, numGraph[inu % 10], TRUE);
			DrawExtendGraph(x + xp + width + os - (width / 4) / 2, y + (height * 3 / 4), x + xp + width + os + (width / 4) / 2, y + (height), dotGraph, TRUE);
			DrawExtendGraph(x + xp + width + os * 2, y, (x + xp + width + os * 2) + width, y + height, numGraph[fn % 10], TRUE);
		}
		else
		{
			DrawExtendGraph(x + xp, y, x + xp + width, y + height, numGraph[inu % 10], TRUE);
		}

		// �`��w���W���ړ�
		x -= width;

		// �P�ԉ��̌����`�悵�I������̂ňꌅ������
		inu /= 10;
	}
}

void Timer::Draw()
{
	//�����\��
	if (time > 10.0) {
		DrawFnum(time, 688, 100, 48, 48);
	}
	else {
		DrawFnum(time, 712, 100, 48, 48);
	}
	DrawFnum(addTime, 788, 202, 16, 16);

#ifdef _DEBUG
	//�f�o�b�O�p�\��
	//DrawFormatString(650, 0, GetColor(255, 255, 255),  "time       : %0.1f", time);
	//DrawFormatString(650, 15, GetColor(255, 255, 255), "addTime    : %0.1f", addTime);
	//DrawFormatString(650, 30, GetColor(255, 255, 255), "penaltyDef : %0.1f", penaltyDef);
	//DrawFormatString(650, 45, GetColor(255, 255, 255), "timerFrame : %0.1f", timerFrame);

#endif


}