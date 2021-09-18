#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"

#include "Map.h"
#include "Player.h"
#include "./Header/GameManager.h"

#include "Input.h"



//ゲーム画面クラス
class Game : public BaseScene {

public:
    Game(ISceneChanger *changer);
    void Initialize() override;    //初期化処理をオーバーライド。
    //void Finalize() override;        //終了処理をオーバーライド。
    void Update() override;        //更新処理をオーバーライド。
    void Draw() override;            //描画処理をオーバーライド。


    //-----以下、ゲーム内で使用するインスタンス-----//

    //デバッグ用プレイヤーモドキ
    float posX = 0, posY = 0;
    //ゲーム管理クラス
    GameManager gameMgr;
    //マップクラス
    Map map;
    //プレイヤー
    Player player;


};

