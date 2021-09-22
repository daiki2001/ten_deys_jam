#include "./../Header/GameManager.h"

void GameManager::Init(int mapdata[][40])
{
	//���x��
	level = 1;

	//�^�C�}�[
	timer.Init();
	timer.Reset(20);

	addedTime = 0;
	penalTime = 10.0;
	bonusTime = 15.0;//������15�b

	//�S�[���Ǘ�
	gmanager.Init(mapdata);
	isHit = false;

	//�S�[���p�[�e�B�N��
	gParticle.Init();

	uiGraph = LoadGraph("Resources/UI.png");
}

void GameManager::Update(float posx,float posy)
{
	if (timer.time > 0) {
		timer.Update();
		gmanager.Update(posx, posy, isHit);
		if (isHit == true) {//�S�[���ƏՓ�
			//���Z����鎞�Ԃ�ێ�
			addedTime = timer.addTime;
			//�^�C�}�[���Z
			timer.Add(bonusTime, penalTime);
			
			LevelUP();//���x���Ǘ�

			//�S�[���p�[�e�B�N������
			gParticle.Spawn(posx + 8, posy + 60 + 8);
			//���Z���ԕ\�����o����
			tx = posx, ty = posy;//���W��ݒ�
			timerParam = 255;//�`��p�����[�^������
		}
	}
	//���Z���ԕ\�����o�͎��ԂɌW��炸�s��
	ty--;
	if (timer.timerFrame % 6 == 0 && timerParam > 0) { timerParam -= 15; }

	//�p�[�e�B�N���X�V
	gParticle.Update();
}

void GameManager::Draw()
{
	DrawGraph(640, 0, uiGraph, true);
	//�^�C�}�[�`��
	timer.Draw();
	//���x���`��
	timer.DrawNum(level, 0, 20, 16, 16);//���ƂŐ��l�`��֐��͕ʂɂ���
	timer.DrawNum(gmanager.goalCount, 100, 20, 16, 16);

	//���Z���ԕ\��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, timerParam);
	timer.DrawNum(addedTime * 10, tx, ty, 16, 16);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	//�S�[���`��
	gmanager.Draw();
	//�p�[�e�B�N���`��
	gParticle.Draw();
}

void GameManager::LevelUP()
{
	if (gmanager.goalCount % 2 == 0) {//2��S�[�����閈
		//���x���㏸
		level++;
		//���Z���Ԃ̌����i����5�b�j
		if (bonusTime > 5.0) {
			bonusTime -= 1.0;
		}
	}
}
