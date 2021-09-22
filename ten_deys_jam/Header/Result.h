#pragma once
#include "ISceneChanger.h"
#include "Sound.h"

class Result
{
public:
	int score;               //スコア
	static int highScore[3]; //ハイスコア
	//int scoreGraph;          //「Score:」の文字画像データ
	bool isGameSet;          //ゲームが終了したかどうか
	int resultGraph[2];      //リザルト画面の画像データ
	int sceneSelect;         //リザルト画面の画像データの要素番号
	int animation;           //リザルト画面の数字の演出

	Sound scoreSE;  //スコア表示のSE
	Sound selectSE; //選択時のSE
	Sound decideSE; //決定時のSE

	Result(); //コンストラクタ
	~Result() {};

	// 初期化
	void Init();
	/// <summary>
	/// スコアの加算
	/// </summary>
	/// <param name="goalCount"> ゴールした回数 </param>
	/// <param name="level"> 今のレベル </param>
	/// <param name="time"> ゴール時の残り時間 </param>
	/// <returns> 加算したスコア </returns>
	int AddScore(int goalCount, int level, float time);
	/// <summary>
	/// ゲーム終了時の処理
	/// </summary>
	/// <param name="changer"> シーン切り替えをシーンマネージャーに伝える変数 </param>
	void GameSet(ISceneChanger* changer);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="gameSet"> ゲームが続けているかどうか </param>
	/// <param name="goalCount"> ゴールした回数 </param>
	/// <param name="level"> 到達したレベル </param>
	void Draw(bool gameSet, int goalCount = 0, int level = 0);
};
