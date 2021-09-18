#pragma once
#include <vector>
#include "Goal.h"

using namespace std;

//�S�[���I�u�W�F�N�g���Ǘ�����N���X�B
//�S�[���̊e�폈�����s��

class GoalManager
{
public:
	//�S�[���I�u�W�F�N�g
	Goal goal;
	//���[�h�����}�b�v�̃S�[���ʒu���i�[����R���e�i(x,y)
	vector<pair<int, int>> goalBuffer;
	//�S�[���J�E���^�[
	int goalCount = 0;

	

public:
	//�R���X�g���N�^
	GoalManager() {};

	//�������i�}�b�v�f�[�^��ǂݍ���ŁA�S�[���ʒu�i�[�R���e�i�Ɋi�[�j
	void Init(int mapData[][40]);

	/// <summary>
	/// �X�V����
	/// �v���C���[�ƃS�[���̏Փ˔���
	/// �Փˎ��̃S�[���Đ���
	/// </summary>
	/// <param name="posX">�S�[���Ɣ�������I�u�W�F�N�g��X���W</param>
	/// <param name="posY">�S�[���Ɣ�������I�u�W�F�N�g��Y���W</param>
	///	<param name="isHit">�S�[���Ƃ̏Փ˔����ԋp</param>
	void Update(float posX, float posY, bool &isHit);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

};

