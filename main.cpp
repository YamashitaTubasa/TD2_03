#include "Input/Input.h"
#include "Platform/WinApp.h"
#include "Platform/DirectXCommon.h"

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
	
#pragma endregion �ŏ��̃V�[���̏�����

	while (true) {

	#pragma region ��ՃV�X�e���̍X�V

		// Windows�̃��b�Z�[�W����
		if (winApp->ProcessMessage()) {
			// �Q�[�����[�v�𔲂���
			break;
		}

		input->Update();

	#pragma endregion ��ՃV�X�e���̍X�V

	#pragma region �ŏ��̃V�[���̍X�V

	#pragma endregion �ŏ��̃V�[���̍X�V

		// �`��O����
		dXCommon->PreDraw();

	#pragma region �ŏ��̃V�[���̕`��
		
	#pragma endregion �ŏ��̃V�[���̕`��

		// �`��㏈��
		dXCommon->PostDraw();
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