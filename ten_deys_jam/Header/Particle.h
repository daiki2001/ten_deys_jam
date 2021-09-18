#pragma once
#include <utility>
#include <tuple>

//パーティクル構造体
typedef struct Particle {
	float posX , posY;  //座標
	float width, height;//横、縦幅
	float vecX, vecY;   //移動ベクトル
	int   param;        //ブレンドパラメータ
	std:: tuple<int, int, int> rgb;//輝度RGB値
	int   frame;     //経過フレーム
	bool  isAlive;   //描画フラグ
	Particle() {//生成時に初期化
		posX  = 0,   posY = 0;
		width = 0, height = 0;
		vecX  = 0;   vecY = 0;
		param = 255;//デフォルト値
		rgb   = std::make_tuple<int, int, int>(255, 255, 255);//デフォルト値
		frame = 0;
		isAlive = false;
	}
};

/// <summary>
/// パーティクル初期化
/// </summary>
/// <param name="p"> 初期化するパーティクルの参照</param>
/// <param name="px"> x座標</param>
/// <param name="py"> y座標</param>
/// <param name="vx"> ベクトルx</param>
/// <param name="vy"> ベクトルy</param>
/// <param name="w"> 横幅</param>
/// <param name="h"> 縦幅</param>
/// <param name="param"> 描画パラメータ</param>
/// <param name="rgb"> 輝度パラメータ</param>
inline void InitParticle(Particle &p, float px, float py, float vx, float vy, float w, float h, int param, std::tuple<int, int, int> rgb) {
	//座標系
	p.posX = px;
	p.posY = py;
	p.vecX = vx;
	p.vecY = vy;
	p.width = w;
	p.height = h;
	//描画パラメータ
	p.param = param;
	p.rgb = rgb;
	//その他
	p.frame = 0;
	p.isAlive = false;
};


