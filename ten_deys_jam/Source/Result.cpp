#include "./../Header/Result.h"
#include <Dxlib.h>
#include "./../Header/Timer.h"
#include "./../Input.h"

int Result::highScore[3] = { 0, 0, 0 };

Result::Result() :
	score(0),
	scoreGraph{},
	isGameSet(false),
	resultGraph{},
	sceneSelect(0)
{
}

void Result::Init()
{
	score = 0;
	isGameSet = false;
	sceneSelect = 0;

	scoreGraph = LoadGraph("Resources/SCORE.png");
	LoadDivGraph("Resources/result.png", 2, 2, 1, 600, 700, resultGraph);
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

	if (Input::IsKey(KEY_INPUT_UP) == true || Input::IsKey(KEY_INPUT_W) == true)
	{
		sceneSelect = 0;
	}
	if (Input::IsKey(KEY_INPUT_DOWN) == true || Input::IsKey(KEY_INPUT_S) == true)
	{
		sceneSelect = 1;
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
	}
}

void Result::Draw(bool gameSet, int goalCount, int level)
{
	if (gameSet == true)
	{
		DrawGraph(200, 0, scoreGraph, true);
		Timer::DrawNum(score, 320, 0);
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x80);
		DrawBox(0, 0, 640, 700, GetColor(0x00, 0x00, 0x00), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0x80);

		DrawGraph(20, 0, resultGraph[sceneSelect], true);

		Timer::DrawNum(goalCount, 320, 236);
		Timer::DrawNum(level, 320, 272);
		Timer::DrawNum(score, 320, 308);

		for (size_t i = 0; i < 3; i++)
		{
			Timer::DrawNum(highScore[i], 320, i * 31 + 392);
		}
	}
}
