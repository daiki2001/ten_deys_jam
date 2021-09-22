#include "./../Header/Sound.h"
#include <DxLib.h>

Sound::Sound() :
	soundHandle(0),
	volume(0),
	mute(false)
{
}

Sound::~Sound()
{
	DeleteSoundMem(soundHandle);
}

void Sound::Init(const char* filePath, int volume)
{
	this->volume = volume;
	this->mute = false;

	this->soundHandle = LoadSoundMem(filePath);
	ChangeVolumeSoundMem(this->volume, soundHandle);
}

void Sound::Play(int playType)
{
	if (CheckSoundMem(soundHandle) == 0)
	{
		// �Đ����ĂȂ�������Đ�
		PlaySoundMem(soundHandle, playType);
	}

	if (mute == true)
	{
		// �~���[�g�t���O�������Ă�����Đ����~�߂�
		StopSoundMem(soundHandle);
	}
}

void Sound::ChangeVolume(int volume)
{
	ChangeVolumeSoundMem(volume, soundHandle);
}
