#include "DxLib.h"

int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	// DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// �t�H���g�T�C�Y�̕ύX
	SetFontSize(200);



	// ���͑ҋ@
	WaitKey();

	// DX���C�u�����̏I������
	DxLib_End();

	return 0;
}