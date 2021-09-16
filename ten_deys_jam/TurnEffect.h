#pragma once

struct TurnParticle
{
	float posX, posY; //座標
	float vecX, vecY; //移動ベクトル
	int   r;          //半径
	int   param;      //ブレンドパラメータ
	int   frame;      //経過フレーム
	bool  isAlive;    //描画フラグ

	TurnParticle(); //コンストラクタ
};

class TurnEffect
{
public:
	static const int particleNum = 5;
	TurnParticle turnParticle[particleNum];
	int x, y;              //プレイヤーの左上座標(オフセット値無し)
	int direction;         //プレイヤーが向いている方向
private:
	bool isEnd;

public:
	TurnEffect();
	~TurnEffect() {};

	void Init(int x, int y, int direction);
	void Update();
	void Draw(int offsetX = 0, int offsetY = 0);

	bool GetEndFlag();
private:
	void Create(int n);
};
