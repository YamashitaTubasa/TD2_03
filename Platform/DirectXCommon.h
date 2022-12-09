#pragma once 
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <d3dx12.h>
#include <chrono>
#include <thread>

#include <DirectXMath.h>
#include <d3dcompiler.h>
#include <DirectXTex.h>

#include "Platform/WinApp.h"
//#include "Input/Input.h"
#include "Platform/FPSFixed.h"

using namespace Microsoft::WRL;
using namespace DirectX;

// DirectX���
class DirectXCommon
{
public: // �����o�֐�
	// ������
	void Initialize(WinApp* winApp);
	// �f�o�C�X�̏�����
	void InitializeDevice();
	// �R�}���h�֘A�̏�����
	void InitializeCommand();
	// �X���b�v�`�F�[���̏�����
	void InitializeSwapchain();
	// �����_�[�^�[�Q�b�g�r���[�̏�����
	void InitializeRenderTargetView();
	// �[�x�o�b�t�@�̏�����
	void InitializeDepthBuffer();
	// �t�F���X�̏�����
	void InitializeFence();
	// �`��O����
	void PreDraw();
	// �`��㏈��
	void PostDraw();

private: // �����o�֐�
	// FPS�Œ菉����
	void InitializeFixFPS();
	// FPS�Œ�X�V
	void UpdateFixFPS();
	// �L�^����(FPS�Œ�p)
	std::chrono::steady_clock::time_point reference_;

public: // Getter
	// �f�o�C�X�̎擾
	ID3D12Device* GetDevice() const { return device.Get(); }
	// �R�}���h���X�g�擾
	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }

private: 
	// WindowsAPI
	WinApp* winApp = nullptr;
	// Input
	/*Input* input = nullptr;*/
	// FPS
	/*FPSFixed* fpsFixed = nullptr;*/

	HRESULT result;
	// DirectX12�f�o�C�X
	ComPtr<ID3D12Device> device;
	// DXGI�t�@�N�g��
	ComPtr<IDXGIFactory7> dxgiFactory;
	// �X���b�v�`�F�C��
	ComPtr<IDXGISwapChain4> swapChain;
	// �R�}���h�A���P�[�^
	ComPtr<ID3D12CommandAllocator> commandAllocator;
	// �R�}���h���X�g
	ComPtr<ID3D12GraphicsCommandList> commandList;
	// �R�}���h�L���[
	ComPtr<ID3D12CommandQueue> commandQueue;
	ComPtr<ID3D12DescriptorHeap> rtvHeap;
	ComPtr<ID3D12DescriptorHeap> dsvHeap;

	//// �X���b�v�`�F�[���̐ݒ�
	//DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	//// �R�}���h�L���[�̐ݒ�
	//D3D12_COMMAND_QUEUE_DESC commandQueueDesc{};
	//D3D12_RESOURCE_BARRIER barrierDesc{};
	//D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};
	//�o�b�N�o�b�t�@
	std::vector<ComPtr<ID3D12Resource>> backBuffers;
	// �t�F���X�̐���
	ComPtr<ID3D12Fence> fence;
	UINT rtvHD;
	UINT64 fenceVal = 0;
};