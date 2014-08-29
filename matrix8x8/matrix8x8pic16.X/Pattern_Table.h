/* 
 * File:   Hardware_Pinouts.h
 * Author: Julito
 *
 * Created on 29 août 2014, 10:42
 */

#ifndef PATTERN_TABLE_H
#define	PATTERN_TABLE_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
const char ColumnScan[]={
                            0b01111111,
                            0b10111111,
                            0b11011111,
                            0b11101111,
                            0b11110111,
                            0b11111011,
                            0b11111101,
                            0b11111110,
                            0b11111111 //force turn off
                            };

const char Patterns[]={
                            0b00000000,
                            0b00111100,
                            0b00111100,
                            0b00111100,
                            0b11111111,
                            0b01111110,
                            0b00111100,
                            0b00011000,

                            0b00011000,
                            0b00100100,
                            0b01011010,
                            0b10100101,
                            0b10100101,
                            0b01011010,
                            0b00100100,
                            0b00011000

                            };

#endif	/* HARDWARE_PINOUTS_H */

