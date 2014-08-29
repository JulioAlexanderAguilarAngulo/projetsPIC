/*
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
 *      V0.01d: Scrolling and negative added.
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
        
char    video_buffer[64],video_line,loop_counter;
char    temp_X,temp_Y;
char    i,index,j,k;
void SendData(char data);

void main(void) {

    CMCON=0b111;// comparators OFF
    VRCONbits.VREN=0X00;//internal ref off
    SpiDatadir = OUTPUT_PIN;
    SpiClockdir = OUTPUT_PIN;
    RowPortdir = OUTPUT_PORT;
    RowPort = 0x00;

    i=0;j=0;k=0;index;loop_counter=0;
    while(1){
        
        SendData(ColumnScan[i]);
        index=i+j;
        index%=8;
        RowPort=Patterns[index]^video_line;
        i++;
        i&=0b00000111;
        k++;
            if (k==250)
                {
                    j++;
                    j&=0b00000111;
                    k=0;
                    loop_counter++;
                    if (loop_counter==16)
                        {
                            video_line^=0xFF;
                            loop_counter=0;
                        }
                }
        __delay_us(500);
        RowPort=0x00;
    }
}


void SendData(char data){
unsigned char LOOP, FLAG;

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

