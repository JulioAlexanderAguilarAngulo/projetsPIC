/*********************************************************
 * File:   main_8x8matrixv001.c
 * Authors:
 *   1)     Julio Alexander Aguilar Angulo.  juloaguilar@gmail.com
 *          ISEN-Toulon. Toulon, France.
 *
 *
 * Description:
 *
 *  Firmware to Control a 8x8 LED Sign Board
 *
 *
 * History:
 *
 *      V0.01a: Initial Dummy Code template and structured definitions
 *             - hardware target: Pedro Sanchez board (available as sch-brd)
 *      V0.01b: Spi-Like Shift Register Function Added inside main file
 *      V0.01c: Matrix Test initial Code.
 *
 * Created on 29 août 2014, 10:25
 * Licensing based on the MIT License.
 *  */

#include <xc.h>
#include <pic16f628A.h>
#include "Hardware_Pinouts.h"

#include "Pattern_Table.h"

#pragma config CP=OFF, CPD=OFF, BOREN=OFF, WDTE=OFF
#pragma config PWRTE=OFF, FOSC=INTOSCIO, MCLRE=OFF, LVP=OFF

#define _XTAL_FREQ 4000000 // in order to use the built-in delay (to change later)
        
char    video_buffer[64];
char    temp_X,temp_Y;
char    i;
void SendData(char data);

void main(void) {

    CMCON=0b111;// comparators OFF
    VRCONbits.VREN=0X00;//internal ref off
    SpiDatadir = OUTPUT_PIN;
    SpiClockdir = OUTPUT_PIN;
    RowPortdir = OUTPUT_PORT;
    RowPort = 0x00;


    while(1){
        SendData(ColumnScan[1]);
        RowPort=Patterns[i];
        i++;i&=0b111;
        __delay_ms(20);

    }
    return;
}


void SendData(char data){
unsigned char LOOP, FLAG;

RowPort=0x00;
for (LOOP=0; LOOP<8; LOOP++)
    {
     FLAG=data&0x01;
        if(FLAG==0) SpiData=0;
        else    SpiData=1;

    SpiClock = 1;
    SpiClock = 0;
    data >>= 1;
    }
}

