#include "./../Header/Goal.h"
#include "DxLib.h"

void Goal::Init()
{
	//���\�[�X�̃��[�h
	LoadDivGraph("Resources/flag.png", 6, 6, 1, 36, 36, flagGraph);
	LoadDivGraph("Resources/effect1.png", 6, 6, 1, 36, 36, effectGraph);
}

void Goal::Update()
{
	frame++;
	if (frame % 6 == 0) {//6f���ɃA�j���[�V�����i�s
		gnum++;
		if (gnum > 5) {//�A�j���[�V�����̏I���Ń��[�v
			gnum = 0;
		}
	}
}

void Goal::Draw()
{
	//DrawBox(pos.first * 16, 60 + pos.second * 16, pos.first * 16 + 16, 60 + pos.second * 16 + 16, GetColor(250, 210, 60), true);
	//�G�t�F�N�g�`��
	DrawGraph((pos.first * 16) - 10, (pos.second * 16) - 10, effectGraph[gnum], TRUE);
	//���`��
	DrawExtendGraph((pos.first * 16) + 8 - 27 + 10, (pos.second * 16) + 8 - 27 - 10, 
					(pos.first * 16) + 8 + 27 + 10, (pos.second * 16) + 8 + 27 - 10, flagGraph[gnum], TRUE);
	
}
