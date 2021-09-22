#include "./../Header/GoalManager.h"
#include "./../Header/egudai_CSV.h"
#include "./../Header/NY_random.h"

void GoalManager::Init(int mapData[][40])
{
	//�󂯎�����}�b�v�f�[�^����S�[���ʒu�����o��
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			if (mapData[y][x] != 12 && mapData[y][x] != 0) {//�S�[���\��n�������ꍇ�i�����̐��l��ς���ƁA�S�[�������ʒu�̕ύX�\�j
				//�S�[���\��n�̃}�b�v�`�b�v���W��pair�^�R���e�i�Ɋi�[
				pair<int, int> buff = make_pair(x, y);
				goalBuffer.push_back(buff);
			}
		}
	}
	//�J�E���g������
	goalCount = 0;

	//�S�[���I�u�W�F�N�g�ɃS�[���ʒu��ݒ�
	goal.pos = goalBuffer[NY_random::intrand_sl(goalBuffer.size() - 1, 0)];

}

void GoalManager::Update(float posX, float posY,bool &isHit)
{
	//�v���C���[���W���}�b�v�`�b�v���W�ɕϊ�
	int x = posX / 16;
	int y = posY / 16;//Y��UI�����炷

	//�v���C���[�ƃS�[���̏Փ˔���
	if (x == goal.pos.first && y == goal.pos.second) {//�Փ˂��Ă���
		//�Փˎ��̒ǉ������͂�����
		goalCount++;//�J�E���g���Z

		//�S�[���I�u�W�F�N�g�̍Đݒ�
		goal.pos = goalBuffer[NY_random::intrand_sl(goalBuffer.size() - 1, 0)];
		isHit = true;//�Փ˂�ԋp
	}
	else {
		isHit = false;//��Փ˂�ԋp
	}
	//�S�[���I�u�W�F�N�g�X�V
	goal.Update();
}

void GoalManager::Draw()
{
	//�S�[���I�u�W�F�N�g�̕`��
	goal.Draw();

}
