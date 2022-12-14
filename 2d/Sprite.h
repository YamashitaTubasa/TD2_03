#pragma once

#include <d3dcompiler.h>

#include "2d/SpriteCommon.h"

#pragma comment(lib, "d3dcompiler.lib")


// =================
// �X�v���C�g
// =================
class Sprite
{
public:
	struct VertexPosUv
	{
		XMFLOAT3 pos; // xyz���W
		XMFLOAT3 uv; // uv���W
	};

	struct PipelineSet
	{
		// �p�C�v���C���X�e�[�g�I�u�W�F�N�g
		ComPtr<ID3D12PipelineState> pipelinestate;
		// ���[�g�V�O�l�`��
		ComPtr<ID3D12RootSignature> rootsignature;
	};

	struct SpritePipelineSet {
		PipelineSet pipelineSet;
	};

public: // �����o�֐�
	// ������
	void Initialize(SpriteCommon* spriteCommon);
	// �X�V
	void Update();
	// �`��
	void Draw(const SpritePipelineSet* pipelineSet);
	// �p�C�v���C������
	Sprite::PipelineSet Object3dCreateGraphicsPipeline(ID3D12Device* dev);

public:
	SpriteCommon* spriteCommon = nullptr;

private:
	ComPtr<ID3D12Device> dev;
	ComPtr<ID3D12GraphicsCommandList> cmdList;
};
