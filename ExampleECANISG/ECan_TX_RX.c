/*
 * ECan_TX_RX.c
 *
 *  Created on: 2019
 *      Author: ASUS
 */

#include "include//DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "include//DSP2833x_Examples.h"   // DSP2833x Examples Include File

extern struct ECAN_REGS ECanbShadow;
extern struct ECAN_REGS ECanaShadow;

//���� ����31
void CANSendM31(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX31.MDH.all = can_send_data->MDH.all;           //����д������
	 ECanbMboxes.MBOX31.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS31 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA31 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA31 = 1; 							   //	д1��0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//���� ����30
void CANSendM30(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX30.MDH.all = can_send_data->MDH.all;           //����д������
	 ECanbMboxes.MBOX30.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS30 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA30 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA30 = 1; 							   //	д1��0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//���� ����29
void CANSendM29(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX29.MDH.all = can_send_data->MDH.all;           //����д������
	 ECanbMboxes.MBOX29.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS29 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA29 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA29 = 1; 							   //	д1��0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}


//�����ж�����
void CAN_Rx_IT_Config(void){

	EALLOW;

	ECanbRegs.CANMIM.bit.MIM0 = 1;//ʹ���ж�����1���ж�;
	ECanbRegs.CANMIL.bit.MIL0 = 1;//���ж�1�������ж�1;
	ECanbRegs.CANGIM.bit.I1EN = 1; //ʹ���ж�1;

	ECanbRegs.CANGIF1.all = 0xFFFFFFFF;

	EDIS;


}
