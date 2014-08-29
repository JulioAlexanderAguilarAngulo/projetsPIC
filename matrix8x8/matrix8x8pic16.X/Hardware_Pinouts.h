/* 
 * File:   Hardware_Pinouts.h
 * Author: Julito
 *
 * Created on 29 août 2014, 10:42
 */

#ifndef HARDWARE_PINOUTS_H
#define	HARDWARE_PINOUTS_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#define SpiClock    PORTAbits.RA1 // RC0  SRCLK-SH_CP
#define SpiClockdir TRISAbits.TRISA1 // RC0

#define SpiData     PORTAbits.RA2 // RA4 or RC2  DS
#define SpiDatadir  TRISAbits.TRISA2 // RA4 or RC2

#define RowPort     PORTB
#define RowPortdir  TRISB

#define INPUT_PIN   1
#define OUTPUT_PIN   0
#define OUTPUT_PORT  0x00

#define MODULE_ON   1
#define MODULE_OFF   0

#endif	/* HARDWARE_PINOUTS_H */

