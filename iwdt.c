#include "iodefine.h"
#include  "misratypes.h"
#include  "iwdt.h"

//  �Ɨ��E�I�b�`�h�b�N�^�C�} (IWDT)�̐ݒ�
//  
//�E���W�X�^�X�^�[�g���[�h
//  �^�C���A�E�g���� : 2048�T�C�N��(07ffh)
//  �N���b�N������ :�����Ȃ�
//  �E�C���h�E�I���ʒu: 0% 
//  �E�C���h�E�J�n�ʒu:100%
//
// �E���Z�b�g�o�͂̋���
//
//�E�Ɨ��E�I�b�`�h�b�N�^�C�}��p�N���b�N = 15[KHz]
//
//  �N���b�N������,  �T�C�N����, IWDT�N���b�N��,  �^�C���A�E�g���� 
// �@ ��������(1),    2048     ,   2048(=1x2048),  136.5[msec]  (= 1/15 * 2048 )    
//
//
//��: IWDTCR ���W�X�^�́A1�񂵂��ύX�ł��Ȃ��B
//     IWDT.IWDTCR.BIT.CKS = 0;
//     IWDT.IWDTCR.BIT.TOPS = 3;�@�ƋL�q����ƁATOPS = 3�����f����Ȃ��B
//     1���[�h�Őݒ肷��B

void IWDT_Set(void)
{
	
	IWDT.IWDTCR.WORD = 0x3303;	// �^�C���A�E�g����=2048�T�C�N��, �N���b�N����=����,  (1/15)*2048 = 136.5[msec] 
					// �E�C���h�E�I���ʒu=0% , �E�C���h�E�I���ʒu=100%
	
	IWDT.IWDTRCR.BYTE = 0x80;	// ���Z�b�g�o�͂�����
	
}


// �Ɨ��E�I�b�`�h�b�N�^�C�}�̃��t���b�V��
//
void IWDT_Refresh(void)
{
	IWDT.IWDTRR = 0x00;
	
	IWDT.IWDTRR = 0xff;
}