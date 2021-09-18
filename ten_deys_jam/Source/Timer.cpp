#include "./../Header/Timer.h"

void Timer::Init()
{
	//�������Ԃ�������
	time = 60.0;
	//���Z���ԏ�����
	addTime = 15.0f;
	//�y�i���e�B�P�\������
	penaltyDef = 10.0f;
	//�t���[��������
	timerFrame = 0;
	//���\�[�X�ǂݍ���
	LoadDivGraph("Resources/num.png", 10, 10, 1, 16, 16, numGraph);
}

void Timer::Reset(int resetTime)
{
	time = resetTime;
}

void Timer::Add(float resetAdd, float resetPenalty)
{
	//�������Ԃɉ��Z���Ԃ����Z
	time += addTime;
	if (time >= 60.0) {//60�b�ȏ�̎�
		time = 60.0;
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
		//���Z���Ԃ�����
		if (addTime > 5.1) { addTime -= 0.1; }

		if (addTime <= 5.1 && time > 0.0) {//���Z����5�ȏォ�A�������Ԃ�����
			time -= 0.1;//�������Ԃ�����
		}
	}
}

void Timer::DrawNum(int tnum, int x, int y)
{
	int i, BeamWidth, xp;

	// Num���\�i���ŉ����ɂȂ邩���ׂ�
	BeamWidth = 0;
	for (i = 10; tnum >= i; i *= 10) BeamWidth++;

	// ��ʍ���ɃO���t�B�b�N�ŕ`��
	// x �͐����O���t�B�b�N��`����`�̍��[�̍��W�ł�
	xp = BeamWidth * NUM_WIDTH;

	for (i = 0; i <= BeamWidth; i++)
	{
		// �����̕`��(���ߐF����)
		// NumHandle �z��ɂ͗v�f�ԍ��O�ɂ́w�O�x�̃O���t�B�b�N���ʔԍ���
		// �P�ɂ́w�P�x�̃O���t�B�b�N���ʔԍ��������Ă���̂ŁA
		// DrawGraph( 0 , 0 , NumHandle[ 0 ] , TRUE ) ; �Ƃ����
		// �w�O�x�̃O���t�B�b�N��`��ł��邱�Ƃ����Y��Ȃ�
		DrawGraph(x + xp, y, numGraph[tnum % 10], TRUE);

		// �`��w���W���ړ�
		x -= NUM_WIDTH;

		// �P�ԉ��̌����`�悵�I������̂ňꌅ������
		tnum /= 10;
	}
}

void Timer::Draw()
{
	//�����\��
	DrawNum(static_cast<int>(time * 10), 0, 1);
	DrawNum(static_cast<int>(addTime * 10), 100, 1);

	
#ifdef _DEBUG
	//�f�o�b�O�p�\��
	//DrawFormatString(650, 0, GetColor(255, 255, 255),  "time       : %0.1f", time);
	//DrawFormatString(650, 15, GetColor(255, 255, 255), "addTime    : %0.1f", addTime);
	//DrawFormatString(650, 30, GetColor(255, 255, 255), "penaltyDef : %0.1f", penaltyDef);
	//DrawFormatString(650, 45, GetColor(255, 255, 255), "timerFrame : %0.1f", timerFrame);

#endif


}