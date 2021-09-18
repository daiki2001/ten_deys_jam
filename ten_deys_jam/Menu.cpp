#include "Menu.h"
#include "DxLib.h"

Menu::Menu(ISceneChanger *changer) : BaseScene(changer) {
}

//������
void Menu::Initialize() {
    mImageHandle = LoadGraph("images/Scene_Menu.png");    //�摜�̃��[�h
}

//�X�V
void Menu::Update() {
    if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
        mSceneChanger->ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_C) != 0) {//C�L�[��������Ă�����
        mSceneChanger->ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
    }
}

//�`��
void Menu::Draw() {
    BaseScene::Draw();//�e�N���X�̕`�惁�\�b�h���Ă�
    DrawBox(0, 0, 640, 60, GetColor(255, 255, 255), false);
    DrawBox(0, 60, 640, 700, GetColor(255, 255, 255), false);

    DrawString(0, 5, "���j���[��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 25, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
    DrawString(0, 45, "C�L�[�������Ɓ@�ݒ��ʂɐi�݂܂��B", GetColor(255, 255, 255));
}