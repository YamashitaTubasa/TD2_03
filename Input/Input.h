#pragma once
#include <windows.h>
#include <wrl.h>
#include <dinput.h>
#include "Platform/WinApp.h"
#include <dwrite.h>
#include <wchar.h>
#include <wrl/client.h>
#include <random>
#include <xinput.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"dwrite.lib")
#pragma comment (lib, "xinput.lib")

#define MaxCountrollers 4  
#define MaxVibration 65535
#define DIRECTINPUT_VERSION 0x0800 // DirectInput�̃o�[�W�����w��

// ����
class Input
{
public:
	struct CountrolerState
	{
		XINPUT_STATE state; // �R���g���[���[�̏�Ԃ̎擾
		XINPUT_VIBRATION vibration;  // �o�C�u���[�V����
		//bool Connected;
	};
	CountrolerState GamePad;

public:
	// namespace
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public: // �����o�֐�
	// ������
	void Initialize(WinApp* winApp);

	// �X�V
	void Update();

	/// <summary>
	/// �L�[�̉������`�F�b�N
	/// </summary>
	/// <param name = "keyNumber">�L�[�ԍ�(DIK_0 ��)</param>
	/// <returns>������Ă��邩</returns>
	bool PushKey(BYTE keyNumber);

	/// <summary>
	/// �L�[�̃g���K�[���`�F�b�N
	/// </summary>
	/// </param name="keyNumber">�L�[�ԍ�( DIK_0 ��)</param>
	/// <reutrns>�g���K�[��</params>
	bool TriggerKey(BYTE keyNumber);

private: // �����o�ϐ�
	// �L�[�{�[�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> keyboard;
	// DirectInput�̃C���X�^���X
	ComPtr<IDirectInput8> directInput;
	// �S�L�[�̏��
	BYTE key[256] = {};
	// �O��̑S�L�[�̏��
	BYTE keyPre[256] = {};
	// WindowsAPI
	WinApp* winApp = nullptr;
};