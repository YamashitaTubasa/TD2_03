#include "Input/Input.h"
#include "Platform/WinApp.h"
#include "Platform/DirectXCommon.h"
#include "3d/Object3d.h"

// windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// �R���\�[���ւ̕����o��
	OutputDebugStringA("Hellow,DirectX!!\n");

#pragma region ��ՃV�X�e���̏�����
	// �|�C���^
	WinApp* winApp = nullptr;
	Input* input = nullptr;
	DirectXCommon* dXCommon = nullptr;
	HRESULT result;
	ID3D12GraphicsCommandList* cmdList = dXCommon->GetCommandList();

	// WindowsAPI�̏�����
	winApp = new WinApp();
	winApp->Initialize();

	// DirectX�̏�����
	dXCommon = new DirectXCommon();
	dXCommon->Initialize(winApp);

	// ���͂̏�����
	input = new Input();
	input->Initialize(winApp);


#pragma endregion ��ՃV�X�e���̏�����

#pragma region �ŏ��̃V�[���̏�����

	// 3D�I�u�W�F�N�g
	Object3d* object3d = nullptr;
	object3d = new Object3d();
	Object3d::StaticInitialize(dXCommon->GetDevice(), WinApp::window_width, WinApp::window_height);
	object3d = Object3d::Create();
	object3d->Update();
	
#pragma endregion �ŏ��̃V�[���̏�����

	while (true) {

	#pragma region ��ՃV�X�e���̍X�V

		// Windows�̃��b�Z�[�W����
		if (winApp->ProcessMessage()) {
			// �Q�[�����[�v�𔲂���
			break;
		}

		input->Update();

		object3d->Update();

	#pragma endregion ��ՃV�X�e���̍X�V

	#pragma region �ŏ��̃V�[���̍X�V

	#pragma endregion �ŏ��̃V�[���̍X�V

		// �`��O����
		dXCommon->PreDraw();
		Object3d::PreDraw(cmdList);

	#pragma region �ŏ��̃V�[���̕`��

		object3d->Draw();
		
	#pragma endregion �ŏ��̃V�[���̕`��

		// �`��㏈��
		dXCommon->PostDraw();
		Object3d::PostDraw();
	}
#pragma region �ŏ��̃V�[���̏I��

#pragma endregion �ŏ��̃V�[���̏I��

#pragma region ��ՃV�X�e���̏I��

	// ���͊J��
	delete input;
	input = nullptr;

	// WindowsAPI�̏I������
	winApp->Finalize();

	// WindowsAPI���
	delete winApp;
	winApp = nullptr;

	// DirectX���
	delete dXCommon;
	dXCommon = nullptr;

#pragma endregion ��ՃV�X�e���̏I��

	return 0;
}