#pragma once

#include <chrono>
#include <thread>

class FPSFixed 
{
public: // �����o�֐�
	// FPS�Œ菉����
	void InitializeFixFPS();
	// FPS�Œ�X�V
	void UpdateFixFPS();
	// �L�^����(FPS�Œ�p)
	std::chrono::steady_clock::time_point reference_;
};