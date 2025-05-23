.NOLIST
;***** THIS IS A MACHINE GENERATED FILE - DO NOT EDIT ********************
;***** Created: 2005-01-11 10:30 ******* Source: AT90S1200.xml ***********
;*************************************************************************
;* A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
;* 
;* Number            : AVR000
;* File Name         : "1200def.inc"
;* Title             : Register/Bit Definitions for the AT90S1200
;* Date              : 2005-01-11
;* Version           : 2.14
;* Support E-mail    : avr@atmel.com
;* Target MCU        : AT90S1200
;* 
;* DESCRIPTION
;* When including this file in the assembly program file, all I/O register 
;* names and I/O register bit names appearing in the data book can be used.
;* In addition, the six registers forming the three data pointers X, Y and 
;* Z have been assigned names XL - ZH. Highest RAM address for Internal 
;* SRAM is also defined 
;* 
;* The Register names are represented by their hexadecimal address.
;* 
;* The Register Bit names are represented by their bit number (0-7).
;* 
;* Please observe the difference in using the bit names with instructions
;* such as "sbr"/"cbr" (set/clear bit in register) and "sbrs"/"sbrc"
;* (skip if bit in register set/cleared). The following example illustrates
;* this:
;* 
;* in    r16,PORTB             ;read PORTB latch
;* sbr   r16,(1<<PB6)+(1<<PB5) ;set PB6 and PB5 (use masks, not bit#)
;* out   PORTB,r16             ;output to PORTB
;* 
;* in    r16,TIFR              ;read the Timer Interrupt Flag Register
;* sbrc  r16,TOV0              ;test the overflow flag (use bit#)
;* rjmp  TOV0_is_set           ;jump if set
;* ...                         ;otherwise do something else
;*************************************************************************

#ifndef _1200DEF_INC_
#define _1200DEF_INC_


#pragma partinc 0

; ***** SPECIFY DEVICE ***************************************************
.device AT90S1200
#pragma AVRPART ADMIN PART_NAME AT90S1200
.equ	SIGNATURE_000	= 0x1e
.equ	SIGNATURE_001	= 0x90
.equ	SIGNATURE_002	= 0x01

#pragma AVRPART CORE CORE_VERSION V0


; ***** I/O REGISTER DEFINITIONS *****************************************
; NOTE:
; Definitions marked "MEMORY MAPPED"are extended I/O ports
; and cannot be used with IN/OUT instructions
.equ	SREG	= 0x3f
.equ	GIMSK	= 0x3b
.equ	TIMSK	= 0x39
.equ	TIFR	= 0x38
.equ	MCUCR	= 0x35
.equ	TCCR0	= 0x33
.equ	TCNT0	= 0x32
.equ	WDTCR	= 0x21
.equ	EEAR	= 0x1e
.equ	EEDR	= 0x1d
.equ	EECR	= 0x1c
.equ	PORTB	= 0x18
.equ	DDRB	= 0x17
.equ	PINB	= 0x16
.equ	PORTD	= 0x12
.equ	DDRD	= 0x11
.equ	PIND	= 0x10
.equ	ACSR	= 0x08


; ***** BIT DEFINITIONS **************************************************

; ***** TIMER_COUNTER_0 **************
; TIMSK - Timer/Counter Interrupt Mask Register
.equ	TOIE0	= 1	; Timer/Counter0 Overflow Interrupt Enable

; TIFR - Timer/Counter Interrupt Flag register
.equ	TOV0	= 1	; Timer/Counter0 Overflow Flag

; TCCR0 - Timer/Counter0 Control Register
.equ	CS00	= 0	; Clock Select0 bit 0
.equ	CS01	= 1	; Clock Select0 bit 1
.equ	CS02	= 2	; Clock Select0 bit 2

; TCNT0 - Timer Counter 0
.equ	TCNT00	= 0	; Timer Counter 0 bit 0
.equ	TCNT01	= 1	; Timer Counter 0 bit 1
.equ	TCNT02	= 2	; Timer Counter 0 bit 2
.equ	TCNT03	= 3	; Timer Counter 0 bit 3
.equ	TCNT04	= 4	; Timer Counter 0 bit 4
.equ	TCNT05	= 5	; Timer Counter 0 bit 5
.equ	TCNT06	= 6	; Timer Counter 0 bit 6
.equ	TCNT07	= 7	; Timer Counter 0 bit 7


; ***** WATCHDOG *********************
; WDTCR - Watchdog Timer Control Register
.equ	WDP0	= 0	; Watch Dog Timer Prescaler bit 0
.equ	WDP1	= 1	; Watch Dog Timer Prescaler bit 1
.equ	WDP2	= 2	; Watch Dog Timer Prescaler bit 2
.equ	WDE	= 3	; Watch Dog Enable


; ***** PORTB ************************
; PORTB - Port B Data Register
.equ	PORTB0	= 0	; Port B Data Register bit 0
.equ	PB0	= 0	; For compatibility
.equ	PORTB1	= 1	; Port B Data Register bit 1
.equ	PB1	= 1	; For compatibility
.equ	PORTB2	= 2	; Port B Data Register bit 2
.equ	PB2	= 2	; For compatibility
.equ	PORTB3	= 3	; Port B Data Register bit 3
.equ	PB3	= 3	; For compatibility
.equ	PORTB4	= 4	; Port B Data Register bit 4
.equ	PB4	= 4	; For compatibility
.equ	PORTB5	= 5	; Port B Data Register bit 5
.equ	PB5	= 5	; For compatibility
.equ	PORTB6	= 6	; Port B Data Register bit 6
.equ	PB6	= 6	; For compatibility
.equ	PORTB7	= 7	; Port B Data Register bit 7
.equ	PB7	= 7	; For compatibility

; DDRB - Port B Data Direction Register
.equ	DDB0	= 0	; Port B Data Direction Register bit 0
.equ	DDB1	= 1	; Port B Data Direction Register bit 1
.equ	DDB2	= 2	; Port B Data Direction Register bit 2
.equ	DDB3	= 3	; Port B Data Direction Register bit 3
.equ	DDB4	= 4	; Port B Data Direction Register bit 4
.equ	DDB5	= 5	; Port B Data Direction Register bit 5
.equ	DDB6	= 6	; Port B Data Direction Register bit 6
.equ	DDB7	= 7	; Port B Data Direction Register bit 7

; PINB - Port B Input Pins
.equ	PINB0	= 0	; Port B Input Pins bit 0
.equ	PINB1	= 1	; Port B Input Pins bit 1
.equ	PINB2	= 2	; Port B Input Pins bit 2
.equ	PINB3	= 3	; Port B Input Pins bit 3
.equ	PINB4	= 4	; Port B Input Pins bit 4
.equ	PINB5	= 5	; Port B Input Pins bit 5
.equ	PINB6	= 6	; Port B Input Pins bit 6
.equ	PINB7	= 7	; Port B Input Pins bit 7


; ***** PORTD ************************
; PORTD - Data Register, Port D
.equ	PORTD0	= 0	; 
.equ	PD0	= 0	; For compatibility
.equ	PORTD1	= 1	; 
.equ	PD1	= 1	; For compatibility
.equ	PORTD2	= 2	; 
.equ	PD2	= 2	; For compatibility
.equ	PORTD3	= 3	; 
.equ	PD3	= 3	; For compatibility
.equ	PORTD4	= 4	; 
.equ	PD4	= 4	; For compatibility
.equ	PORTD5	= 5	; 
.equ	PD5	= 5	; For compatibility
.equ	PORTD6	= 6	; 
.equ	PD6	= 6	; For compatibility

; DDRD
.equ	DDD0	= 0	; 
.equ	DDD1	= 1	; 
.equ	DDD2	= 2	; 
.equ	DDD3	= 3	; 
.equ	DDD4	= 4	; 
.equ	DDD5	= 5	; 
.equ	DDD6	= 6	; 

; PIND - Input Pins, Port D
.equ	PIND0	= 0	; 
.equ	PIND1	= 1	; 
.equ	PIND2	= 2	; 
.equ	PIND3	= 3	; 
.equ	PIND4	= 4	; 
.equ	PIND5	= 5	; 
.equ	PIND6	= 6	; 


; ***** ANALOG_COMPARATOR ************
; ACSR - Analog Comparator Control And Status Register
.equ	ACIS0	= 0	; Analog Comparator Interrupt Mode Select bit 0
.equ	ACIS1	= 1	; Analog Comparator Interrupt Mode Select bit 1
.equ	ACIE	= 3	; Analog Comparator Interrupt Enable
.equ	ACI	= 4	; Analog Comparator Interrupt Flag
.equ	ACO	= 5	; Analog Comparator Output
.equ	ACD	= 7	; Analog Comparator Disable


; ***** CPU **************************
; SREG - Status Register
.equ	SREG_C	= 0	; Carry Flag
.equ	SREG_Z	= 1	; Zero Flag
.equ	SREG_N	= 2	; Negative Flag
.equ	SREG_V	= 3	; Two's Complement Overflow Flag
.equ	SREG_S	= 4	; Sign Bit
.equ	SREG_H	= 5	; Half Carry Flag
.equ	SREG_T	= 6	; Bit Copy Storage
.equ	SREG_I	= 7	; Global Interrupt Enable

; MCUCR - MCU Control Register
.equ	ISC00	= 0	; Interrupt Sense Control 0 bit 0
.equ	ISC01	= 1	; Interrupt Sense Control 0 bit 1
.equ	SM	= 4	; Sleep Mode
.equ	SE	= 5	; Sleep Enable


; ***** EXTERNAL_INTERRUPT ***********
; GIMSK - General Interrupt Mask Register
.equ	INT0	= 6	; External Interrupt Request 0 Enable


; ***** EEPROM ***********************
; EEAR - EEPROM Read/Write Access
.equ	EEAR0	= 0	; EEPROM Read/Write Access bit 0
.equ	EEAR1	= 1	; EEPROM Read/Write Access bit 1
.equ	EEAR2	= 2	; EEPROM Read/Write Access bit 2
.equ	EEAR3	= 3	; EEPROM Read/Write Access bit 3
.equ	EEAR4	= 4	; EEPROM Read/Write Access bit 4
.equ	EEAR5	= 5	; EEPROM Read/Write Access bit 5
.equ	EEAR6	= 6	; EEPROM Read/Write Access bit 6

; EEDR - EEPROM Data Register
.equ	EEDR0	= 0	; EEPROM Data Register bit 0
.equ	EEDR1	= 1	; EEPROM Data Register bit 1
.equ	EEDR2	= 2	; EEPROM Data Register bit 2
.equ	EEDR3	= 3	; EEPROM Data Register bit 3
.equ	EEDR4	= 4	; EEPROM Data Register bit 4
.equ	EEDR5	= 5	; EEPROM Data Register bit 5
.equ	EEDR6	= 6	; EEPROM Data Register bit 6
.equ	EEDR7	= 7	; EEPROM Data Register bit 7

; EECR - EEPROM Control Register
.equ	EERE	= 0	; EEPROM Read Enable
.equ	EEWE	= 1	; EEPROM Write Enable



; ***** LOCKSBITS ********************************************************
.equ	LB1	= 0	; Lockbit
.equ	LB2	= 1	; Lockbit


; ***** FUSES ************************************************************
; LOW fuse bits



; ***** CPU REGISTER DEFINITIONS *****************************************
.def	XH	= r27
.def	XL	= r26
.def	YH	= r29
.def	YL	= r28
.def	ZH	= r31
.def	ZL	= r30



; ***** DATA MEMORY DECLARATIONS *****************************************
.equ	FLASHEND	= 0x01ff	; Note: Word address
.equ	IOEND	= 0x003f
.equ	SRAM_SIZE	= 0
.equ	RAMEND	= 0x0000
.equ	XRAMEND	= 0x0000
.equ	E2END	= 0x003f
.equ	EEPROMEND	= 0x003f
.equ	EEADRBITS	= 6
#pragma AVRPART MEMORY PROG_FLASH 1024
#pragma AVRPART MEMORY EEPROM 64
#pragma AVRPART MEMORY INT_SRAM SIZE 0
#pragma AVRPART MEMORY INT_SRAM START_ADDR 0x0





; ***** INTERRUPT VECTORS ************************************************
.equ	INT0addr	= 0x0001	; External Interrupt 0
.equ	OVF0addr	= 0x0002	; Timer/Counter0 Overflow
.equ	ACIaddr	= 0x0003	; Analog Comparator

.equ	INT_VECTORS_SIZE	= 4	; size in words

#pragma AVRPART CORE INSTRUCTIONS_NOT_SUPPORTED break

#endif  /* _1200DEF_INC_ */

; ***** END OF FILE ******************************************************
.LIST