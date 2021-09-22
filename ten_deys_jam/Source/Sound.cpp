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
		// 再生してなかったら再生
		PlaySoundMem(soundHandle, playType);
	}

	if (mute == true)
	{
		// ミュートフラグが立っていたら再生を止める
		StopSoundMem(soundHandle);
	}
}

void Sound::ChangeVolume(int volume)
{
	ChangeVolumeSoundMem(volume, soundHandle);
}
