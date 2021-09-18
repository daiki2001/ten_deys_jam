#pragma once

struct CurveParticle
{
	float posX, posY; //座標
	float vecX, vecY; //移動ベクトル
	int   r;          //半径
	int   param;      //ブレンドパラメータ
	int   frame;      //経過フレーム
	bool  isAlive;    //描画フラグ

	CurveParticle(); //コンストラクタ
};

class CurveEffect
{
public:
	static const int particleNum = 5;         //パーティクルの個数
	CurveParticle curveParticle[particleNum]; //パーティクル一粒の情報
	int x, y;                                 //プレイヤーの左上座標(オフセット値無し)
	int direction;                            //プレイヤーが向いている方向
	bool rightCurveFlag;                      //右折かどうか
private:
	bool isEnd; //演出が終了したかどうかのフラグ

public:
	CurveEffect();     //コンストラクタ
	~CurveEffect() {}; //デストラクタ

	// 初期化（x, y:プレイヤーの左上座標(オフセット値無し)、direction:プレイヤーが向いている方向、rightCurveFlag:右折かどうか）
	void Init(int x, int y, int direction, bool rightCurveFlag);
	// 更新
	void Update();
	// 描画（offsetX, offsetY:オフセット値）
	void Draw(int offsetX = 0, int offsetY = 0);

	// 演出が終了しているかどうかを取得する（trueで終了している）
	bool GetEndFlag();
private:
	// パーティクルの生成（n:turnParticleの要素番号）
	void Create(int n);
};
