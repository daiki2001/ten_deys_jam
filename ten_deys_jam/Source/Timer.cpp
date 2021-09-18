#include "./../Header/Timer.h"

void Timer::Init()
{
	//総合時間を初期化
	time = 60.0;
	//加算時間初期化
	addTime = 15.0f;
	//ペナルティ猶予初期化
	penaltyDef = 10.0f;
	//フレーム初期化
	timerFrame = 0;
	//リソース読み込み
	LoadDivGraph("Resources/num.png", 10, 10, 1, 16, 16, numGraph);
}

void Timer::Reset(int resetTime)
{
	time = resetTime;
}

void Timer::Add(float resetAdd, float resetPenalty)
{
	//総合時間に加算時間を加算
	time += addTime;
	if (time >= 60.0) {//60秒以上の時
		time = 60.0;
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
		//加算時間が減少
		if (addTime > 5.1) { addTime -= 0.1; }

		if (addTime <= 5.1 && time > 0.0) {//加算時間5以上かつ、制限時間がある
			time -= 0.1;//制限時間が減少
		}
	}
}

void Timer::DrawNum(int tnum, int x, int y)
{
	int i, BeamWidth, xp;

	// Numが十進数で何桁になるか調べる
	BeamWidth = 0;
	for (i = 10; tnum >= i; i *= 10) BeamWidth++;

	// 画面左上にグラフィックで描画
	// x は数字グラフィックを描く矩形の左端の座標です
	xp = BeamWidth * NUM_WIDTH;

	for (i = 0; i <= BeamWidth; i++)
	{
		// 数字の描画(透過色あり)
		// NumHandle 配列には要素番号０には『０』のグラフィック識別番号が
		// １には『１』のグラフィック識別番号が入っているので、
		// DrawGraph( 0 , 0 , NumHandle[ 0 ] , TRUE ) ; とすれば
		// 『０』のグラフィックを描画できることをお忘れなく
		DrawGraph(x + xp, y, numGraph[tnum % 10], TRUE);

		// 描画Ｘ座標を移動
		x -= NUM_WIDTH;

		// １番下の桁が描画し終わったので一桁下げる
		tnum /= 10;
	}
}

void Timer::Draw()
{
	//正式表示
	DrawNum(static_cast<int>(time * 10), 0, 1);
	DrawNum(static_cast<int>(addTime * 10), 100, 1);

	
#ifdef _DEBUG
	//デバッグ用表示
	//DrawFormatString(650, 0, GetColor(255, 255, 255),  "time       : %0.1f", time);
	//DrawFormatString(650, 15, GetColor(255, 255, 255), "addTime    : %0.1f", addTime);
	//DrawFormatString(650, 30, GetColor(255, 255, 255), "penaltyDef : %0.1f", penaltyDef);
	//DrawFormatString(650, 45, GetColor(255, 255, 255), "timerFrame : %0.1f", timerFrame);

#endif


}