//###########################################################################
// Filename: Example_28xEcan_A_to_B_Xmit.c
//
// Description: eCAN-A To eCAN-B TXLOOP - Transmit loop
//
// ASSUMPTIONS:
//
//    This program requires the DSP2833x header files.
//
//    Both CAN ports of the 2833x DSP need to be connected
//    to each other (via CAN transceivers)
//
//       eCANA is on GPIO19 (CANTXA)  and
//                   GPIO18 (CANRXA)
//
//       eCANB is on GPIO16  (CANTXB)  and
//                   GPIO17 (CANRXB)
//
//    As supplied, this project is configured for "boot to SARAM"
//    operation.  The 2833x Boot Mode table is shown below.
//    For information on configuring the boot mode of an eZdsp,
//    please refer to the documentation included with the eZdsp,
//
//       $Boot_Table:
//
//         GPIO87   GPIO86     GPIO85   GPIO84
//          XA15     XA14       XA13     XA12
//           PU       PU         PU       PU
//        ==========================================
//            1        1          1        1    Jump to Flash
//            1        1          1        0    SCI-A boot
//            1        1          0        1    SPI-A boot
//            1        1          0        0    I2C-A boot
//            1        0          1        1    eCAN-A boot
//            1        0          1        0    McBSP-A boot
//            1        0          0        1    Jump to XINTF x16
//            1        0          0        0    Jump to XINTF x32
//            0        1          1        1    Jump to OTP
//            0        1          1        0    Parallel GPIO I/O boot
//            0        1          0        1    Parallel XINTF boot
//            0        1          0        0    Jump to SARAM	    <- "boot to SARAM"
//            0        0          1        1    Branch to check boot mode
//            0        0          1        0    Boot to flash, bypass ADC cal
//            0        0          0        1    Boot to SARAM, bypass ADC cal
//            0        0          0        0    Boot to SCI-A, bypass ADC cal
//                                              Boot_Table_End$
//
// DESCRIPTION:
//	  2019-12-3
//	  ���ڵ���򣬿�����������ʱ����������Ϣ�ķ��ͣ���ʱ��0��������ΪTTCAN�е�
//	  һ��BC �����ڴ�С5ms����Ҫ���ڲο���Ϣ�ķ��ͣ���ʱ��1��������Ϊ1us����Ҫ����
//	  ����ʱ�䴰�ڣ����ڶ�ռ����can���ĵķ��͡�

//	  Follow ignored
//    This example TRANSMITS data to another CAN module using MAILBOX5
//    This program could either loop forever or transmit "n" # of times,
//    where "n" is the TXCOUNT value.
//
//    This example can be used to check CAN-A and CAN-B. Since CAN-B is
//    initialized in DSP2833x_ECan.c, it will acknowledge all frames
//    transmitted by the node on which this code runs. Both CAN ports of
//    the 2833x DSP need to be connected to each other (via CAN transceivers)
//
//###########################################################################
// Original Author: HJ
//
// $TI Release: 2833x/2823x Header Files and Peripheral Examples V133 $
// $Release Date: June 8, 2012 $
//###########################################################################

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

struct ECAN_REGS ECanbShadow;
struct ECAN_REGS ECanaShadow;
//###########################################################################
/*
   struct  CANMDLBYTES {      // bits   description                         //MDL
   Uint16      speed1:12;     // 31:20
   Uint16      function1:4;     // 19:16
   Uint16      speed0:12;     // 15:4
   Uint16      function0:4;     // 3:0
};
struct  CANMDLWORDS {      // bits  description
   Uint16      LOW_WORD:16; // 0:15
   Uint16      HI_WORD:16;  // 31:16
};
union CANMDLREG {
   Uint32                all;
   struct CANMDLWORDS   word;
   struct CANMDLBYTES   byte;
};
//###########################################################################
struct  CANMDHWORDS {         // bits  description                       //MDH
   Uint16      LOW_WORD:16;    // 0:15
   Uint16      HI_WORD:16;     // 31:16
};
struct  CANMDHBYTES {      // bits   description
   Uint16      BYTE7:8;     // 63:56
   Uint16      BYTE6:8;     // 55:48
   Uint16      BYTE5:8;     // 47:40
   Uint16      BYTE4:8;     // 39:32
};
union CANMDHREG {
   Uint32                  all;
   struct CANMDHWORDS     word;
   struct CANMDHBYTES     byte;
};
//###########################################################################
struct  CANMSGIDBITS {        // bits  description                        //ID
   Uint16      EXTMSGID_L:16;  // 0:15
   Uint16      EXTMSGID_H:2;   // 16:17
   Uint16      STDMSGID:11;    // 18:28
   Uint16      AAM:1;          // 29
   Uint16      AME:1;          // 30
   Uint16      IDE:1;          // 31
};

union CANMSGIDREG {
   Uint32                all;
   struct CANMSGIDBITS  bit;
};
//###########################################################################
struct CAN_Message {
	union CANMSGIDREG     MSGID;
    union CANMDLREG       MDL;
    union CANMDHREG       MDH;
};*/

extern struct CAN_Message CANMessage_TX;
//###########################################################################
//extern void CANa_Send_Message(struct CAN_Message *can_send_data);
extern void CAN_Rx_IT_Config(void);
void ConfigECANA();
extern void CANa_Send_Message(struct CAN_Message *can_send_data);


void main ()
{
	/*
	 Create a shadow register structure for the CAN control registers. This is
 	 needed, since, only 32-bit access is allowed to these registers. 16-bit access
 	 to these registers could potentially corrupt the register contents. This is
 	 especially true while writing to a bit (or group of bits) among bits 16 - 31
	 */

	// Step 1. Initialize System Control:
	// PLL, WatchDog, enable Peripheral Clocks
	// This example function is found in the DSP2833x_SysCtrl.c file.
	InitSysCtrl();

	// Step 2. Initalize GPIO:
	// This example function is found in the DSP2833x_Gpio.c file and
	// illustrates how to set the GPIO to it's default state.
	// InitGpio();  // Skipped for this example
	// Just initalize eCAN pins for this example
	// This function is in DSP2833x_ECan.c
	//��ʼ��ECANA����
	InitECanGpio();

	// Step 3. Clear all interrupts and initialize PIE vector table:
	// Disable CPU interrupts
	DINT;

	// Initialize the PIE control registers to their default state.
	// The default state is all PIE interrupts disabled and flags
	// are cleared.
	// This function is found in the DSP2833x_PieCtrl.c file.
	InitPieCtrl();

	// Disable CPU interrupts and clear all CPU interrupt flags:
	IER = 0x0000;
	IFR = 0x0000;

	// Initialize the PIE vector table with pointers to the shell Interrupt
	// Service Routines (ISR).
	// This will populate the entire table, even if the interrupt
	// is not used in this example.  This is useful for debug purposes.
	// The shell ISR routines are found in DSP2833x_DefaultIsr.c.
	// This function is found in DSP2833x_PieVect.c.
	InitPieVectTable();

	//ʹ�ܶ�ʱ���жϣ�ECANA���Ͳο���Ϣ�ж�
	EnableInterrupts();

	// Initialize all the Device Peripherals:  (Ignore this Step, no Peris are used in this Program)
	// This function is found in DSP2833x_InitPeripherals.c
	//InitPeripherals();

	// Step 3. In this case just initalize eCAN-A and eCAN-B
	// This function is in DSP2833x_ECan.c
	InitECan();

	/*
	 * Above is completed Version 1.0 Time:2019-11-7
	 * Created by Leslie @ Hohai
	 */
	// Step 4 Confiure ECAN
	ConfigECANA();

	CAN_Rx_IT_Config();           //�������䷢���ж�

	//Step 5 ���ö�ʱ��
	//��ʱ0��ʼ��
	//InitalCpuTimers(&CpuTimer0, CpuTimer0Regs);
	//��ʱ��1��ʼ��
	InitalCpuTimers(&CpuTimer1, CpuTimer1Regs);

	#if (CPU_FRQ_150MHZ)
	// Configure CPU-Timer 0, 1, and 2 to interrupt every msecond:
    // 150MHz CPU Freq, 1 second Pe riod (in uSeconds)
	//��ʱ��0 ����Ϊ5ms����
    //ConfigCpuTimer(&CpuTimer0, 150, 5000);		//CpuTimer0 ���� 5ms
    //��ʱ������Ϊ1us���ڣ�������Ϊ���ڵĵ�λ����ʱ�䣬ÿһ�����ڶ�Ԥ��1us��ʱ����Ϊ��ʱʱ��
    ConfigCpuTimer(&CpuTimer1, 150, 1);	//CpuTimer1 ����1us
	#endif
	#if (CPU_FRQ_100MHZ)
    // Configure CPU-Timer 0, 1, and 2 to interrupt every second:
    // 100MHz CPU Freq, 1 second Period (in uSeconds)
    ConfigCpuTimer(&CpuTimer0, 100, 1000000);
	#endif
    ERTM;                                        //ʹ��ȫ��ʵʱ�ж�

	//CANa_Send_Message(&CANMessage_TX);

	for(;;);
	//asm(" ESTOP0");  // Stop here
}

void ConfigECANA()
{
	EALLOW;

	/*
	 *	Configure Mailboxes 0-6 as Tx, 24-31 as Rx
	 *	Configure Since this write is to the entire register (instead of a bit
	 *	Configure field) a shadow register is not required.
	 * 	����ID����*/
	//CANA ������ ����0 Ϊ�������䣬 ��Ϣ: �ο���Ϣ
	ECanaMboxes.MBOX0.MSGID.all = 0x00000000;
	ECanaMboxes.MBOX0.MSGID.bit.STDMSGID = 0x000F;
	//����1		��������		��ϢM2
	ECanaMboxes.MBOX1.MSGID.all = 0x00000000;
	ECanaMboxes.MBOX1.MSGID.bit.STDMSGID = 0x0002;
	//����2		��������		��ϢM9
	ECanaMboxes.MBOX2.MSGID.all = 0x00000000;
	ECanaMboxes.MBOX2.MSGID.bit.STDMSGID = 0x0009;
	//����3		��������		��ϢM10
	ECanaMboxes.MBOX3.MSGID.all = 0x00000000;
	ECanaMboxes.MBOX3.MSGID.bit.STDMSGID = 0x000A;

	//����31		��������		��ϢM1
	ECanaMboxes.MBOX31.MSGID.all = 0x00000000;
	ECanaMboxes.MBOX31.MSGID.bit.STDMSGID = 0x0001;
	//����30		��������		��ϢM4
	ECanaMboxes.MBOX30.MSGID.all = 0x00000000;
	ECanaMboxes.MBOX30.MSGID.bit.STDMSGID = 0x0004;
	//����29		��������		��ϢM11
	ECanaMboxes.MBOX29.MSGID.all = 0x00000000;
	ECanaMboxes.MBOX29.MSGID.bit.STDMSGID = 0x000B;

	/*
	 * 	���䷽������*/
	ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
	//����0		��������
	ECanaShadow.CANMD.bit.MD0 = 1;
	//����1		��������
	ECanaShadow.CANMD.bit.MD1 = 1;
	//����2		��������
	ECanaShadow.CANMD.bit.MD2 = 1;
	//����3		��������
	ECanaShadow.CANMD.bit.MD3 = 1;

	//����31		��������
	ECanaShadow.CANMD.bit.MD31 = 0;
	//����30		��������
	ECanaShadow.CANMD.bit.MD30 = 0;
	//����29		��������
	ECanaShadow.CANMD.bit.MD29 = 0;

    /*
     * �趨��������ݳ���*/
	//CANA ������ ����0 Ϊ�������䣬 ��Ϣ: �ο���Ϣ
    ECanaMboxes.MBOX0.MSGCTRL.bit.DLC = 1;
	//����1		��������		��ϢM2
    ECanaMboxes.MBOX1.MSGCTRL.bit.DLC = 7;
	//����2		��������		��ϢM9
    ECanaMboxes.MBOX2.MSGCTRL.bit.DLC = 8;
	//����3		��������		��ϢM10
    ECanaMboxes.MBOX3.MSGCTRL.bit.DLC = 8;

	//����31		��������		��ϢM1
    ECanaMboxes.MBOX31.MSGCTRL.bit.DLC = 4;
	//����30		��������		��ϢM4
    ECanaMboxes.MBOX30.MSGCTRL.bit.DLC = 6;
	//����29		��������		��ϢM11
    ECanaMboxes.MBOX29.MSGCTRL.bit.DLC = 8;

    /* Write to the mailbox RAM field */
    EDIS;

    EALLOW;

    /* Begin transmitting */
    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.STM = 0;    // Configure CAN for self-test mode,just configure CAN for normal mode.
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

	ECanaShadow.CANME.all = ECanaRegs.CANME.all;             //����ʹ��
    ECanaShadow.CANME.bit.ME0 = 1;
    ECanaShadow.CANME.bit.ME1 = 1;
    ECanaShadow.CANME.bit.ME2 = 1;
    ECanaShadow.CANME.bit.ME3 = 1;

	ECanaShadow.CANME.bit.ME31 = 1;
	ECanaShadow.CANME.bit.ME30 = 1;
    ECanaShadow.CANME.bit.ME29 = 1;
	ECanaRegs.CANME.all = ECanaShadow.CANME.all;
	EDIS;
}

