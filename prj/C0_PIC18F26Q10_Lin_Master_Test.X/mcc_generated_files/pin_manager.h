/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F26Q10
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set DS2 aliases
#define DS2_TRIS                 TRISBbits.TRISB1
#define DS2_LAT                  LATBbits.LATB1
#define DS2_PORT                 PORTBbits.RB1
#define DS2_WPU                  WPUBbits.WPUB1
#define DS2_OD                   ODCONBbits.ODCB1
#define DS2_ANS                  ANSELBbits.ANSELB1
#define DS2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define DS2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define DS2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define DS2_GetValue()           PORTBbits.RB1
#define DS2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define DS2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define DS2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define DS2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define DS2_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define DS2_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define DS2_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define DS2_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set DS3 aliases
#define DS3_TRIS                 TRISBbits.TRISB2
#define DS3_LAT                  LATBbits.LATB2
#define DS3_PORT                 PORTBbits.RB2
#define DS3_WPU                  WPUBbits.WPUB2
#define DS3_OD                   ODCONBbits.ODCB2
#define DS3_ANS                  ANSELBbits.ANSELB2
#define DS3_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define DS3_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define DS3_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define DS3_GetValue()           PORTBbits.RB2
#define DS3_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define DS3_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define DS3_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define DS3_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define DS3_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define DS3_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define DS3_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define DS3_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set DS4 aliases
#define DS4_TRIS                 TRISBbits.TRISB3
#define DS4_LAT                  LATBbits.LATB3
#define DS4_PORT                 PORTBbits.RB3
#define DS4_WPU                  WPUBbits.WPUB3
#define DS4_OD                   ODCONBbits.ODCB3
#define DS4_ANS                  ANSELBbits.ANSELB3
#define DS4_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define DS4_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define DS4_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define DS4_GetValue()           PORTBbits.RB3
#define DS4_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define DS4_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define DS4_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define DS4_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define DS4_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define DS4_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define DS4_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define DS4_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set SW2 aliases
#define SW2_TRIS                 TRISBbits.TRISB5
#define SW2_LAT                  LATBbits.LATB5
#define SW2_PORT                 PORTBbits.RB5
#define SW2_WPU                  WPUBbits.WPUB5
#define SW2_OD                   ODCONBbits.ODCB5
#define SW2_ANS                  ANSELBbits.ANSELB5
#define SW2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SW2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SW2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SW2_GetValue()           PORTBbits.RB5
#define SW2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SW2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SW2_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SW2_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SW2_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set LIN_TX aliases
#define LIN_TX_TRIS                 TRISCbits.TRISC6
#define LIN_TX_LAT                  LATCbits.LATC6
#define LIN_TX_PORT                 PORTCbits.RC6
#define LIN_TX_WPU                  WPUCbits.WPUC6
#define LIN_TX_OD                   ODCONCbits.ODCC6
#define LIN_TX_ANS                  ANSELCbits.ANSELC6
#define LIN_TX_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LIN_TX_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LIN_TX_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LIN_TX_GetValue()           PORTCbits.RC6
#define LIN_TX_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LIN_TX_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LIN_TX_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define LIN_TX_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define LIN_TX_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define LIN_TX_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define LIN_TX_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define LIN_TX_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF5 pin functionality
 * @Example
    IOCBF5_ISR();
 */
void IOCBF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF5_SetInterruptHandler() method.
    This handler is called every time the IOCBF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(IOCBF5_InterruptHandler);

*/
extern void (*IOCBF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF5_SetInterruptHandler() method.
    This handler is called every time the IOCBF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(IOCBF5_DefaultInterruptHandler);

*/
void IOCBF5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/