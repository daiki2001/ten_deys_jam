#pragma once

//FPS管理クラス
//シングルトンパターン採用
class fps final
{
	static int frame;
	static int mStartTime;         //測定開始時刻
	static int mCount;             //カウンタ
	static float mFps;             //fps
	static const int N = 60;//平均を取るサンプル数
	static const int FPS = 60;	//設定したFPS

private:
	fps();
	~fps() {};

public:
	fps(const fps &obj) = delete;//コピーコンストラクタ無効
	fps &operator=(const fps &obj) = delete; //代入演算子の無効

	static int GetFrameCount();

	static int GetFrame();

	static void Update();

	static void Draw(int x, int y);

	static void Wait();


};

