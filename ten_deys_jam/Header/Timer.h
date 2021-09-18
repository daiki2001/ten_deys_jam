#pragma once
#include "DxLib.h"

#define GAME_TIMER_DEF 60

#define NUM_WIDTH (16)
#define NUM_HEIGHT (16)

//時間を管理するクラス（スケルトンコード）
/*
・仕様
 6F 経過 0.1秒減少
 表示桁数は3桁（00.0sec）

 ・α版はDrawFormatStringでおｋ
 ・ただしβでリソースを使用する場合の処理を考えておいて欲しい
 ・余力があるならリソース対応させてくれると嬉しい
*/

class Timer
{
public:
	//総合時間
	float time;
	//加算時間
	float addTime;
	//加算時間減少猶予
	float penaltyDef;
	//フレーム
	int timerFrame;

	//画像描画用


	//画像を使う場合のリソース
	int numGraph[10];


public:
	//コンストラクタ
	Timer() {};

	//初期化（メンバ変数のリセット、画像のロード）
	void Init();

	//リセット（タイマーのリセット）
	void Reset(int resetTime);

	/// <summary>
	/// <para>加算型リセット処理（ゴール衝突時実行）</para>
	/// 総合時間に加算時間を加算
	/// </summary>
	/// <param name="resetAdd"> 加算時間のリセット値</param>
	/// <param name="resetPenalty"> ペナルティ猶予時間のリセット値</param>
	void Add(float resetAdd,float resetPenalty);

	//更新（カウントダウン）
	void Update();

	/// <summary>
	/// <para>数値描画関数</para>
	/// <para>少数を使用する場合、少数桁を整数変換し</para>
	/// <para>別の数値として扱うこと</para>
	/// </summary>
	/// <param name="tnum"> 描画する数値</param>
	/// <param name="x"> 描画する左上x座標</param>
	/// <param name="y"> 描画する左上y座標</param>
	void DrawNum(int tnum,int x,int y);

	//描画
	void Draw();

};

