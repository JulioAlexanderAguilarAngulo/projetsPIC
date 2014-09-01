/* File:   main_8x8matrixv001.c
 * Authors:
 *   1)     Julio Alexander Aguilar Angulo.  juloaguilar@gmail.com
 *          ISEN-Toulon. Toulon, France.
 *
 * Description:
 *                    Firmware to Control a 8x8 LED Sign Board
 *
 * History:
 *      V0.01a: Initial Dummy Code template and structured definitions
 *             - hardware target: Pedro Sanchez board (available as sch-brd)
 *      V0.01b: Spi-Like Shift Register Function Added inside main file
 *      V0.01c: Matrix Test initial Code.
 *      V0.01d: Scrolling and negative added.
 *
 * Created on 29 août 2014, 10:25   Licensing under the MIT License.
 */

#include <xc.h>
#include <pic16f628A.h>
#include "Hardware_Pinouts.h"

#include "Pattern_Table.h"

#pragma config CP=OFF, CPD=OFF, BOREN=OFF, WDTE=OFF
#pragma config PWRTE=OFF, FOSC=INTOSCIO, MCLRE=OFF, LVP=OFF

#define _XTAL_FREQ 4000000 // in order to use the built-in delay (to change later)
#define NUMBER_OF_LOOPS 24

const char sequence[]={30,31,32,0};
char    sign_buffer[NUMBER_OF_ROWS],video_buffer[NUMBER_OF_ROWS*NUMBER_OF_COLUMNS],video_line,loop_counter;
char    temp_X,temp_Y,temp;
char    sign_pointer,index,offset_index,table_pointer,k,i,sign_length;
void    SendData(char data);
void    LoadSignBuffer(char index);
void    LoadVideoBuffer(char index);



void main(void) {

    CMCON=0b111;// comparators OFF
    VRCONbits.VREN=0X00;//internal ref off
    SpiDatadir = OUTPUT_PIN;
    SpiClockdir = OUTPUT_PIN;
    RowPortdir = OUTPUT_PORT;
    RowPort = 0x00;

    sign_length=0;
// find string size:
        do{
        k=sequence[sign_length++];
        sign_length++;
        }
    while (!k);


    sign_pointer=0;offset_index=0;k=0;index;loop_counter=0;
    while(1){
        
        SendData(ColumnScan[sign_pointer]);
        LoadSignBuffer(1);
        index=sign_pointer+offset_index;
        index%=8;
        RowPort=sign_buffer[index]^video_line;//soon using video buffer instead
        sign_pointer++;
        sign_pointer&=0b00000111;
        k++;
            if (k==250)
                {
                    offset_index++;
                    if (offset_index==NUMBER_OF_ROWS+1)
                        {
                        offset_index=0;
                        }
                    k=0;
                    loop_counter++;
                    if (loop_counter==NUMBER_OF_LOOPS)
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

for (LOOP=0; LOOP<NUMBER_OF_COLUMNS; LOOP++)
    {
     FLAG=data&0x01;
        if(FLAG==0) SpiData=0;
        else    SpiData=1;

    SpiClock = 1;
    SpiClock = 0;
    data >>= 1;
    }
}

void LoadSignBuffer(char index){
    char table_pointer;
    table_pointer=sequence[index]-30;
    index=0;
    while (index<NUMBER_OF_ROWS)
        {
        sign_buffer[index]=Patterns[NUMBER_OF_COLUMNS*table_pointer+index];
            index++;
        }
}

void LoadVideoBuffer(char index){
    char table_pointer,aa,j ;
    do{
        aa=sequence[j];

    }
    while (!aa);
    table_pointer=sequence[index]-30;
    index=0;
    while (index<NUMBER_OF_ROWS)
        {
        sign_buffer[index]=Patterns[NUMBER_OF_COLUMNS*table_pointer+index];
            index++;
        }
}