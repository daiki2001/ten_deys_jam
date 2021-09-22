#include "./../Header/Goal.h"
#include "DxLib.h"

void Goal::Init()
{
	//リソースのロード
	LoadDivGraph("Resources/flag.png", 6, 6, 1, 36, 36, flagGraph);
	LoadDivGraph("Resources/effect1.png", 6, 6, 1, 36, 36, effectGraph);
}

void Goal::Update()
{
	frame++;
	if (frame % 6 == 0) {//6f毎にアニメーション進行
		gnum++;
		if (gnum > 5) {//アニメーションの終わりでループ
			gnum = 0;
		}
	}
}

void Goal::Draw()
{
	//DrawBox(pos.first * 16, 60 + pos.second * 16, pos.first * 16 + 16, 60 + pos.second * 16 + 16, GetColor(250, 210, 60), true);
	//エフェクト描画
	DrawGraph((pos.first * 16) - 10, (pos.second * 16) - 10, effectGraph[gnum], TRUE);
	//旗描画
	DrawExtendGraph((pos.first * 16) + 8 - 27 + 10, (pos.second * 16) + 8 - 27 - 10, 
					(pos.first * 16) + 8 + 27 + 10, (pos.second * 16) + 8 + 27 - 10, flagGraph[gnum], TRUE);
	
}
