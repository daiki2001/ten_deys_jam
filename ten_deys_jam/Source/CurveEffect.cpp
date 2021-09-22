#include "./../Header/CurveEffect.h"
#include <DxLib.h>
#include <math.h>

CurveParticle::CurveParticle() :
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

CurveEffect::CurveEffect() :
	curveParticle{},
	x{},
	y{},
	direction{},
	rightCurveFlag(false),
	isEnd(true)
{
}

void CurveEffect::Init(int x, int y, int direction, bool rightCurveFlag)
{
	if (isEnd == false)
	{
		// ���o���I�����Ă��Ȃ������珉�������Ȃ�
		return;
	}

	isEnd = false;
	this->x = x + 8;
	this->y = y + 8;
	this->direction = direction;
	this->rightCurveFlag = rightCurveFlag;

	for (size_t i = 0; i < particleNum; i++)
	{
		curveParticle[i] = CurveParticle();
	}
}

void CurveEffect::Update()
{
	if (isEnd == true)
	{
		// ���o���s���Ă��Ȃ�������X�V�����Ȃ�
		return;
	}

	bool isCreate = false;

	for (int i = 0; i < particleNum; i++)
	{
		if (curveParticle[i].isAlive == true)
		{
			curveParticle[i].posX += curveParticle[i].vecX;
			curveParticle[i].posY += curveParticle[i].vecY;
			curveParticle[i].param -= curveParticle[i].frame * 3.5;
			curveParticle[i].frame++;
		}

		if (curveParticle[i].param < 0 && curveParticle[i].isAlive == true && i == particleNum - 1)
		{
			//���o�̏I��
			isEnd = true;
		}

		// �p�[�e�B�N���̐����������̂P
		if (curveParticle[i].isAlive == false && isCreate == false)
		{
			int n = (particleNum + (i - 1)) % particleNum;

			// �p�[�e�B�N���̐����������̂Q
			if ((curveParticle[n].frame % 1 == 0) && (curveParticle[n].frame != curveParticle[i].frame || i == 0))
			{
				// �p�[�e�B�N���̐���
				Create(i);
				isCreate = true;
			}
		}
	}
}

void CurveEffect::Draw(int offsetX, int offsetY)
{
	if (isEnd == true)
	{
		// ���o���s���Ă��Ȃ�������`������Ȃ�
		return;
	}

	for (size_t i = 0; i < particleNum; i++)
	{
		// turnParticle[i].param�ɍ��킹�ăA���t�@�u�����h���|����
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, curveParticle[i].param);

		DrawCircle(curveParticle[i].posX + offsetX, curveParticle[i].posY + offsetY, curveParticle[i].r, GetColor(0xff, 0xff, 0xff), true);
	}
	// �u�����h���[�h���m�[�u�����h�ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0x00);
}

bool CurveEffect::GetEndFlag()
{
	return isEnd;
}

void CurveEffect::Create(int n)
{
	if (rightCurveFlag == true)
	{
		curveParticle[n].posX = 8 * sin((DX_PI / particleNum * (particleNum - n)) + (2 * DX_PI / 8 * (direction * 2 + 3))) + x;
		curveParticle[n].posY = 8 * cos((DX_PI / particleNum * (particleNum - n)) + (2 * DX_PI / 8 * (direction * 2 + 3))) + y;
	}
	else
	{
		curveParticle[n].posX = 8 * sin((DX_PI / particleNum * n) + (2 * DX_PI / 8 * (direction * 2 + 1))) + x;
		curveParticle[n].posY = 8 * cos((DX_PI / particleNum * n) + (2 * DX_PI / 8 * (direction * 2 + 1))) + y;
	}
	curveParticle[n].r = n * 2 + 4;
	curveParticle[n].param = 0xC0;
	curveParticle[n].frame = 0;
	curveParticle[n].isAlive = true;
}
