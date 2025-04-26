nolist

#define true	1
#define false	0
#define call	acall
#define goto	ajmp
#define return	ret

Wait macro _cycles
	mov	20, #_cycles
	djnz	20,$-3

	#ifndef WAIT_WARNING_MESSAGE_SHOWN
	#define WAIT_WARNING_MESSAGE_SHOWN
	#messg "Wait macro uses direct address 0x20. So, don't use this address for storing data."
	#endif
Endm

WritePort macro _port,_dt
	mov _port,#_dt
Endm

ConfigurePortForInput macro _port
	mov _port,#FFH
Endm

ConfigurePortForOutput macro _port
	mov _port,#0
Endm

ConfigurePinForInput macro _pin
	setb _pin
Endm

ConfigurePinForOutput macro _pin
Endm

SetPin macro _pin
	setb _pin
Endm

ClearPin macro _pin
	clr _pin
Endm

InvertPin macro _pin
	cpl _pin
Endm

JumpIfNotEqual macro _src,_dt,_addr
	mov A,_src
	cjne A,#_dt,_addr
Endm

JumpIfEqual macro _src,_dt,_addr
	mov A,_src
	cjne A,#_dt,$+5
	sjmp _addr
Endm

CallIfNotEqual macro _src,_dt,_addr
	mov A,_src
	acall A,#_dt,_addr
Endm

CallIfEqual macro _src,_dt,_addr
	mov A,_src
	cjne A,#_dt,$+5
	acall _addr
Endm


; -------- EXTERNAL INTERRUPT MACROS ------------------------
; -----------------------------------------------------------

OnExternalInterrupt0 macro _addr
	org 0x03
	ajmp _addr
Endm

OnExternalInterrupt1 macro _addr
	org 0x13
	ajmp _addr
Endm

EnableExternalInterrupt0OnFallingEdge macro
	orl 0x88,#1			;select falling edge
	orl 0xA8,#81H		;enable global interrupt and int0

	#ifndef external_int0_messg_shown
		#define external_int0_messg_shown
		#messg "INT0 pin is at P3.2"
	#endif
Endm

EnableExternalInterrupt0 macro
	EnableExternalInterrupt0OnFallingEdge
Endm

EnableExternalInterrupt1OnFallingEdge macro
	orl 0x88,#4			;select falling edge
	orl 0xA8,#84H		;enable global interrupt and int1

	#ifndef external_int1_messg_shown
		#define external_int1_messg_shown
		#messg "INT1 pin is at P3.3"
	#endif
Endm

EnableExternalInterrupt1 macro
	EnableExternalInterrupt1OnFallingEdge
Endm

; -------- TIMER MACROS -------------------------------------
; -----------------------------------------------------------

OnTimer0Interrupt macro _addr
	org 0x0B
	ajmp _addr
Endm

OnTimer1Interrupt macro _addr
	org 0x1B
	ajmp _addr
Endm

OnTimer2Interrupt macro _addr
	org 0x2B
	ajmp _addr
Endm

ShowTimerModes macro
	#ifndef timer_mode_described
		#define timer_mode_described
		#messg "Timer modes in timer/counter mode :";
		#messg "   Mode0 : TLx<4.0> serves as prescaler, THx serves as 8 bit timer/counter)";
		#messg "   Mode1 : THx, TLx serves as 16 bit timer/counter";
		#messg "   Mode2 : TLx serves as timer/counter. On overflow, TLx is loaded from THx. So, range is from THx to 255";
		#messg "   Mode3 : TLx is a 8 bit timer/counter";
		#messg "T0 (Count input for Timer0) is at P3.4";
		#messg "T1 (Count input for Timer1) is at P3.5";
	#endif
Endm

EnableTimer0WithMode macro _mode
	anl 0x89,#F0H		;clear 4 bits of TMOD
	orl 0x89,#(_mode & 3 )  ;Clear GATE0, C/T0 and set mode
	orl 0x88,#10H		;timer0 run control bit TR0
	orl 0xA8,#82H		;enable global interrupt and timer0 interrupt

	ShowTimerModes
Endm

EnableTimer0CounterWithMode macro _mode
	anl 0x89,#F0H			  ;clear 4 bits of TMOD
	orl 0x89,#( (_mode & 3 ) + 4 )  ;Set C/T0 and mode
	orl 0x88,#10H			  ;timer0 run control bit TR0
	orl 0xA8,#82H			  ;enable global interrupt and timer0 interrupt

	ShowTimerModes
Endm

EnableTimer0 macro
	EnableTimer0WithMode 3
Endm

EnableTimer0Counter macro
	EnableTimer0CounterWithMode 3
Endm

EnableTimer1WithMode macro _mode
	anl 0x89,#0FH				;clear 4 MSB bits of TMOD
	orl 0x89,#( (_mode & 3 ) * 16 )  	;Clear GATE1, C/T1 and set mode
	orl 0x88,#40H				;timer1 run control bit TR1
	orl 0xA8,#88H				;enable global interrupt and timer1 interrupt

	ShowTimerModes
Endm

EnableTimer1CounterWithMode macro _mode
	anl 0x89,#0FH					;clear 4 MSB bits of TMOD
	orl 0x89,#( (_mode & 3 ) * 16 + 0x40 )  	;SET C/T1 and mode
	orl 0x88,#40H					;timer1 run control bit TR1
	orl 0xA8,#88H					;enable global interrupt and timer1 interrupt

	ShowTimerModes
Endm

EnableTimer1 macro
	EnableTimer1WithMode 3
Endm

EnableTimer1Counter macro
	EnableTimer1CounterWithMode 3
Endm

EnableTimer2 macro t2ex_enable
	mov 0xC8,#( 4 + ( t2ex_enable & 1 ) * 9 ) ;t2con set tr2 and others 2 bits for capture
	orl 0xA8,#80H					;enable global interrupt
Endm

EnableTimer2Counter macro t2ex_enable
	mov 0xC8,# ( ( t2ex_enable & 1 ) * 9 );
	orl 0xA8,#80
Endm

; -------- ADC MACROS ---------------------------------------
; -----------------------------------------------------------

OnAdcInterrupt macro _addr
	org 0x43
	ajmp _addr
Endm

ConfigureAdcPins macro _is_an0,_is_an1,_is_an2,_is_an3,_is_an4,_is_an5,_is_an6,_is_an7
	mov  0xF6,#(_is_an7 * 128 + _is_an6 * 64 + _is_an5 * 32 + _is_an4 * 16 + _is_an3 * 8 + _is_an2 * 4 + _is_an1 * 2 + _is_an0 );
Endm

StartAdcConversion macro _input_channel
	orl  0xE8,#2					  ;set eadc or enable adc interrupt enable bit
	orl  0xA8,#80H					  ;set ea
	anl  0xF3,#E0H
	orl  0xF3,# (( _input_channel & 7 ) + 0x20 ); set aden
	orl  0xF3,#8					  ;set adsst
Endm

StartAdcConversionAndWait macro _input_channel
	anl 0xE8,#FD					;clear eadc or adc interrupt enable bit
	anl 0xF3,#E0H
	orl 0xF3,# ((_input_channel & 7 ) + 0x20 );set aden
	orl 0xF3,#8						;set adsst

	mov A,0xF3
	anl A,#10H
	jz  $-4						;loop until adeoc is set

	anl 0xF3,#EFH					;clear adeoc
Endm

ReadAdc macro _addr_high,_addr_low
	mov _addr_high,0xF5				;addh
	mov _addr_low ,0xF4				;addl
Endm

; -------- SPI MACROS ---------------------------------------
; -----------------------------------------------------------

OnSpiInterrupt macro _addr
	org 0x53
	ajmp _addr
Endm

LIST