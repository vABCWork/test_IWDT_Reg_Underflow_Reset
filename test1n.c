#include	<machine.h>
#include	"iodefine.h"
#include	"misratypes.h"
#include	"delay.h"
#include	"iwdt.h"


// ����m�F�p�@LED�o�̓|�[�g
// ALM3 :�@PH3
#define ALM_3_PMR      (PORTH.PMR.BIT.B3)   //  �ėp���o�̓|�[�g
#define ALM_3_PDR      (PORTH.PDR.BIT.B3)   //  �o�͂܂��͓��̓|�[�g�|�[�g�Ɏw��
#define ALM_3_PODR     (PORTH.PODR.BIT.B3)  //  �o�̓f�[�^

// �E�I�b�`�h�b�N�^�C�}�ɂ�郊�Z�b�g�����m�F�p LED�o�̓|�[�g
// ALM4: PH2
#define ALM_4_PMR      (PORTH.PMR.BIT.B2)   //  �ėp���o�̓|�[�g
#define ALM_4_PDR      (PORTH.PDR.BIT.B2)   //  �o�͂܂��͓��̓|�[�g�|�[�g�Ɏw��
#define ALM_4_PODR     (PORTH.PODR.BIT.B2)  //  �o�̓f�[�^


void Task_Normal(void);
void Task_Delay_Error(void);


//
// �Ɨ��E�I�b�`�h�b�N�^�C�}�̓���m�F
//  �E���W�X�^�X�^�[�g���[�h
//  �E�^�C���A�E�g���� = 136.5[msec]
//  �E�E�B���h�E�I��=0%, �E�B���h�E�J�n=100%
//  �E�A���_�[�t���[�Ń��Z�b�g
//

void main(void)
{
	ALM_3_PMR = 0;		// �ėp���o�̓|�[�g
	ALM_3_PDR = 1;		// �o�̓|�[�g�Ɏw��
	
	ALM_4_PMR = 0;		// �ėp���o�̓|�[�g
	ALM_4_PDR = 1;		// �o�̓|�[�g�Ɏw��
	
	
	if ( SYSTEM.RSTSR2.BIT.IWDTRF == 1 ) {	// �Ɨ��E�I�b�`�h�b�N�^�C�}�ɂ�郊�Z�b�g�����o�����ꍇ
	    while(1){ 
		ALM_4_PODR = 1;	     // ALM_4 �_��
	    }
	}
	

	IWDT_Set();		// �Ɨ��E�I�b�`�h�b�N�^�C�} (IWDT)�̐ݒ� ( 136.5[msec]�Ń^�C���A�E�g)
	IWDT_Refresh();		// �E�I�b�`�h�b�N�^�C�}���t���b�V��(�J�E���g�_�E���J�n)
	
	
	while(1){
	 
	   Task_Normal();	// 100msec�҂�
	   
	   IWDT_Refresh();	// �E�I�b�`�h�b�N�^�C�}���t���b�V��
	
	   Task_Normal();	// 100msec�҂� (���퓮��m�F�̏ꍇ ���{)
	 //  Task_Delay_Error();	// 150msec�҂� (�ُ퓮��m�F�̏ꍇ ���{)
	   
	   IWDT_Refresh();	// �E�I�b�`�h�b�N�^�C�}���t���b�V��

	}
	
	
}


//
//  �^�X�N(���펞)
//
void Task_Normal(void)
{
	ALM_3_PODR ^= 1;      // ALM3 LED ���]	
	
	delay_msec(100);     // 100msec �҂�
}



//
//  �^�X�N(�x��ُ�)
//
void Task_Delay_Error(void)
{
	ALM_3_PODR ^= 1;      // ALM3 LED ���]	
	
	delay_msec(150);     //150msec �҂�
}


