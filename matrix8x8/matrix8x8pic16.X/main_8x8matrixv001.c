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
 *      V0.01: Initial Dummy Code template and structured definitions
 *             - hardware target: Pedro Sanchez board (available as sch-brd)
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

char    video_buffer[64];
char    temp_X,temp_Y;


void main(void) {

    CMCON=0b111;// comparators OFF
    VRCONbits.VREN=0X00;//internal ref off
    SpiDatadir = OUTPUT_PIN;
    SpiClockdir = OUTPUT_PIN;
    RowPortdir = OUTPUT_PORT;
    RowPort = 0x00;


    while(1){


    }
    return;
}
