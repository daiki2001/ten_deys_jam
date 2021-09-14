#pragma once

class Input final
{
public:
	static char keys[256];
	static char oldkeys[256];

private:
	// �R���X�g���N�^�ƃf�X�g���N�^��private��
	Input() {};
	~Input() {};

public:
	Input(const Input& obj) = delete; //�R�s�[�R���X�g���N�^�̖�����
	Input& operator=(const Input& obj) = delete; //������Z�q�̖�����

	// ���͂̍X�V
	static void Updata();

	// �L�[�������Ă��邩�ǂ����̔���
	static bool IsKey(int keyCode);
	// �L�[���������u�Ԃ��ǂ����̔���
	static bool IsKeyTrigger(int keyCode);
	// �L�[�𗣂����u�Ԃ��ǂ����̔���
	static bool IsKeyReturn(int keyCode);
};
