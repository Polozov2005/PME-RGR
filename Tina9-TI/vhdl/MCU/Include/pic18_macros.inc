nolist

#define TRUE	1
#define FALSE	0

START_INTERRUPT_BLOCK macro
	org 6
	bra pic18_interrupt_block_end

	#ifdef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt block already declared and there can be only one interrupt block"
	#endif

	#define PIC18_INTERRUPT_BLOCK_STARTED
Endm

END_INTERRUPT_BLOCK macro
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "END_INTERRUPT_BLOCK macro is invalid without starting START_INTERRUPT_BLOCK"
	#endif
	#undef PIC18_INTERRUPT_BLOCK_STARTED
	retfie
	pic18_interrupt_block_end:
Endm

Wait macro _cycles
	movlw _cycles
	movwf 0x20,1
	decfsz 0x20,1
	goto $-1

	#ifndef WAIT_WARNING_MESSAGE_SHOWN
	#define WAIT_WARNING_MESSAGE_SHOWN
	#messg "Wait macro uses memory at 0x20. So, don't use this address for storing data."
	#endif
Endm

CallIfBitSet macro _port,_bit,_label
	btfsc _port,_bit
	call _label	
Endm

JumpIfBitSet macro _port,_bit,_label
	btfsc _port,_bit
	bra   _label	
Endm

SkipIfBitSet macro _port,_bit,_skip_count
	JumpIfBitSet(_port,_bit,$_skip_count+1)
Endm

CallIfBitClear macro _port,_bit,_label
	btfss _port,_bit
	call _label	
Endm
JumpIfBitClear macro _port,_bit,_label
	btfss _port,_bit
	bra   _label	
Endm
SkipIfBitClear macro _port,_bit,_skip_count
	JumpIfBitClear(_port,_bit,$_skip_count+1)
Endm

CallIfEqual macro _port,_dt,_addr
	MOVLW _dt
	SUBWF _port,W
	BTFSC STATUS,2			;Z
	CALL  _addr
Endm

CallIfNotEqual macro _port,_dt,_addr
	MOVLW _dt
	SUBWF _port,W
	BTFSS STATUS,2			;Z
	CALL  _addr
Endm

JumpIfEqual macro _port,_dt,_addr
	MOVLW _dt
	SUBWF _port,W
	BTFSC STATUS,2 			;Z
	GOTO  _addr
Endm

JumpIfNotEqual macro _port,_dt,_addr
	MOVLW _dt
	SUBWF _port,W
	BTFSS STATUS,2 			;Z
	GOTO  _addr
Endm

SkipIfEqual macro _port,_dt,_skip_count
	JumpIfEqual _port,_dt,$+_skip_count+1
Endm

SkipIfNotEqual macro _port,_dt,_skip_count
	JumpIfNotEqual _port,_dt,$+_skip_count+1
Endm

InvertPin macro _port,_bit
	btg _port,_bit
Endm

WritePort macro _port,_dt
	movlw _dt
	movwf _port
Endm

ConfigurePortForInput macro _port
	movlw 0xFF
	movwf _port + 18
Endm

ConfigurePortForOutput macro _port
	movlw 0
	movwf _port + 18
Endm

ConfigurePinForInput macro _port,_pin
	bsf _port + 18,_pin
Endm

ConfigurePinForOutput macro _port,_pin
	bcf _port  + 18,_pin
Endm

SetPin macro _port,_pin
	bsf _port,_pin
Endm

ClearPin macro _port,_pin
	bcf _port,_pin
Endm

#define ra0 porta,0
#define ra1 porta,1
#define ra2 porta,2
#define ra3 porta,3
#define ra4 porta,4
#define ra5 porta,5
#define ra6 porta,6
#define ra7 porta,7

#define rb0 portb,0
#define rb1 portb,1
#define rb2 portb,2
#define rb3 portb,3
#define rb4 portb,4
#define rb5 portb,5
#define rb6 portb,6
#define rb7 portb,7

#define rc0 portc,0
#define rc1 portc,1
#define rc2 portc,2
#define rc3 portc,3
#define rc4 portc,4
#define rc5 portc,5
#define rc6 portc,6
#define rc7 portc,7

#define rd0 portd,0
#define rd1 portd,1
#define rd2 portd,2
#define rd3 portd,3
#define rd4 portd,4
#define rd5 portd,5
#define rd6 portd,6
#define rd7 portd,7

#define re0 porte,0
#define re1 porte,1
#define re2 porte,2
#define re3 porte,3
#define re4 porte,4
#define re5 porte,5
#define re6 porte,6
#define re7 porte,7

#define rf0 portf,0
#define rf1 portf,1
#define rf2 portf,2
#define rf3 portf,3
#define rf4 portf,4
#define rf5 portf,5
#define rf6 portf,6
#define rf7 portf,7

; -------- EXTERNAL INTERRUPT MACROS ------------------------
; -----------------------------------------------------------

OnExternalInterrupt0 macro _address
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(INTCON,1,_address);	INT0IF
	BCF INTCON,1
Endm

OnExternalInterruptX macro _n,_address
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(INTCON3,_n-1,_address);	INT1IF
	BCF INTCON3,_n-1
Endm

OnExternalInterrupt macro _address
	OnExternalInterrupt0 _address
Endm

OnExternalInterrupt1 macro _address
	OnExternalInterruptX 1,_address
Endm

OnExternalInterrupt2 macro _address
	OnExternalInterruptX 2,_address
Endm

OnExternalInterrupt3 macro _address
	OnExternalInterruptX 3,_address
Endm

OnRBInterrupt macro _address
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(INTCON,0,_address);	INTCON RBIF
	BCF INTCON,0
Endm

EnableExternalInterrupt0 macro
	ConfigurePinForInput int0_pin
	BCF	INTCON,1			; INT0IF <= 0
	BSF	INTCON,4			; INT0IE <= 1
	BSF	INTCON,6			; PEIE
	BSF	INTCON,7			; GIE
Endm

EnableExternalInterrupt0OnRisingEdge macro
	BSF	INTCON2,6			; RISING EDGE
	EnableExternalInterrupt0
Endm

EnableExternalInterrupt0OnFallingEdge macro
	BCF	INTCON2,6			; RISING EDGE
	EnableExternalInterrupt0
Endm

EnableExternalInterruptX macro _n				; Enable interrupt 1, 2 and 3
	BCF	INTCON3, _n	- 1		; INTxF <= 0
	BSF	INTCON3,2 + _n		; INTxIE <= 1
	BSF	INTCON,6			; PEIE
	BSF	INTCON,7			; GIE	
Endm

EnableExternalInterrupt1OnRisingEdge macro
	ConfigurePinForInput int1_pin
	BSF	INTCON2,5
	EnableExternalInterruptX(1)
Endm

EnableExternalInterrupt1OnFallingEdge macro
	ConfigurePinForInput int1_pin
	BCF	INTCON2,5
	EnableExternalInterruptX(1)
Endm

EnableExternalInterrupt1 macro
	EnableExternalInterrupt1OnRisingEdge
Endm

EnableExternalInterrupt2OnRisingEdge macro
	ConfigurePinForInput int2_pin
	BSF	INTCON2,4
	EnableExternalInterruptX(2)
Endm

EnableExternalInterrupt2OnFallingEdge macro
	ConfigurePinForInput int2_pin
	BCF	INTCON2,4
	EnableExternalInterruptX(2)
Endm

EnableExternalInterrupt2 macro
	EnableExternalInterrupt2OnRisingEdge
Endm

EnableExternalInterrupt3OnRisingEdge macro
	ConfigurePinForInput int3_pin
	BSF	INTCON2,3
	EnableExternalInterruptX(3)
Endm

EnableExternalInterrupt3OnFallingEdge macro
	ConfigurePinForInput int3_pin
	BCF	INTCON2,3
	EnableExternalInterruptX(3)
Endm

EnableExternalInterrupt3 macro
	EnableExternalInterrupt3OnRisingEdge
Endm

EnableRBInterrupt macro
	BCF	INTCON,0
	BSF	INTCON,3
	BSF	INTCON,6
	BSF	INTCON,7
Endm

;---------------------------------------------------------
;---------------------------------------------------------

OnComparator1InterruptEx macro _address
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(PIR2,5,_address);	CM1IF
	BCF PIR2,5
Endm

OnComparator2InterruptEx macro _address
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(PIR2,6,_address);	CM2IF
	BCF PIR2,6
Endm

DisableComparatorVrefModule macro
	BCF	CVRCON, 7				;CVREN <= 0
Endm

EnableComparatorVrefModule macro high_range, use_vref, selected_range

	#ifdef vref_plus_pin
		ConfigurePinForInput vref_plus_pin
		ConfigurePinForInput vref_minus_pin
	#endif

	MOVLW	( 1 << 7 ) | ( high_range << 5 ) | ( use_vref << 4 ) | ( selected_range & 15 );
	MOVWF	CVRCON
Endm

EnableComparator1Ex macro positive_cvref, negative_selection, enable_output, output_invert, interrupt_type

	ConfigurePinForInput c1ina_pin;
	ConfigurePinForInput c1inb_pin;

	#ifdef c1out_pin
		ConfigurePinForOutput c1out_pin;
	#endif

	MOVLW	( 1 << 7 ) | ( enable_output << 6 ) | ( output_invert << 5 ) | ( ( interrupt_type & 3 ) << 3 ) | ( positive_cvref << 2 ) | ( negative_selection & 3 );
	MOVWF	CM1CON

	BCF	PIR2,5
	BSF	PIE2,5
	BSF	INTCON,6
	BSF	INTCON,7
Endm

DisableComparator1Ex macro
	BCF	CM1CON, 7
Endm

EnableComparator2Ex macro positive_cvref, negative_selection, enable_output, output_invert, interrupt_type

	ConfigurePinForInput c2ina_pin;
	ConfigurePinForInput c2inb_pin;

	MOVLW	( 1 << 7 ) | ( enable_output << 6 ) | ( output_invert << 5 ) | ( ( interrupt_type & 3 ) << 3 ) | ( positive_cvref << 2 ) | ( negative_selection & 3 );
	MOVWF	CM2CON

	BCF	PIR2,6
	BSF	PIE2,6
	BSF	INTCON,6
	BSF	INTCON,7
Endm

DisableComparator2Ex macro
	BCF	CM2CON, 7
Endm

;---------------------------------------------------------
;---------------------------------------------------------

OnAdcInterrupt macro _address
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(PIR1,6,_address);	ADIF
	BCF PIR1,6
Endm

StartAdcConversion macro input_channel,adc_clock, right_justified

	#ifequ ADCON2
		MOVLW	( ( input_channel & 15 ) << 2 ) | 1;
		MOVWF	ADCON0
		MOVLW 0xFF
		MOVWF ADCON1
		MOVLW ( right_justified << 7 ) | ( adc_clock & 7 );
		MOVWF ADCON2
	#endif

	#ifnequ ADCON2
		MOVLW	( ( input_channel & 15 ) << 2 ) | ( 1 << 7 ) | ( 1 << 6 ) | 1;
		MOVWF	ADCON0
		MOVLW ( right_justified << 7 ) | ( adc_clock & 7 );
		MOVWF ADCON1
	#endif
	
	BCF	PIR1,6
	BSF	PIE1,6
	BSF	INTCON,6
	BSF	INTCON,7

	BSF	ADCON0, 1
Endm

StartAdcConversionWithoutVref macro input_channel,adc_clock, right_justified

	#ifequ ADCON2
		MOVLW	( ( input_channel & 15 ) << 2 ) | 1;
		MOVWF	ADCON0
		MOVLW 0xCF
		MOVWF ADCON1
		MOVLW ( right_justified << 7 ) | ( adc_clock & 7 );
		MOVWF ADCON2
	#endif

	#ifnequ ADCON2
		MOVLW	( ( input_channel & 15 ) << 2 ) | 1;
		MOVWF	ADCON0
		MOVLW ( right_justified << 7 ) | ( adc_clock & 7 );
		MOVWF ADCON1
	#endif
	
	BCF	PIR1,6
	BSF	PIE1,6
	BSF	INTCON,6
	BSF	INTCON,7

	BSF	ADCON0, 1
Endm

;---------------------------------------------------------
;---------------------------------------------------------

OnTimer0Interrupt macro _address
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(INTCON,2,_address);	TMR0IF
	BCF INTCON,2
Endm

EnableTimer0 macro _is_8bit, _has_prescaler, _prescaler_value
	MOVLW	( _is_8bit << 6 ) | ( _has_prescaler << 3 ) | ( _prescaler_value & 7 ) | 0x80;
	MOVWF	T0CON

	BCF	INTCON,2			; TMR0IF
	BSF	INTCON,5			; TMR0IE
	BSF	INTCON,6			; PEIE
	BSF	INTCON,7			; GIE
Endm

EnableTimer0Counter macro _is_8bit, _has_prescaler, _prescaler_value, _falling_edge
	ConfigurePinForInput	T0CKI_PIN

	MOVLW	( _is_8bit << 6 ) | ( _has_prescaler << 3 ) | ( _prescaler_value & 7 ) | ( _falling_edge << 4 ) | 0xA0;
	MOVWF	T0CON

	BCF	INTCON,2			; TMR0IF
	BSF	INTCON,5			; TMR0IE
	BSF	INTCON,6			; PEIE
	BSF	INTCON,7			; GIE
Endm

DisableTimer0 macro
	BCF	T0CON, 7
Endm

OnTimer1Interrupt macro _address
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(PIR1,0,_address);		TMR1IF
	BCF PIR1,0
Endm

EnableTimer1 macro _is_8bit, _prescaler
	MOVLW	( _is_8bit << 7 ) |  ( ( _prescaler & 3 ) << 4 ) | 5;
	MOVWF	T1CON

	BCF	PIR1,0				; TMR1IF
	BSF	PIE1,0				; TMR1IE
	BSF	INTCON,6			; PEIE
	BSF	INTCON,7			; GIE
Endm

EnableTimer1Counter macro _is_8bit, _prescaler
	ConfigurePinForInput	t13cki_pin

	MOVLW	( _is_8bit << 7 ) |  ( ( _prescaler & 3 ) << 4 ) | 7;
	MOVWF	T1CON

	BCF	PIR1,0				; TMR1IF
	BSF	PIE1,0				; TMR1IE
	BSF	INTCON,6			; PEIE
	BSF	INTCON,7			; GIE
Endm

DisableTimer1 macro
	BCF	T1CON, 0
Endm

OnTimer2Interrupt macro _address
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(PIR1,1,_address);		TMR2IF
	BCF PIR1,1
Endm

EnableTimer2 macro _upper_limit, _prescaler, _postscaler
	MOVLW	_upper_limit
	MOVWF	PR2
	MOVLW	( _postscaler & 15 ) << 3 | ( _prescaler & 3 ) | 4;
	MOVWF	T2CON

	BCF	PIR1,1				; TMR2IF
	BSF	PIE1,1				; TMR2IE
	BSF	INTCON,6			; PEIE
	BSF	INTCON,7			; GIE
Endm

DisableTimer2 macro
	BCF	T2CON, 2
Endm

OnTimer3Interrupt macro _address
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(PIR2,1,_address);			TMR3IF
	BCF PIR2,1
Endm

EnableTimer3 macro _is_8bit, _prescaler
	MOVLW	( _is_8bit << 7 ) | ( ( _prescaler & 3 ) << 4 ) | 5;
	MOVWF	T3CON

	BCF	PIR2,1				; TMR3IF
	BSF	PIE2,1				; TMR3IE
	BSF	INTCON,6			; PEIE
	BSF	INTCON,7			; GIE
Endm

EnableTimer3Counter macro _is_8bit, _prescaler
	ConfigurePinForInput	t13cki_pin

	MOVLW	( _is_8bit << 7 ) | ( ( _prescaler & 3 ) << 4 ) | 7;
	MOVWF	T3CON

	BCF	PIR2,1				; TMR3IF
	BSF	PIE2,1				; TMR3IE
	BSF	INTCON,6			; PEIE
	BSF	INTCON,7			; GIE
Endm

DisableTimer3 macro
	BCF	T3CON,0
Endm

OnTimer4Interrupt macro _address
	#ifndef PIC18_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(PIR3,3,_address);		TMR4IF
	BCF PIR3,3
Endm

EnableTimer4 macro _upper_limit, _prescaler, _postscaler
	MOVLW	_upper_limit
	MOVWF	PR4
	MOVLW	( _postscaler & 15 ) << 3 | ( _prescaler & 3 ) | 4;
	MOVWF	T4CON

	BCF	PIR3,3				; TMR4IF
	BSF	PIE3,3				; TMR4IE
	BSF	INTCON,6			; PEIE
	BSF	INTCON,7			; GIE
Endm

DisableTimer4 macro
	BCF	T4CON, 2
Endm
;---------------------------------------------------------
;---------------------------------------------------------
LIST