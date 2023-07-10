/*************************************************
* �v���O���~���O���K
* �}�b�`�R�Q�[���̐���
**************************************************/
#include "DxLib.h"
#include "FreamControl.h"
#include "InputControl.h"
#include "SceneManager.h"

/*************************************************
* �}�N����`
**************************************************/
#define SCREEN_HEIGHT	(480)		// �X�N���[���T�C�Y�i�����j
#define SCREEN_WIDTH	(640)		// �X�N���[���T�C�Y�i���j
#define SCREEN_COLORBIT	(32)		// �X�N���[���J���[�r�b�g
#define FONT_SIZE		(20)		// �����T�C�Y

/*************************************************
* �^��`
**************************************************/


/*************************************************
* �O���[�o���ϐ��錾
**************************************************/


/*************************************************
* �v���g�^�C�v�錾
**************************************************/



/*************************************************
* �v���O�����̊J�n
**************************************************/
int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// �E�B���h�E�^�C�g���̐ݒ�
	SetMainWindowText("Match 3 Puzzule");

	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	// ��ʃT�C�Y�̍ő�T�C�Y, �J���[�r�b�g���̐ݒ�
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);


	// DX���C�u�����̏�����
	if (DxLib_Init() == D_ERROR)
	{
		return D_ERROR;
	}

	// �e�@�\�̏���������
	FreamControl_Initialize();
	Input_Initialize();

	// �V�[���}�l�[�W���[����������
	// �G���[������������A�I������
	if (SceneManager_Initialize() == D_ERROR)
	{
		return D_ERROR;
	}

	// �`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// �t�H���g�T�C�Y�̕ύX
	SetFontSize(FONT_SIZE);

	// �Q�[�����[�v
	while (ProcessMessage() != D_ERROR && Input_Escape() == FALSE)
	{
		// ���͐���@�\�X�V����
		Input_Update();

		// �V�[���}�l�[�W���[�X�V����
		SceneManager_Update();

		// ��ʃN���A
		ClearDrawScreen();

		// �V�[���}�l�[�W���[�`�揈��
		SceneManager_Draw();

		// �t���[�����[�g���䏈��
		FreamCotrol_Update();

		// ��ʂ̓��e��\��ʂɔ��f
		ScreenFlip();

	}

	// DX���C�u�����̏I������
	DxLib_End();

	return 0;
}
