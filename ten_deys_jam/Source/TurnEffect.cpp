#include "./../Header/TurnEffect.h"
#include <DxLib.h>
#include <math.h>

TurnParticle::TurnParticle() :
	posX(0),
	posY(0),
	vecX(0),
	vecY(0),
	r(1),
	param(0),
	frame(0),
	isAlive(false)
{
}

TurnEffect::TurnEffect() :
	turnParticle{},
	x{},
	y{},
	direction{},
	isEnd(true)
{
}

void TurnEffect::Init(int x, int y, int direction)
{
	if (isEnd == false)
	{
		// 演出が終了していなかったら初期化しない
		return;
	}

	isEnd = false;
	this->x = x + 8;
	this->y = y + 8;
	this->direction = direction;

	for (size_t i = 0; i < particleNum; i++)
	{
		turnParticle[i] = TurnParticle();
	}
}

void TurnEffect::Update()
{
	if (isEnd == true)
	{
		// 演出が行われていなかったら更新をしない
		return;
	}

	bool isCreate = false;

	for (int i = 0; i < particleNum; i++)
	{
		if (turnParticle[i].isAlive == true)
		{
			turnParticle[i].posX += turnParticle[i].vecX;
			turnParticle[i].posY += turnParticle[i].vecY;
			turnParticle[i].param -= turnParticle[i].frame * 3.5;
			turnParticle[i].frame++;
		}

		if (turnParticle[i].param < 0 && turnParticle[i].isAlive == true && i == particleNum - 1)
		{
			//演出の終了
			isEnd = true;
		}

		// パーティクルの生成条件その１
		if (turnParticle[i].isAlive == false && isCreate == false)
		{
			int n = (particleNum + (i - 1)) % particleNum;

			// パーティクルの生成条件その２
			if ((turnParticle[n].frame % 1 == 0) && (turnParticle[n].frame != turnParticle[i].frame || i == 0))
			{
				// パーティクルの生成
				Create(i % particleNum);
				isCreate = true;
			}
		}
	}
}

void TurnEffect::Draw(int offsetX, int offsetY)
{
	if (isEnd == true)
	{
		// 演出が行われていなかったら描画をしない
		return;
	}

	for (size_t i = 0; i < particleNum; i++)
	{
		// turnParticle[i].paramに合わせてアルファブレンドを掛ける
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, turnParticle[i].param);

		DrawCircle(turnParticle[i].posX + offsetX, turnParticle[i].posY + offsetY, turnParticle[i].r, GetColor(0xff, 0xff, 0xff), true);
	}
	// ブレンドモードをノーブレンドに戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0x00);
}

bool TurnEffect::GetEndFlag()
{
	return isEnd;
}

void TurnEffect::Create(int n)
{
	turnParticle[n].posX = 8 * sin((DX_PI / particleNum * n) + (2 * DX_PI / 4 * (direction + 1))) + x;
	turnParticle[n].posY = 8 * cos((DX_PI / particleNum * n) + (2 * DX_PI / 4 * (direction + 1))) + y;
	if (n < particleNum / 2)
	{
		turnParticle[n].r = n * 2 + 4;
	}
	else
	{
		turnParticle[n].r = (particleNum - n) * 2 + 4;
	}
	turnParticle[n].param = 0xC0;
	turnParticle[n].frame = 0;
	turnParticle[n].isAlive = true;
}
