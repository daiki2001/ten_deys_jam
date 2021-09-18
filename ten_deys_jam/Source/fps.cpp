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
	if (mCount == 0) { //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60フレーム目なら平均を計算する
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
	int tookTime = GetNowCount() - mStartTime;	//かかった時間
	int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}
