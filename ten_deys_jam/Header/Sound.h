#pragma once

class Sound
{
public:
	int soundHandle; //サウンドハンドル
	bool mute;       //ミュートフラグ
private:
	int volume; //音量（0x00 ~ 0xFF）

public:
	Sound();  //コンストラクタ
	~Sound(); //デストラクタ

	// 初期化（filePath:音ファイルのパス、volume:音量）
	void Init(const char* filePath, int volume);
	// 音の再生（playType:再生形式）
	void Play(int playType);
	// 音量の変更（volume:音量）
	void ChangeVolume(int volume);
};
