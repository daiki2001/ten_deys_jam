#include "./../Header/Timer.h"
#include <DxLib.h>
#include <cmath>

int Timer::numGraph[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int Timer::dotGraph = 0;

void Timer::Init()
{
	//総合時間を初期化
	time = 30.0;
	//加算時間初期化
	addTime = 10.0f;
	//ペナルティ猶予初期化
	penaltyDef = 10.0f;
	//フレーム初期化
	timerFrame = 0;
	//リソース読み込み
	LoadDivGraph("Resources/num.png", 10, 10, 1, 16, 16, numGraph);
	dotGraph = LoadGraph("Resources/dot.png");
}

void Timer::Reset(int resetTime)
{
	time = resetTime;
}

void Timer::Add(float resetAdd, float resetPenalty)
{
	//総合時間に加算時間を加算
	time += addTime;
	if (time >= 30.0) {//60秒以上の時
		time = 30.0;
	}

	//加算時間リセット
	addTime = resetAdd;
	//ペナルティ猶予をリセット
	penaltyDef = resetPenalty;
}

void Timer::Update()
{
	//残り秒数を計算
	timerFrame++;

	if (timerFrame % 6 == 0) {//6f毎に

		if (time > 0.0) {//加算時間5以上かつ、制限時間がある
			time -= 0.1;//制限時間が減少
		}
	}
}

void Timer::DrawNum(int tnum, int x, int y, int width, int height)
{
	int i, BeamWidth, xp;

	// Numが十進数で何桁になるか調べる
	BeamWidth = 0;
	for (i = 10; tnum >= i; i *= 10) BeamWidth++;

	// 画面左上にグラフィックで描画
	// x は数字グラフィックを描く矩形の左端の座標です
	xp = BeamWidth * width;

	for (i = 0; i <= BeamWidth; i++)
	{
		// 数字の描画(透過色あり)
		// NumHandle 配列には要素番号０には『０』のグラフィック識別番号が
		// １には『１』のグラフィック識別番号が入っているので、
		// DrawGraph( 0 , 0 , NumHandle[ 0 ] , TRUE ) ; とすれば
		// 『０』のグラフィックを描画できることをお忘れなく
		DrawExtendGraph(x + xp, y, x + xp + width, y + height, numGraph[tnum % 10], TRUE);

		// 描画Ｘ座標を移動
		x -= width;

		// １番下の桁が描画し終わったので一桁下げる
		tnum /= 10;
	}
}

void Timer::DrawFnum(float tnum, int x, int y, int width, int height)
{
	int i, BeamWidth, xp, os;

	//少数描画用オフセット
	os = 6;

	//引数を整数部と小数部に分割
	float inum, fnum;
	fnum = std::modf(tnum, &inum);
	//小数部を10倍してキャスト
	int fn = static_cast<int>(fnum * 10);
	//整数部の桁数を調べる
	BeamWidth = 0;
	int inu = static_cast<int>(inum);
	for (i = 10; inu >= i; i *= 10) BeamWidth++;

	// 画面左上にグラフィックで描画
	// x は数字グラフィックを描く矩形の左端の座標です
	xp = BeamWidth * width;

	for (i = 0; i <= BeamWidth; i++)
	{
		// 数字の描画(透過色あり)
		// NumHandle 配列には要素番号０には『０』のグラフィック識別番号が
		// １には『１』のグラフィック識別番号が入っているので、
		// DrawGraph( 0 , 0 , NumHandle[ 0 ] , TRUE ) ; とすれば
		// 『０』のグラフィックを描画できることをお忘れなく

		if (i == 0) {
			DrawExtendGraph(x + xp, y, x + xp + width, y + height, numGraph[inu % 10], TRUE);
			DrawExtendGraph(x + xp + width + os - (width / 4) / 2, y + (height * 3 / 4), x + xp + width + os + (width / 4) / 2, y + (height), dotGraph, TRUE);
			DrawExtendGraph(x + xp + width + os * 2, y, (x + xp + width + os * 2) + width, y + height, numGraph[fn % 10], TRUE);
		}
		else
		{
			DrawExtendGraph(x + xp, y, x + xp + width, y + height, numGraph[inu % 10], TRUE);
		}

		// 描画Ｘ座標を移動
		x -= width;

		// １番下の桁が描画し終わったので一桁下げる
		inu /= 10;
	}
}

void Timer::Draw()
{
	//正式表示
	if (time > 10.0) {
		DrawFnum(time, 688, 100, 48, 48);
	}
	else {
		DrawFnum(time, 712, 100, 48, 48);
	}
	DrawFnum(addTime, 788, 202, 16, 16);

#ifdef _DEBUG
	//デバッグ用表示
	//DrawFormatString(650, 0, GetColor(255, 255, 255),  "time       : %0.1f", time);
	//DrawFormatString(650, 15, GetColor(255, 255, 255), "addTime    : %0.1f", addTime);
	//DrawFormatString(650, 30, GetColor(255, 255, 255), "penaltyDef : %0.1f", penaltyDef);
	//DrawFormatString(650, 45, GetColor(255, 255, 255), "timerFrame : %0.1f", timerFrame);

#endif


}