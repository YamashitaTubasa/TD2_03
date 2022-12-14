#include "2d/Sprite.h"

void Sprite::Initialize(SpriteCommon* spriteCommon){
	this->spriteCommon = spriteCommon;
}

void Sprite::Update(){

	PipelineSet object3dPipelineSet = Object3dCreateGraphicsPipeline(dev.Get());
	//HRESULT result;
	//ID3D12Device* device = nullptr;

	//// ���_�f�[�^
	//XMFLOAT3 vertices[] = {
	//	{-0.5f, -0.5f, 0.0f}, // ����
	//	{-0.5f, +0.5f, 0.0f}, // ����
	//	{+0.5f, -0.5f, 0.0f}, // �E��
	//};

	//// ���_�f�[�^�S�̃T�C�Y = ���_�f�[�^����̃T�C�Y * ���_�f�[�^�̗v�f��
	//UINT sizeVB = static_cast<UINT>(sizeof(XMFLOAT3) * _countof(vertices));

	//// ���_�o�b�t�@�̐ݒ�
	//D3D12_HEAP_PROPERTIES heapProp{}; // �q�[�v�ݒ�
	//heapProp.Type = D3D12_HEAP_TYPE_UPLOAD; // GPU�ւ̓]���p
	//// �����[�X�ݒ�
	//D3D12_RESOURCE_DESC resDesc{};
	//resDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	//resDesc.Width = sizeVB; // ���_�S�̃T�C�Y
	//resDesc.Height = 1;
	//resDesc.DepthOrArraySize = 1;
	//resDesc.MipLevels = 1;
	//resDesc.SampleDesc.Count = 1;
	//resDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
	//
	//// ���_�o�b�t�@�̐���
	//ID3D12Resource* vertBuff = nullptr;
	//result = device->CreateCommittedResource(
	//	&heapProp, // �q�[�v�ݒ�
	//	D3D12_HEAP_FLAG_NONE,
	//	&resDesc, // ���\�[�X�ݒ�
	//	D3D12_RESOURCE_STATE_GENERIC_READ,
	//	nullptr,
	//	IID_PPV_ARGS(&vertBuff));
	//assert(SUCCEEDED(result));

	//// GPU��̃o�b�t�@�ɑΉ��������z������(���C����������)���擾����
	//XMFLOAT3* vertMap = nullptr;
	//result = vertBuff->Map(0, nullptr, (void**)&vertMap);
	//assert(SUCCEEDED(result));
	//// �S���_�ɑ΂���
	//for (int i = 0; i < _countof(vertices); i++) {
	//	vertMap[i] = vertices[i]; // ���W���R�s�[
	//}
	//// �q���������
	//vertBuff->Unmap(0, nullptr);

	//// ���_�o�b�t�@�r���[�̍쐬
	//D3D12_VERTEX_BUFFER_VIEW vbView{};
	//// GPU���z�A�h���X
	//vbView.BufferLocation = vertBuff->GetGPUVirtualAddress();
	//// ���_�o�b�t�@�̃T�C�Y
	//vbView.SizeInBytes = sizeVB;
	//// ���_����̃f�[�^�T�C�Y
	//vbView.StrideInBytes = sizeof(XMFLOAT3);

	//ID3DBlob* vsBlob = nullptr; // ���_�V�F�[�_�I�u�W�F�N�g
	//ID3DBlob* psBlob = nullptr; // �s�N�Z���V�F�[�_�I�u�W�F�N�g
	//ID3DBlob* errorBlob = nullptr; // �G���[�I�u�W�F�N�g

	//// ���_�V�F�[�_�̓ǂݍ��݂ƃR���p�C��
	//result = D3DCompileFromFile(
	//	L"SpriteVS.hlsl", // �V�F�[�_�t�@�C��
	//	nullptr,
	//	D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
	//	"main", "vs_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���f���w��
	//	D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // �f�o�b�N�p�ݒ�
	//	0,
	//	&vsBlob, &errorBlob);

	//// �G���[�Ȃ�
	//if (FAILED(result)) {
	//	// errorBlob����G���[���e��string�^�ɃR�s�[
	//	std::string error;
	//	error.resize(errorBlob->GetBufferSize());

	//	std::copy_n((char*)errorBlob->GetBufferPointer(),
	//		errorBlob->GetBufferSize(),
	//		error.begin());
	//	error += "\n";
	//	// �G���[���e���o�̓E�B���h�E�ɕ\��
	//	OutputDebugStringA(error.c_str());
	//	assert(0);
	//}

	//// �s�N�Z���V�F�[�_�̓ǂݍ��݂ƃR���p�C��
	//result = D3DCompileFromFile(
	//	L"SpritePS.hlsl", // �V�F�[�_�t�@�C����
	//	nullptr,
	//	D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
	//	"main", "ps_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���o��p�w��
	//	0,
	//	&psBlob, &errorBlob);
}

void Sprite::Draw(SpritePipelineSet* spipelineSet) {

	// �p�C�v���C���X�e�[�g�ƃ��[�g�V�O�l�`���̐ݒ�
	cmdList->SetPipelineState(spipelineSet->pipelineSet.pipelinestate.Get());
	cmdList->SetGraphicsRootSignature(pipelineSet.rootsignature.Get());
}

Sprite::PipelineSet Sprite::Object3dCreateGraphicsPipeline(ID3D12Device* dev)
{
	HRESULT result;
	ComPtr<ID3DBlob> vsBlob; // ���_�V�F�[�_�I�u�W�F�N�g
	ComPtr<ID3DBlob> psBlob; // �s�N�Z���V�F�[�_�I�u�W�F�N�g
	ComPtr<ID3DBlob> errorBlob; // �G���[�I�u�W�F�N�g

	// ���_�V�F�[�_�̓ǂݍ��݂ƃR���p�C��
	result = D3DCompileFromFile(
		L"SpriteVS.hlsl", // �V�F�[�_�t�@�C����
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
		"main", "vs_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���f���w��
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // �f�o�b�O�p�w��
		0,
		&vsBlob, &errorBlob);

	if (FAILED(result)) {
		// errorBlob����G���[���e��string�^�ɃR�s�[
		std::string errstr;
		errstr.resize(errorBlob->GetBufferSize());

		std::copy_n((char*)errorBlob->GetBufferPointer(),
			errorBlob->GetBufferSize(),
			errstr.begin());
		errstr += "\n";
		// �G���[���e���o�̓E�B���h�E�ɕ\��
		OutputDebugStringA(errstr.c_str());
		exit(1);
	}

	// �s�N�Z���V�F�[�_�̓ǂݍ��݂ƃR���p�C��
	result = D3DCompileFromFile(
		L"SpritePS.hlsl", // �V�F�[�_�t�@�C����
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
		"main", "ps_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���f���w��
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // �f�o�b�N�p�ݒ�
		0,
		&psBlob, &errorBlob);

	if (FAILED(result)) {
		// errorBlob����G���[���e��string�^�ɃR�s�[
		std::string errstr;
		errstr.resize(errorBlob->GetBufferSize());

		std::copy_n((char*)errorBlob->GetBufferPointer(),
			errorBlob->GetBufferSize(),
			errstr.begin());
		errstr += "\n";
		// �G���[���e���o�̓E�B���h�E�ɕ\��
		OutputDebugStringA(errstr.c_str());
		exit(1);
	}

	// ���_���C�A�E�g
	D3D12_INPUT_ELEMENT_DESC inputLayout[] = {
		{
			"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,
			D3D12_APPEND_ALIGNED_ELEMENT,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
		},
		{
			"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0,
			D3D12_APPEND_ALIGNED_ELEMENT,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
		},
	};

	// �O���t�B�b�N�X�p�C�v���C���ݒ�
	D3D12_GRAPHICS_PIPELINE_STATE_DESC gpipeline{};

	gpipeline.VS.pShaderBytecode = vsBlob->GetBufferPointer();
	gpipeline.VS.BytecodeLength = vsBlob->GetBufferSize();
	gpipeline.PS.pShaderBytecode = psBlob->GetBufferPointer();
	gpipeline.PS.BytecodeLength = psBlob->GetBufferSize();

	// �T���v���}�X�N�ƃ��X�^���C�U�X�e�[�g�̐ݒ�
	gpipeline.SampleMask = D3D12_DEFAULT_SAMPLE_MASK; // �W���ݒ�

	gpipeline.RasterizerState.CullMode = D3D12_CULL_MODE_NONE; // �J�����O���Ȃ�
	gpipeline.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID; // �|���S�����h��Ԃ�
	gpipeline.RasterizerState.DepthClipEnable = true; // �[�x�N���b�s���O��L��

	// �u�����h�X�e�[�h�̐ݒ�
	gpipeline.BlendState.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL; // RBGA���ׂẴ`�����l����`��

	// ���_���C�A�E�g�ݒ�
	gpipeline.InputLayout.pInputElementDescs = inputLayout;
	gpipeline.InputLayout.NumElements = _countof(inputLayout);

	// �}�`�̌`����O�p�`�ɐݒ�
	gpipeline.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;

	gpipeline.NumRenderTargets = 1; // �`��Ώۂ�1��
	gpipeline.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM; // 0�`255�w���RGBA
	gpipeline.SampleDesc.Count = 1; // 1�s�N�Z���ɂ�1��T���v�����O

	// �p�C�v���C���ƃ��[�g�V�O�l�`���̃Z�b�g
	PipelineSet pipelineSet;

	D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc{};
	rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

	ComPtr<ID3DBlob> rootSigBlob;
	// �o�[�W������������ł̃V���A���C�Y
	result = D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1_0, &rootSigBlob, &errorBlob);
	// ���[�g�V�O�l�`���̐���
	result = dev->CreateRootSignature(0, rootSigBlob->GetBufferPointer(), rootSigBlob->GetBufferSize(),
		IID_PPV_ARGS(&pipelineSet.rootsignature));
	rootSigBlob->Release();

	// �p�C�v���C���Ƀ��[�g�V�O�l�b�`�����Z�b�g
	gpipeline.pRootSignature = pipelineSet.rootsignature.Get();

	// �p�C�v���C���X�e�[�g�̐���
	result = dev->CreateGraphicsPipelineState(&gpipeline, IID_PPV_ARGS(&pipelineSet.pipelinestate));

	// �p�C�v���C���ƃ��[�g�V�O�l�`����Ԃ�
	return pipelineSet;
}
