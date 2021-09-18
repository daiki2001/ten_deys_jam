#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"

#include "Map.h"
#include "Player.h"
#include "./Header/GameManager.h"

#include "Input.h"



//�Q�[����ʃN���X
class Game : public BaseScene {

public:
    Game(ISceneChanger *changer);
    void Initialize() override;    //�������������I�[�o�[���C�h�B
    //void Finalize() override;        //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;            //�`�揈�����I�[�o�[���C�h�B


    //-----�ȉ��A�Q�[�����Ŏg�p����C���X�^���X-----//

    //�f�o�b�O�p�v���C���[���h�L
    float posX = 0, posY = 0;
    //�Q�[���Ǘ��N���X
    GameManager gameMgr;
    //�}�b�v�N���X
    Map map;
    //�v���C���[
    Player player;


};

