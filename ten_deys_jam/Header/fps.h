#pragma once

//FPS�Ǘ��N���X
//�V���O���g���p�^�[���̗p
class fps final
{
	static int frame;
	static int mStartTime;         //����J�n����
	static int mCount;             //�J�E���^
	static float mFps;             //fps
	static const int N = 60;//���ς����T���v����
	static const int FPS = 60;	//�ݒ肵��FPS

private:
	fps();
	~fps() {};

public:
	fps(const fps &obj) = delete;//�R�s�[�R���X�g���N�^����
	fps &operator=(const fps &obj) = delete; //������Z�q�̖���

	static int GetFrameCount();

	static int GetFrame();

	static void Update();

	static void Draw(int x, int y);

	static void Wait();


};

