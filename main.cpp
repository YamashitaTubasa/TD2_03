#include "Input/Input.h"
#include "Platform/WinApp.h"
#include "Platform/DirectXCommon.h"
#include "3d/Object3d.h"

// windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// コンソールへの文字出力
	OutputDebugStringA("Hellow,DirectX!!\n");

#pragma region 基盤システムの初期化
	// ポインタ
	WinApp* winApp = nullptr;
	Input* input = nullptr;
	DirectXCommon* dXCommon = nullptr;
	HRESULT result;
	ID3D12GraphicsCommandList* cmdList = dXCommon->GetCommandList();

	// WindowsAPIの初期化
	winApp = new WinApp();
	winApp->Initialize();

	// DirectXの初期化
	dXCommon = new DirectXCommon();
	dXCommon->Initialize(winApp);

	// 入力の初期化
	input = new Input();
	input->Initialize(winApp);


#pragma endregion 基盤システムの初期化

#pragma region 最初のシーンの初期化

	// 3Dオブジェクト
	Object3d* object3d = nullptr;
	object3d = new Object3d();
	Object3d::StaticInitialize(dXCommon->GetDevice(), WinApp::window_width, WinApp::window_height);
	object3d = Object3d::Create();
	object3d->Update();
	
#pragma endregion 最初のシーンの初期化

	while (true) {

	#pragma region 基盤システムの更新

		// Windowsのメッセージ処理
		if (winApp->ProcessMessage()) {
			// ゲームループを抜ける
			break;
		}

		input->Update();

		object3d->Update();

	#pragma endregion 基盤システムの更新

	#pragma region 最初のシーンの更新

	#pragma endregion 最初のシーンの更新

		// 描画前処理
		dXCommon->PreDraw();
		Object3d::PreDraw(cmdList);

	#pragma region 最初のシーンの描画

		object3d->Draw();
		
	#pragma endregion 最初のシーンの描画

		// 描画後処理
		dXCommon->PostDraw();
		Object3d::PostDraw();
	}
#pragma region 最初のシーンの終了

#pragma endregion 最初のシーンの終了

#pragma region 基盤システムの終了

	// 入力開放
	delete input;
	input = nullptr;

	// WindowsAPIの終了処理
	winApp->Finalize();

	// WindowsAPI解放
	delete winApp;
	winApp = nullptr;

	// DirectX解放
	delete dXCommon;
	dXCommon = nullptr;

#pragma endregion 基盤システムの終了

	return 0;
}