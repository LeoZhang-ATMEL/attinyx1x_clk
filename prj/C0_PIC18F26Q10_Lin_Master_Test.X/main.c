/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F26Q10
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

uint32_t timeout_tbl[1] = {
    7200000
};
static volatile uint32_t timeout = 0;
void usr_InterruptHandler(void)
{
    timeout++;
}
/*
                         Main application
 */
void main(void)
{
    uint32_t i;
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    TMR2_SetInterruptHandler(usr_InterruptHandler);
    TMR2_StartTimer();
    while (1)
    {
        for (i  = 0; i < 1; i++) {
            
            LIN_TX_SetLow();
            __delay_ms(1);
            LIN_TX_SetHigh();
            uint32_t t = timeout_tbl[i];
            uint32_t tp = t / 4;
            uint32_t tleft = 0;
            timeout = 0;
            while (timeout < t) {
                if (timeout >= (tp*3)) {
                    RB0PPS = 0x00;
                    RB1PPS = 0x00;
                    RB2PPS = 0x00;
                    RB3PPS = 0x05;   //RB0->CCP1:CCP1;
                    
                    RB0_SetLow();
                    DS2_SetLow();
                    DS3_SetLow();
                    //DS4_SetHigh();
                    
                    tleft = tp - (timeout - tp*3);
                } else if (timeout >= (tp*2)) {
                    RB0PPS = 0x00;
                    RB1PPS = 0x00;
                    RB2PPS = 0x05;   //RB0->CCP1:CCP1;
                    RB1PPS = 0x00;

                    RB0_SetLow();
                    DS2_SetLow();
                    //DS3_SetHigh();
                    DS4_SetHigh();
                    tleft = tp - (timeout - tp*2);
                } else if (timeout >= (tp)) {
                    RB0PPS = 0x00;
                    RB1PPS = 0x05;   //RB0->CCP1:CCP1;
                    RB2PPS = 0x00;
                    RB3PPS = 0x00;
                    
                    RB0_SetLow();
                    //DS2_SetLow();
                    DS3_SetHigh();
                    DS4_SetHigh();
                    tleft = tp - (timeout - tp);
                } else {
                    RB0PPS = 0x05;   //RB0->CCP1:CCP1;
                    RB1PPS = 0x00;
                    RB2PPS = 0x00;
                    RB3PPS = 0x00;
                    
                    //RB0_SetHigh();
                    DS2_SetHigh();
                    DS3_SetHigh();
                    DS4_SetHigh();
                    
                    tleft = tp - (timeout);
                }
                float fl = ((float)tleft) / ((float)tp);
                fl = fl * (0x3EC0 >> 6);
                
                PWM1_LoadDutyValue((uint16_t)fl);
            }
        }
        // Add your application code
    }
}
/**
 End of File
*/