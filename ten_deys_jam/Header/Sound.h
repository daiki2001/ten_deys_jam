#pragma once

class Sound
{
public:
	int soundHandle; //�T�E���h�n���h��
	bool mute;       //�~���[�g�t���O
private:
	int volume; //���ʁi0x00 ~ 0xFF�j

public:
	Sound();  //�R���X�g���N�^
	~Sound(); //�f�X�g���N�^

	// �������ifilePath:���t�@�C���̃p�X�Avolume:���ʁj
	void Init(const char* filePath, int volume);
	// ���̍Đ��iplayType:�Đ��`���j
	void Play(int playType);
	// ���ʂ̕ύX�ivolume:���ʁj
	void ChangeVolume(int volume);
};
