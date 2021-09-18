#pragma once
#include "./../Header/GoalParticle.h"
#include "DxLib.h"

GoalParticle::GoalParticle()
{
	//�p�[�e�B�N������
	grain = new Particle[MAX_GRAIN];
	//�p�[�e�B�N�����\�[�X�̓ǂݍ���
}

GoalParticle::~GoalParticle()
{
	delete[] grain;
}

void GoalParticle::Init()
{
	//�p�[�e�B�N���̃p�����[�^�[�̏�����
	for (int i = 0; i < MAX_GRAIN; i++) {
		InitParticle(grain[i], 0, 0, 0, 0, 8, 8, 255, std::make_tuple<int, int, int>(255, 255, 255));
	}
}

void GoalParticle::Spawn(float x, float y)
{
	float rad = (360.0f / MAX_GRAIN);//���̎ˏo�p�x
	rad = rad * (DX_PI / 180);//���W�A���p�ɕϊ�
	for (int i = 0; i < MAX_GRAIN; i++) {//�S�p�[�e�B�N�����o��
		//�������i�o�����W�ƃT�C�Y�ݒ�j
		InitParticle(grain[i], x, y, 0, 0, 4, 4, 255, std::make_tuple<int, int, int>(255, 255, 255));
		//�x�N�g���v�Z(�~����̓_�����߂�v��)
		grain[i].vecX = 10 * cosf(rad * i);
		grain[i].vecY = 10 * sinf(rad * i);
		//�`��t���O�L����
		grain[i].isAlive = true;
	}
}

void GoalParticle::Update()
{
	//�p�[�e�B�N���X�V����
	for (int i = 0; i < MAX_GRAIN; i++) {
		if (grain[i].isAlive == true) {//�p�[�e�B�N�����L���Ȏ�

			grain[i].frame++;
			//���W���ړ�
			grain[i].posX += grain[i].vecX;
			grain[i].posY += grain[i].vecY;

			if (grain[i].frame % 2 == 0) {//2f����
				//�`��p�����[�^����
				grain[i].param -= 5;
			}
			if (grain[i].frame % 102 == 0) {//102f�o�ߎ�
				grain[i].isAlive = false;//�p�[�e�B�N��������
			}
		}
	}

}

void GoalParticle::Draw()
{
	if (grain[0].isAlive == true) {
		for (int i = 0; i < MAX_GRAIN; i++) {
			if (grain[i].isAlive == true) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, grain[i].param);
				DrawCircle(grain[i].posX, grain[i].posY, grain[i].width, GetColor(255, 255, 255));
			}
		}
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}
