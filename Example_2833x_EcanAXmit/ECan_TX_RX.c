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

//发送 邮箱0
void CANSendM0(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX0.MDH.all = can_send_data->MDH.all;           //数据写进邮箱
	 ECanbMboxes.MBOX0.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS0 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA0 != 1 ){}; 					   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA0 = 1; 							   //	写1清0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//发送 邮箱1
void CANSendM1(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX1.MDH.all = can_send_data->MDH.all;           //数据写进邮箱
	 ECanbMboxes.MBOX1.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS1 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA1 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA1 = 1; 							   //	写1清0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//发送 邮箱2
void CANSendM2(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX2.MDH.all = can_send_data->MDH.all;           //数据写进邮箱
	 ECanbMboxes.MBOX2.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS2 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA2 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA2 = 1; 							   //	写1清0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//发送 邮箱3
void CANSendM3(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX3.MDH.all = can_send_data->MDH.all;           //数据写进邮箱
	 ECanbMboxes.MBOX3.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS3 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA3 != 1 ){};					   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA3 = 1; 							   //	写1清0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//发送 邮箱4
void CANSendM4(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX4.MDH.all = can_send_data->MDH.all;           //数据写进邮箱
	 ECanbMboxes.MBOX4.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS4 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA4 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA4 = 1; 							   //	写1清0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//发送 邮箱5
void CANSendM5(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX5.MDH.all = can_send_data->MDH.all;           //数据写进邮箱
	 ECanbMboxes.MBOX5.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS5 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA5 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA5 = 1; 							   //	写1清0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//发送 邮箱6
void CANSendM6(struct CAN_Message *can_send_data){

	 ECanbMboxes.MBOX6.MDH.all = can_send_data->MDH.all;           //数据写进邮箱
	 ECanbMboxes.MBOX6.MDL.all = can_send_data->MDL.all;

	 ECanbShadow.CANTRS.all = 0;								   //
	 ECanbShadow.CANTRS.bit.TRS6 = 1;                   		   //
	 ECanbRegs.CANTRS.all = ECanbShadow.CANTRS.all;

	 while(ECanbRegs.CANTA.bit.TA6 != 1 ){};				   // Wait for TA0 bit to be set..

	 ECanbShadow.CANTA.all = 0;
	 ECanbShadow.CANTA.bit.TA6 = 1; 							   //	写1清0
	 ECanbRegs.CANTA.all = ECanbShadow.CANTA.all;
}

//接收中断配置
void CAN_Rx_IT_Config(void){

	EALLOW;

	ECanbRegs.CANMIM.bit.MIM0 = 1;//使能中断邮箱0的中断;
	ECanbRegs.CANMIL.bit.MIL0 = 1;//将中断连接至中断1;
	ECanbRegs.CANGIM.bit.I1EN = 1; //使能中断1;

	ECanbRegs.CANGIF1.all = 0xFFFFFFFF;

	EDIS;


}
