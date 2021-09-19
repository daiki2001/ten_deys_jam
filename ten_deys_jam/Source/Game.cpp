
#include "./../Header/Game.h"
#include "DxLib.h"

Game::Game(ISceneChanger *changer) : BaseScene(changer) {

    //マップデータ初期化は一度だけ行う
    map.Init();
    
}

//初期化
void Game::Initialize() {
    //プレイヤー初期化
    player.Init(432, 16 * 38, 3, 3);
    //ゲーム管理クラス初期化
    gameMgr.Init(map.map);
    //スコア関係の初期化
    result.Init();
}

//更新
void Game::Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        mSceneChanger->ChangeScene(eScene_Menu);//シーンをメニューに変更
    }

#ifdef _DEBUG
    //デバッグ用、入力
    /*Input::Updata();

    if (Input::IsKey(KEY_INPUT_UP   )) { posY -= 3.0f; }
    if (Input::IsKey(KEY_INPUT_DOWN )) { posY += 3.0f; }
    if (Input::IsKey(KEY_INPUT_RIGHT)) { posX += 3.0f; }
    if (Input::IsKey(KEY_INPUT_LEFT )) { posX -= 3.0f; }*/
#endif
    player.Update(&map);
    gameMgr.Update(player.posX, player.posY);

    if (gameMgr.timer.time > 0)
    {
        if (gameMgr.isHit == true)
        {
            result.AddScore(gameMgr.gmanager.goalCount, gameMgr.level, gameMgr.timer.time);
        }
    }
    else
    {
        result.GameSet(mSceneChanger);
    }
}

//描画
void Game::Draw() {
    BaseScene::Draw();//親クラスの描画メソッドを呼ぶ

    //マップ描画
    map.Draw();
    //プレイヤー描画
    player.Draw(0, 60);
    //ゲーム管理クラス描画
    gameMgr.Draw();
    //リザルト画面の描画
    result.Draw(gameMgr.timer.time > 0, gameMgr.gmanager.goalCount, gameMgr.level);

#ifdef _DEBUG
    //デバッグキャラ描画
    /*DrawBox(posX - 8, posY - 8, posX + 8, posY + 8, GetColor(50, 50, 255), TRUE);
    DrawFormatString(posX - 15, posY - 15, GetColor(255, 255, 255), "pos:%f %f", posX / 16, posY / 16);*/
#endif // _DEBUG

}
