#include "./../Header/Result.h"
#include <Dxlib.h>
#include "./../Header/Timer.h"
#include "./../Header/Input.h"
#include <math.h>

int Result::highScore[3] = { 0, 0, 0 };

Result::Result() :
	score(0),
	isGameSet(false),
	resultGraph{},
	sceneSelect(0),
	animation(0),
	scoreSE{},
	selectSE{},
	decideSE{}
{
}

void Result::Init()
{
	score = 0;
	isGameSet = false;
	sceneSelect = 0;
	animation = 0;

	LoadDivGraph("Resources/result.png", 2, 2, 1, 640, 700, resultGraph);

	scoreSE.Init("Resources/se10.mp3", 0x80);
	selectSE.Init("Resources/se10.mp3", 0x80);
	decideSE.Init("Resources/se10.mp3", 0x80);
}

int Result::AddScore(int goalCount, int level, float time)
{
	int add = (goalCount + level) * 100 + time * 10;
	score += add;
	return add;
}

void Result::GameSet(ISceneChanger* changer)
{
	if (isGameSet == false)
	{
		// ハイスコアの更新
		isGameSet = true;
		int keepScore = score;

		for (size_t i = 0; i < 3; i++)
		{
			if (score > highScore[i])
			{
				int temp = highScore[i];
				highScore[i] =keepScore;
				keepScore = temp;
			}
		}
	}
	else
	{
		animation++;
	}

	if (animation < 45)
	{
		scoreSE.Play(DX_PLAYTYPE_BACK);
	}

	if (Input::IsKey(KEY_INPUT_UP) == true || Input::IsKey(KEY_INPUT_W) == true)
	{
		sceneSelect = 0;
		selectSE.Play(DX_PLAYTYPE_BACK);
	}
	if (Input::IsKey(KEY_INPUT_DOWN) == true || Input::IsKey(KEY_INPUT_S) == true)
	{
		sceneSelect = 1;
		selectSE.Play(DX_PLAYTYPE_BACK);
	}
	if (Input::IsKeyTrigger(KEY_INPUT_SPACE) == true)
	{
		if (sceneSelect == 0)
		{
			// リトライ
			changer->ChangeScene(eScene_Game);
		}
		else
		{
			// タイトルに戻る
			changer->ChangeScene(eScene_Menu);
		}
		decideSE.Play(DX_PLAYTYPE_NORMAL);
	}
}

void Result::Draw(bool gameSet, int goalCount, int level)
{
	int num = 0; //scoreの桁数

	// 桁数を求める
	for (num = 0; score / pow(10, num) >= 1; num++);
	if (score == 0)
	{
		// scoreが0の時はfor文を通らない
		num = 1;
	}

	Timer::DrawNum(score, 764 - num * 12, 327, 24, 24);

	if (gameSet == false)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x80);
		DrawBox(0, 0, 890, 640, GetColor(0x00, 0x00, 0x00), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0x80);

		if (animation < 10)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 25 * animation);

			DrawGraph(0, -30, resultGraph[sceneSelect], true);

			Timer::DrawNum(0, 313, 216 - 30, 16, 16);
			Timer::DrawNum(0, 313, 252 - 30, 16, 16);
			Timer::DrawNum(0, 313, 288 - 30, 16, 16);

			for (size_t i = 0; i < 3; i++)
			{
				Timer::DrawNum(0, 302, i * 31 + 362, 16, 16);
			}

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0x80);
		}
		else if (animation < 20)
		{
			DrawGraph(0, -30, resultGraph[sceneSelect], true);

			Timer::DrawNum(goalCount / (20 - animation), 313, 216 - 30, 16, 16);
			Timer::DrawNum(0, 313, 252 - 30, 16, 16);
			Timer::DrawNum(0, 313, 288 - 30, 16, 16);

			for (size_t i = 0; i < 3; i++)
			{
				Timer::DrawNum(0, 302, i * 31 + 362, 16, 16);
			}
		}
		else if (animation < 30)
		{
			DrawGraph(0, -30, resultGraph[sceneSelect], true);

			Timer::DrawNum(goalCount, 313, 216 - 30, 16, 16);
			Timer::DrawNum(level / (30 - animation), 313, 252 - 30, 16, 16);
			Timer::DrawNum(0, 313, 288 - 30, 16, 16);

			for (size_t i = 0; i < 3; i++)
			{
				Timer::DrawNum(0, 302, i * 31 + 362, 16, 16);
			}
		}
		else if (animation < 40)
		{
			DrawGraph(0, -30, resultGraph[sceneSelect], true);

			Timer::DrawNum(goalCount, 313, 216 - 30, 16, 16);
			Timer::DrawNum(level, 313, 252 - 30, 16, 16);
			Timer::DrawNum(score / (40 - animation), 313, 288 - 30, 16, 16);

			for (size_t i = 0; i < 3; i++)
			{
				Timer::DrawNum(0, 302, i * 31 + 362, 16, 16);
			}
		}
		else if (animation < 45)
		{
			DrawGraph(0, -30, resultGraph[sceneSelect], true);

			Timer::DrawNum(goalCount, 313, 216 - 30, 16, 16);
			Timer::DrawNum(level, 313, 252 - 30, 16, 16);
			Timer::DrawNum(score, 313, 288 - 30, 16, 16);

			for (size_t i = 0; i < 3; i++)
			{
				Timer::DrawNum(highScore[i] / (45 - animation), 302, i * 31 + 362, 16, 16);
			}
		}
		else
		{
			DrawGraph(0, -30, resultGraph[sceneSelect], true);

			Timer::DrawNum(goalCount, 313, 216 - 30, 16, 16);
			Timer::DrawNum(level, 313, 252 - 30, 16, 16);
			Timer::DrawNum(score, 313, 288 - 30, 16, 16);

			for (size_t i = 0; i < 3; i++)
			{
				Timer::DrawNum(highScore[i], 302, i * 31 + 362, 16, 16);
			}
		}
	}
}
