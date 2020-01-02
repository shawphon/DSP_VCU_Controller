/*
 * cpu_timer0.c
 *
 *  Created on: 2018年4月9日
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

struct CPUTIMER_VARS CpuTimer0;     //包含寄存器的结构体指针，cpu频率，中断个数，周期。。。
struct CPUTIMER_VARS CpuTimer1;

//InitCpuTimers:
//
//This function initializes CPU timer0 to a known state.
//
void InitalCpuTimers(struct CPUTIMER_VARS *CpuTimerX, struct CPUTIMER_REGS *CpuTimerXRegs){
	//初始化CPU定时器

	CpuTimerX->RegsAddr = CpuTimerXRegs;

	CpuTimerXRegs->PRD.all = 0xFFFFFFFF;	//初始化 周期值为全1值

	CpuTimerXRegs->TPR.all = 0;				//分频后时钟和系统时钟同步
	CpuTimerXRegs->TPRH.all = 0;

	CpuTimerXRegs->TCR.bit.TSS = 1;			//将定时器停止
	CpuTimerXRegs->TCR.bit.TRB = 1;			//使能定时器重载，并重载

	CpuTimerX->InterruptCount = 0;			//中断次数计数初始化为0
}
//InitCPUtimers
//void InitCpuTimers(void){
	/*CpuTimer0中设有CpuTimer0Resgs的相同结构体的指针，是为了简化下列的程序，同时将寄存器并入CPUTimer0中
	 * 这两个变量都在CpuTimer0Regs.h 文件中已有定义*/

	//将Cpu定时器0寄存器和Cpu定时器0相联接
//	CpuTimer0.RegsAddr = &CpuTimer0Regs;

	//对Cpu定时器寄存器进行初始化
//	CpuTimer0Regs.PRD.all = 0xFFFFFFFF;					//将PRD（TIM装载数据的来源初始化成最大）

//	CpuTimer0Regs.TPR.all= 0;
//	CpuTimer0Regs.TPRH.all = 0;							//将psc设置为和系统时钟脉冲相同步

//	CpuTimer0Regs.TCR.bit.TSS = 1;						//将定时器停止

//	CpuTimer0Regs.TCR.bit.TRB = 1;						//重新装载计数器
//
//	CpuTimer0.InterruptCount = 0;						//中断次数初始化为0

//}

void ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period){
	Uint32 temp;
	Timer->CPUFreqInMHz = Freq;
	Timer->PeriodInUSec = Period;
	temp = (long) (Freq * Period);
	Timer->RegsAddr->PRD.all = temp;							//设计定时器寄存器中PRD计数器的重载值

	Timer->RegsAddr->TPR.all = 0;
	Timer->RegsAddr->TPRH.all = 0;								//设置PSC和系统时钟脉冲同步

	Timer->RegsAddr->TCR.bit.TSS = 1;							//定时器停止状态
	Timer->RegsAddr->TCR.bit.TRB = 1;							//重新加载计数器值
	Timer->RegsAddr->TCR.bit.FREE = 0;
	Timer->RegsAddr->TCR.bit.SOFT = 0;							//Free 1 ；soft 1；时：定时器在程序调试时也在运行
	Timer->RegsAddr->TCR.bit.TIE = 1;                           //定时器中断使能

	Timer->InterruptCount = 0;									// 定时器中断次数,用于计数

}





