/*
 * cpu_timer0.c
 *
 *  Created on: 2018��4��9��
 *      Author: ASUS
 */
//###########################################################################
//
// FILE:    DSP2833x_CpuTimers.c
//
// TITLE:   CPU 32-bit Timers Initialization & Support Functions.
//
// NOTES:   CpuTimer2 is reserved for use with DSP BIOS and
//          other realtime operating systems.
//
//          Do not use these this timer in your application if you ever plan
//          on integrating DSP-BIOS or another realtime OS.
//
//###########################################################################
// $TI Release: F2833x/F2823x Header Files and Peripheral Examples V140 $
// $Release Date: March  4, 2015 $
// $Copyright: Copyright (C) 2007-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "include//DSP2833x_Device.h"
#include "include//DSP2833x_Examples.h"

struct CPUTIMER_VARS CpuTimer0;     //�����Ĵ����Ľṹ��ָ�룬cpuƵ�ʣ��жϸ��������ڡ�����
struct CPUTIMER_VARS CpuTimer1;

//InitCpuTimers:
//
//This function initializes CPU timer0 to a known state.
//
void InitalCpuTimers(struct CPUTIMER_VARS *CpuTimerX, struct CPUTIMER_REGS *CpuTimerXRegs){
	//��ʼ��CPU��ʱ��

	CpuTimerX->RegsAddr = CpuTimerXRegs;

	CpuTimerXRegs->PRD.all = 0xFFFFFFFF;	//��ʼ�� ����ֵΪȫ1ֵ

	CpuTimerXRegs->TPR.all = 0;				//��Ƶ��ʱ�Ӻ�ϵͳʱ��ͬ��
	CpuTimerXRegs->TPRH.all = 0;

	CpuTimerXRegs->TCR.bit.TSS = 1;			//����ʱ��ֹͣ
	CpuTimerXRegs->TCR.bit.TRB = 1;			//ʹ�ܶ�ʱ�����أ�������

	CpuTimerX->InterruptCount = 0;			//�жϴ���������ʼ��Ϊ0
}
//InitCPUtimers
//void InitCpuTimers(void){
	/*CpuTimer0������CpuTimer0Resgs����ͬ�ṹ���ָ�룬��Ϊ�˼����еĳ���ͬʱ���Ĵ�������CPUTimer0��
	 * ��������������CpuTimer0Regs.h �ļ������ж���*/

	//��Cpu��ʱ��0�Ĵ�����Cpu��ʱ��0������
//	CpuTimer0.RegsAddr = &CpuTimer0Regs;

	//��Cpu��ʱ���Ĵ������г�ʼ��
//	CpuTimer0Regs.PRD.all = 0xFFFFFFFF;					//��PRD��TIMװ�����ݵ���Դ��ʼ�������

//	CpuTimer0Regs.TPR.all= 0;
//	CpuTimer0Regs.TPRH.all = 0;							//��psc����Ϊ��ϵͳʱ��������ͬ��

//	CpuTimer0Regs.TCR.bit.TSS = 1;						//����ʱ��ֹͣ

//	CpuTimer0Regs.TCR.bit.TRB = 1;						//����װ�ؼ�����
//
//	CpuTimer0.InterruptCount = 0;						//�жϴ�����ʼ��Ϊ0

//}

void ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period){
	Uint32 temp;
	Timer->CPUFreqInMHz = Freq;
	Timer->PeriodInUSec = Period;
	temp = (long) (Freq * Period);
	Timer->RegsAddr->PRD.all = temp;							//��ƶ�ʱ���Ĵ�����PRD������������ֵ

	Timer->RegsAddr->TPR.all = 0;
	Timer->RegsAddr->TPRH.all = 0;								//����PSC��ϵͳʱ������ͬ��

	Timer->RegsAddr->TCR.bit.TSS = 1;							//��ʱ��ֹͣ״̬
	Timer->RegsAddr->TCR.bit.TRB = 1;							//���¼��ؼ�����ֵ
	Timer->RegsAddr->TCR.bit.FREE = 0;
	Timer->RegsAddr->TCR.bit.SOFT = 0;							//Free 1 ��soft 1��ʱ����ʱ���ڳ������ʱҲ������
	Timer->RegsAddr->TCR.bit.TIE = 1;                           //��ʱ���ж�ʹ��

	Timer->InterruptCount = 0;									// ��ʱ���жϴ���,���ڼ���

}





