#pragma once
#include <random>

//�����������֐��̌Ăяo���݂̂ŉ\�ɂ������������N���X
//�V���O���g���p�^�[���̗p
//�֐��� (�^��)rand_nl(non limit �͈͎w��Ȃ�)
//                sl(set limit �͈͎w�肠��)
class NY_random
{
public:
	//�񌈒�I����
	static std::random_device rnd;
	//���������ɕK�v�Ȃق��̗v�f�͊֐����s���ɐ���
private:
	//�R���X�g���N�^�A�f�X�g���N�^��private
	NY_random() {};
	~NY_random() {};
public:
	NY_random(const NY_random &obj) = delete; //�R�s�[�R���X�g���N�^�̖�����
	NY_random &operator=(const NY_random &obj) = delete; //������Z�q�̖�����

	/// <summary>
	/// �͈͖��w��̐����^���������i�񌈒�I�j
	/// </summary>
	/// <returns> �������ꂽint�^�����i32bit ,0~0xffffffff�j</returns>
	static int intrand_nl();

	/// <summary>
	/// �͈͎w��̐����^���������i����I�j
	/// </summary>
	/// <param name="max"> �������闐���̍ő�l </param>
	/// <param name="min"> �������闐���̍ŏ��l </param>
	/// <returns> �������ꂽint�^�����i32bit, min~max�͈̔́j </returns>
	static int intrand_sl(int max, int min);

	/// <summary>
	/// �͈͎w���double�^��������
	/// </summary>
	/// <param name="max"> �������闐���̍ő�l</param>
	/// <param name="min"> �������闐���̍ŏ��l</param>
	/// <returns> �������ꂽdouble�^����</returns>
	static double doublerand_sl(double max, double min);

	/// <summary>
	/// �͈͎w���float�^��������
	/// </summary>
	/// <param name="max"> �������闐���̍ő�l</param>
	/// <param name="min"> �������闐���̍ŏ��l</param>
	/// <returns> �������ꂽfloat�^�����i���ۂ�double�����A�L���X�g��float�ɂ��Ă�j</returns>
	static float floatrand_sl(float max, float min);

};

