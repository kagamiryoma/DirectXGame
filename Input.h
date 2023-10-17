#pragma once

#include <Windows.h>


#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <wrl.h>

//using namespace Microsoft::WRL;

class Input
{
public:
	// 初期化
	void Initialize(HINSTANCE hInstance, HWND hwnd);
	// 更新
	void Update();

	// 任意ボタンを押したとき
	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

private:
	// キーボードのデバイス
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;

	BYTE key[256] = {};
	BYTE keyPre[256] = {};
};

