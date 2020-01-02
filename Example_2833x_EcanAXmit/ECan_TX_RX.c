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

//���� ����0
void CANSendM0(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX0.MDH.all = can_send_data->MDH.all;           //����д������
	 ECanbMboxes.MBOX0.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS0 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA0 != 1 ){}; 					   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA0 = 1; 							   //	д1��0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//���� ����1
void CANSendM1(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX1.MDH.all = can_send_data->MDH.all;           //����д������
	 ECanbMboxes.MBOX1.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS1 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA1 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA1 = 1; 							   //	д1��0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//���� ����2
void CANSendM2(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX2.MDH.all = can_send_data->MDH.all;           //����д������
	 ECanbMboxes.MBOX2.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS2 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA2 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA2 = 1; 							   //	д1��0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//���� ����3
void CANSendM3(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX3.MDH.all = can_send_data->MDH.all;           //����д������
	 ECanbMboxes.MBOX3.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS3 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA3 != 1 ){};					   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA3 = 1; 							   //	д1��0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//���� ����4
void CANSendM4(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX4.MDH.all = can_send_data->MDH.all;           //����д������
	 ECanbMboxes.MBOX4.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS4 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA4 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA4 = 1; 							   //	д1��0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//���� ����5
void CANSendM5(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX5.MDH.all = can_send_data->MDH.all;           //����д������
	 ECanbMboxes.MBOX5.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS5 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA5 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA5 = 1; 							   //	д1��0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//���� ����6
void CANSendM6(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX6.MDH.all = can_send_data->MDH.all;           //����д������
	 ECanbMboxes.MBOX6.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS6 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA6 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA6 = 1; 							   //	д1��0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//�����ж�����
void CAN_Rx_IT_Config(void){

	EALLOW;

	ECanbRegs.CANMIM.bit.MIM0 = 1;//ʹ���ж�����0���ж�;
	ECanbRegs.CANMIL.bit.MIL0 = 1;//���ж��������ж�1;
	ECanbRegs.CANGIM.bit.I1EN = 1; //ʹ���ж�1;

	ECanbRegs.CANGIF1.all = 0xFFFFFFFF;

	EDIS;


}
