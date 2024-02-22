#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"

#include "SpriteCommon.h"
#include "Sprite.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    // ポインタ置き場
    Input* input_ = nullptr;
    WinApp* winApp_ = nullptr;
    DirectXCommon* dxCommon_ = nullptr;

#pragma region WindowsAPI初期化処理
    
    winApp_ = new WinApp();
    winApp_->Initialize();

#pragma region DirectX初期化処理
    dxCommon_ = new DirectXCommon();
    dxCommon_->Initialize(winApp_);

     // Input生成、初期化
    input_ = new Input();
    input_->Initialize(winApp_);

    // スプライトコモン
    SpriteCommon* spriteCommon = new SpriteCommon();
    spriteCommon->Initialize(dxCommon_);

    // スプライト
    Sprite* sprite = new Sprite();
    sprite->Initialize(dxCommon_,spriteCommon);

    // ゲームループ
    while (true) {
        //更新
        if (winApp_->Update() == true) {
            break;
        }

        // 入力
        input_->Update();
    
        // 更新前処理
        dxCommon_->PreDraw();

        sprite->Draw();

        // 更新後処理
        dxCommon_->PostDraw();
    }
    delete sprite;
    delete spriteCommon;
    delete input_;
    delete dxCommon_;
    winApp_->Finalize();
    delete winApp_;

    return 0;
}