
#include "Game.h"
#include "DxLib.h"

Game::Game(ISceneChanger *changer) : BaseScene(changer) {

    //�}�b�v�f�[�^�������͈�x�����s��
    map.Init();
    
}

//������
void Game::Initialize() {
    //�v���C���[������
    player.Init(432, 16 * 38, 3, 3);
    //�Q�[���Ǘ��N���X������
    gameMgr.Init(map.map);
}

//�X�V
void Game::Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        mSceneChanger->ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
    }

#ifdef _DEBUG
    //�f�o�b�O�p�A����
    /*Input::Updata();

    if (Input::IsKey(KEY_INPUT_UP   )) { posY -= 3.0f; }
    if (Input::IsKey(KEY_INPUT_DOWN )) { posY += 3.0f; }
    if (Input::IsKey(KEY_INPUT_RIGHT)) { posX += 3.0f; }
    if (Input::IsKey(KEY_INPUT_LEFT )) { posX -= 3.0f; }*/
#endif
    player.Update(&map);
    gameMgr.Update(player.posX, player.posY);
}

//�`��
void Game::Draw() {
    BaseScene::Draw();//�e�N���X�̕`�惁�\�b�h���Ă�

    //�}�b�v�`��
    map.Draw();
    //�v���C���[�`��
    player.Draw(0, 60);
    //�Q�[���Ǘ��N���X�`��
    gameMgr.Draw();

#ifdef _DEBUG
    //�f�o�b�O�L�����`��
    /*DrawBox(posX - 8, posY - 8, posX + 8, posY + 8, GetColor(50, 50, 255), TRUE);
    DrawFormatString(posX - 15, posY - 15, GetColor(255, 255, 255), "pos:%f %f", posX / 16, posY / 16);*/
#endif // _DEBUG

}
