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

//发送 邮箱31
void CANaSendM31(struct CAN_Message *can_send_data){

	 ECanaMboxes.MBOX31.MDH.all = can_send_data->MDH.all;           //数据写进邮箱
	 ECanaMboxes.MBOX31.MDL.all = can_send_data->MDL.all;

	 ECanaShadow.CANTRS.all = 0;								   //
	 ECanaShadow.CANTRS.bit.TRS31 = 1;                   		   //
	 ECanaRegs.CANTRS.all = ECanaShadow.CANTRS.all;
	 do
	 {
	 ECanaShadow.CANTA.all = ECanaRegs.CANTA.all;
	 } while(ECanaShadow.CANTA.bit.TA31 == 0 ); 					   // Wait for TA0 bit to be set..

	 ECanaShadow.CANTA.all = 0;
	 ECanaShadow.CANTA.bit.TA31 = 1; 							   //	写1清0
	 ECanaRegs.CANTA.all = ECanaShadow.CANTA.all;
}

//发送 邮箱30
void CANaSendM30(struct CAN_Message *can_send_data){

	 ECanaMboxes.MBOX30.MDH.all = can_send_data->MDH.all;           //数据写进邮箱
	 ECanaMboxes.MBOX30.MDL.all = can_send_data->MDL.all;

	 ECanaShadow.CANTRS.all = 0;								   //
	 ECanaShadow.CANTRS.bit.TRS30 = 1;                   		   //
	 ECanaRegs.CANTRS.all = ECanaShadow.CANTRS.all;
	 do
	 {
	 ECanaShadow.CANTA.all = ECanaRegs.CANTA.all;
	 } while(ECanaShadow.CANTA.bit.TA30 == 0 ); 					   // Wait for TA0 bit to be set..

	 ECanaShadow.CANTA.all = 0;
	 ECanaShadow.CANTA.bit.TA30 = 1; 							   //	写1清0
	 ECanaRegs.CANTA.all = ECanaShadow.CANTA.all;
}


//接收中断配置
void CAN_Rx_IT_Config(void){

	EALLOW;

	ECanaRegs.CANMIM.bit.MIM0 = 1;//使能中断邮箱0的中断;
	ECanaRegs.CANMIL.bit.MIL0 = 1;//将中断1连接至中断1;

	ECanaRegs.CANGIM.bit.I1EN = 1; //使能中断1;
	ECanaRegs.CANGIF1.all = 0xFFFFFFFF;

	EDIS;
}
