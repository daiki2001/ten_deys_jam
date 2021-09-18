#include "./../Header/fps.h"
#include "DxLib.h"

int   fps::frame = 0;
int   fps::mCount = 0;
int   fps::mStartTime = 0;
float fps::mFps = 0;

fps::fps()
{
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
}

int fps::GetFrameCount()
{
	return mCount;
}

int fps::GetFrame()
{
	return frame;
}

void fps::Update()
{
	if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
	frame++;
}

void fps::Draw(int x, int y)
{
	DrawFormatString(x, y, GetColor(255, 255, 255), "%.1f", mFps);
}

void fps::Wait()
{
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}
