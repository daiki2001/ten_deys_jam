#pragma once
#include <utility>
#include <tuple>

//�p�[�e�B�N���\����
typedef struct Particle {
	float posX , posY;  //���W
	float width, height;//���A�c��
	float vecX, vecY;   //�ړ��x�N�g��
	int   param;        //�u�����h�p�����[�^
	std:: tuple<int, int, int> rgb;//�P�xRGB�l
	int   frame;     //�o�߃t���[��
	bool  isAlive;   //�`��t���O
	Particle() {//�������ɏ�����
		posX  = 0,   posY = 0;
		width = 0, height = 0;
		vecX  = 0;   vecY = 0;
		param = 255;//�f�t�H���g�l
		rgb   = std::make_tuple<int, int, int>(255, 255, 255);//�f�t�H���g�l
		frame = 0;
		isAlive = false;
	}
};

/// <summary>
/// �p�[�e�B�N��������
/// </summary>
/// <param name="p"> ����������p�[�e�B�N���̎Q��</param>
/// <param name="px"> x���W</param>
/// <param name="py"> y���W</param>
/// <param name="vx"> �x�N�g��x</param>
/// <param name="vy"> �x�N�g��y</param>
/// <param name="w"> ����</param>
/// <param name="h"> �c��</param>
/// <param name="param"> �`��p�����[�^</param>
/// <param name="rgb"> �P�x�p�����[�^</param>
inline void InitParticle(Particle &p, float px, float py, float vx, float vy, float w, float h, int param, std::tuple<int, int, int> rgb) {
	//���W�n
	p.posX = px;
	p.posY = py;
	p.vecX = vx;
	p.vecY = vy;
	p.width = w;
	p.height = h;
	//�`��p�����[�^
	p.param = param;
	p.rgb = rgb;
	//���̑�
	p.frame = 0;
	p.isAlive = false;
};


