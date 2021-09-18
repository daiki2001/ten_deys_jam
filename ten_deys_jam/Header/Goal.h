#pragma once
#include <utility>

class Goal
{
public:
	//�S�[���̎��ۂ̈ʒu(�}�b�v�`�b�v���W)(x,y);
	std::pair<int, int> pos = std::make_pair(0, 0);
	//�S�[���摜
	int flagGraph[6];//��
	int effectGraph[6];//�S�[���G�t�F�N�g

	//�o�߃t���[��
	int frame = 0;
	//�`��ԍ�
	int gnum = 0;

public:
	//�R���X�g���N�^
	Goal() {
		Init();
	}

	//������
	void Init();

	//�X�V
	void Update();

	//�`��
	void Draw();

};

