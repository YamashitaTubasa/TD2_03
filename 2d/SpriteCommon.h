#pragma once

#include <DirectXMath.h>

#include "Platform/DirectXCommon.h"

using namespace DirectX;

// ===================
// �X�v���C�g���ʕ�
// ===================
class SpriteCommon
{
public:
	

public: // �����o�֐�
	// ������
	void Initialize();
	// �X�V
	void Update();
	// �`��
	void Draw();

public: // getter
	DirectXCommon* GetDirectXCommon() const{ return directXCommon; }

private:
	DirectXCommon* directXCommon = nullptr;
};