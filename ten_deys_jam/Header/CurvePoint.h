#pragma once
#include "Map.h"

class CurvePoint
{
public:
	int posX, posY;     //�Ȃ���ꏊ�̍��W
	int direction;      //�v���C���[�̐i�s����
	bool turnRightFlag; //�E�܂��ǂ����̃t���O
	int frame;          //�t���[���J�E���^
	int animation;      //�A�j���[�V�����J�E���^
	int graphArray[9];  //�摜�f�[�^
	bool drawFlag;      //�`�悷�邩�ǂ���

public:
	CurvePoint(); //�R���X�g���N�^
	~CurvePoint() {};

	// ������
	void Init();
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name="posX"> �v���C���[��X���W(�I�t�Z�b�g�l����) </param>
	/// <param name="posY"> �v���C���[��Y���W(�I�t�Z�b�g�l����) </param>
	/// <param name="direction"> �v���C���[�̐i�s���� </param>
	/// <param name="turnFlag"> �v���C���[�ɋȂ���ӎv�����邩�ǂ��� </param>
	/// <param name="turnRightFlag"> �E�܂��邩�ǂ��� </param>
	/// <param name="map"> �}�b�v </param>
	void Update(int posX, int posY, int direction, bool turnFlag, Map* map);
	// �`��ioffsetX, offsetY:�I�t�Z�b�g�l�j
	void Draw(int offsetX = 0, int offsetY = 0);
};
