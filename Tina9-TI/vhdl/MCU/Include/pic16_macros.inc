nolist

#define TRUE	1
#define FALSE	0

START_INTERRUPT_BLOCK macro
	org 0x03
	goto pic_interrupt_block_end

	#ifdef PIC_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt block already declared and there can be only one interrupt block"
	#endif

	#define PIC_INTERRUPT_BLOCK_STARTED
Endm

END_INTERRUPT_BLOCK macro
	#ifndef PIC_INTERRUPT_BLOCK_STARTED
	#Error "END_INTERRUPT_BLOCK macro is invalid without starting START_INTERRUPT_BLOCK"
	#endif
	#undef PIC_INTERRUPT_BLOCK_STARTED
	retfie
	pic_interrupt_block_end:
Endm

Wait macro _cycles
	movlw _cycles
	movwf 0x20
	decfsz 0x20
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
	goto _label	
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
	goto _label	
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
	btfss _port,_bit
	goto $+3
	bcf _port,_bit
	goto $+2
	bsf _port,_bit
Endm

WriteMemoryBank0 macro _port,_dt
	movlw _dt
	movwf _port
Endm

WriteMemoryBank1 macro _port,_dt
	bsf status,rp0
	movlw _dt
	movwf _port
	bcf status,rp0
Endm

WritePort macro _port,_dt
	WriteMemoryBank0(_port,_dt);
Endm

ConfigurePortForInput macro _port
	bsf status,rp0
	movlw 0xFF
	movwf _port
	bcf status,rp0
Endm

ConfigurePortForOutput macro _port
	bsf status,rp0
	movlw 0
	movwf _port
	bcf status,rp0
Endm

ConfigurePinForInput macro _port,_pin
	bsf status,rp0
	bsf _port,_pin
	bcf status,rp0
Endm

ConfigurePinForOutput macro _port,_pin
	bsf status,rp0
	bcf _port,_pin
	bcf status,rp0
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

; -------- EXTERNAL INTERRUPT MACROS ------------------------
; -----------------------------------------------------------

OnExternalInterrupt macro _address
	#ifndef PIC_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(INTCON,1,_address);	INTCON INTF
	BCF INTCON,1
Endm

OnRBInterrupt macro _address
	#ifndef PIC_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(INTCON,0,_address);	INTCON RBIF
	BCF INTCON,0
Endm

#ifequ portb
	#define external_interrupt_pin rb0
	#define external_interrupt_at_rb0
#endif
#ifnequ portb
	#define external_interrupt_pin ra2
	#define external_interrupt_at_ra2
#endif

ShowExternalInterruptMessage macro
	#ifndef EXTERNAL_INTERRUPT_PIN_MSG_SHOWN
		  #define EXTERNAL_INTERRUPT_PIN_MSG_SHOWN
		  #ifdef external_interrupt_at_rb0
			#messg "External interrupt occurs at RB0"
		  #endif
		  #ifdef external_interrupt_at_ra2
			#messg "External interrupt occurs at RA2"
		  #endif
	#endif
Endm
EnableExternalInterruptOnRisingEdge macro
	ShowExternalInterruptMessage();
	BSF STATUS,RP0
	BSF 0x81,6				;INTEDG
	BCF STATUS,RP0
	ConfigurePinForInput external_interrupt_pin
	BSF INTCON,4 ;inte
	BCF INTCON,1 ;intf	
	BSF INTCON,6 ;PEIE
	BSF INTCON,7 ;GIE
Endm

EnableExternalInterruptOnFallingEdge macro
	ShowExternalInterruptMessage();
	BSF STATUS,RP0
	BCF 0x81,6				;INTEDG
	BCF STATUS,RP0
	ConfigurePinForInput external_interrupt_pin
	BCF INTCON,1 ;INTF
	BSF INTCON,4 ;INTE
	BSF INTCON,6 ;PEIE
	BSF INTCON,7 ;GIE
Endm

EnableExternalInterrupt macro
	EnableExternalInterruptOnRisingEdge
Endm

EnableRBInterrupt macro
	BSF STATUS,RP0
	BSF TRISB,4
	BSF TRISB,5
	BSF TRISB,6
	BSF TRISB,7
	BCF STATUS,RP0
	BCF INTCON,0 ;RBIF
	BSF INTCON,3 ;RBIE
	BSF INTCON,6 ;PEIE
	BSF INTCON,7 ;GIE
Endm

; -------- TIMER0 MACROS ------------------------------------
; -----------------------------------------------------------

#define T0CKI_PIN ra4
OnTimer0Interrupt macro _address
	#ifndef PIC_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(INTCON,2,_address);	INTCON,TMR0IF
	BCF INTCON,2
Endm

EnableTimer0Interrupt macro
	BCF INTCON,2	;T0IF
	BSF INTCON,5	;T0IE
	BSF INTCON,6	;PEIE
	BSF INTCON,7	;GIE
Endm

EnableTimer0CounterOnRisingEdge macro
	#messg "Timer0 counter enabled on RA4"
	BSF STATUS,RP0
	BSF 0x81,5			;OPTION_REG<T0CS>
	BCF 0x81,4			;OPTION_REG<TOSE>
	BCF STATUS,RP0
Endm

EnableTimer0CounterOnFallingEdge macro
	#messg "Timer0 counter enabled on RA4"
	BSF STATUS,RP0
	BSF 0x81,5			;OPTION_REG<T0CS>
	BSF 0x81,4			;OPTION_REG<TOSE>
	BCF STATUS,RP0
Endm

EnableTimer0Counter macro
	EnableTimer0CounterOnRisingEdge
Endm

EnableTimer0 macro
	BSF STATUS,RP0
	BCF 0x81,5		;clear OPTION_REG,T0CS
	BSF 0x81,3		;PSA = 1 means, prescalar is assigned to WDT
	BCF STATUS,RP0
	EnableTimer0Interrupt()
Endm

EnableTimer0WithPrescalar macro _prescalar_val	
	BSF STATUS,RP0
	MOVF 0x81,W
	ANDLW 0xC0		;clear T0CS,T0SE,PSA,PS2,PS1,PS0
	IORLW ( _prescalar_val & 0x07 );
	MOVWF 0x81
	BCF STATUS,RP0
	EnableTimer0Interrupt()
	#messg "Timer0 is setup to interrupt in each " 256 * _prescalar_val * 2 "Cycles. So, your interrupt handler routine must be executed within this period"
Endm

; -------- SPI MACROS ---------------------------------------
; -----------------------------------------------------------

#define SCK_PIN rc3
#define SDI_PIN rc4
#define SDO_PIN rc5

OnSpiInterrupt macro _address
	#ifndef PIC_INTERRUPT_BLOCK_STARTED
	#Error "Interrupt functions are valid only between START_INTERRUPT_BLOCK and END_INTERRUPT_BLOCK"
	#endif

	CallIfBitSet(PIR1,3,_address);	PIR1,SSPIF
Endm

EnableSpiReceiverWithModeAndCkp macro _mode,_ckp,_dt
	#ifndef SPI_PIN_SHOWN_4121
		#define SPI_PIN_SHOWN 4121
		#messg "SCK = RC3, SDI = RC4, SDO = RC5"
	#endif

	BSF STATUS,RP0
	BSF sdi_pin
	BCF sdo_pin
	BSF sck_pin
	BSF PIE1,SSPIE
	BCF STATUS,RP0

	BCF PIR1,SSPIF
	BSF INTCON,7				; GIE
	BSF INTCON,6				; PIE

	MOVLW	( 0x20 + 0x10 * _ckp + _mode ); 
	MOVWF	SSPCON

	MOVLW	_dt;
	MOVWF	SSPBUF;
Endm

EnableSpiReceiver macro _dt
	EnableSpiReceiverWithModeAndCkp(5,1,_dt)
Endm

ReadSpiData macro _dest
	MOVF SSPBUF,W
	MOVWF _dest
Endm

WriteSpiData macro _dt
	MOVLW _dt
	MOVWF SSPBUF
Endm

WriteSpiDataFromMemory macro _addr
	MOVF _addr,W
	MOVWF SSPBUF
Endm

EnableSpiTransmitterWithModeAndCkp macro _mode,_ckp

	#ifndef SPI_PIN_SHOWN_4121
		#define SPI_PIN_SHOWN 4121
		#messg "SCK = RC3, SDI = RC4, SDO = RC5"
	#endif

	BSF	STATUS,RP0
	BSF	sdi_pin
	BCF	sdo_pin
	BCF	sck_pin
	BCF	PIE1,SSPIE						;Disable SSP Interrupt
	BCF	STATUS,RP0

	MOVLW	( 0x20 + 0x10 * _ckp + _mode ); 
	MOVWF	SSPCON
Endm

EnableSpiTransmitter macro
	EnableSpiTransmitterWithModeAndCkp(1,1);		FOSC/16
Endm

EnableSpiTransmitterFast macro
	EnableSpiTransmitterWithModeAndCkp(0,1);		FOSC/4
Endm

EnableSpiTransmitterSlow macro
	EnableSpiTransmitterWithModeAndCkp(2,1);		FOSC/64
Endm

EnableSpiWaitLoop macro
	#ifndef SPI_TRANSMIT_WAIT_4121_DECLARED
		#define SPI_TRANSMIT_WAIT_4121_DECLARED
		GOTO $+6
		spi_transmit_wait_4121:
			BCF	PIR1,3
			MOVWF	SSPBUF
			BTFSS	PIR1,3;		SSPIF
			GOTO	$-1
			RETURN
	#endif
Endm

SendWithSpi macro _dt
	EnableSpiWaitLoop
	MOVLW _dt
	call spi_transmit_wait_4121	
Endm

Send2BytesWithSpi macro _dt
	SendWithSpi(_dt/256);
	SendWithSpi(_dt%256);
Endm

SendMemoryWithSpi macro _addr
	EnableSpiWaitLoop
	MOVF _addr,W
	call spi_transmit_wait_4121
Endm

; -------- MCP2515 MACROS -----------------------------------
; -----------------------------------------------------------

#define MCP2515_SS_PIN 			RC2
#define MCP2515_CANSTAT			0x0E
#define MCP2515_CANCTRL			0x0F

#define MCP2515_COMMAND_RESET     	0xC0
#define MCP2515_COMMAND_READ      	0x03
#define MCP2515_COMMAND_WRITE     	0x02
#define MCP2515_COMMAND_RTS       	0x80
#define MCP2515_COMMAND_RTS_TXB0  	0x81
#define MCP2515_COMMAND_RTS_TXB1  	0x82
#define MCP2515_COMMAND_RTS_TXB2  	0x83
#define MCP2515_COMMAND_RD_STATUS 	0xA0
#define MCP2515_COMMAND_BIT_MODIFY	0x05    

InitMcp2515Communication macro
	SetPin(MCP2515_SS_PIN);
	ConfigurePinForOutput(MCP2515_SS_PIN);
	EnableSpiTransmitter

	ClearPin(MCP2515_SS_PIN);
	SendWithSpi ( MCP2515_COMMAND_WRITE );
	SendWithSpi 0x2B		;INTE REG
	SendWithSpi 0x03		;All receive interrupts are enabled
	SendWithSpi 0		;Current interrupt is 0
	SetPin ( MCP2515_SS_PIN );
Endm

ConfigureMcp2515Transmitter macro _transmitter_no,_id,_priority
	ClearPin(MCP2515_SS_PIN);
	SendWithSpi ( MCP2515_COMMAND_WRITE );
	SendWithSpi ( 0x30 + _transmitter_no * 0x10 )		;start address
	SendWithSpi ( _priority & 0x03 );				;TXBCTRL
	SendWithSpi ( _id / 8 );					;SIDH = SID<10..3>
	SendWithSpi ( ( _id % 8 ) * 32 );				;SIDL = SID<2..0>,-,EXIDE,-,EID17,EID16
	SetPin(MCP2515_SS_PIN);
Endm

ConfigureMcp2515TransmitterEx macro _transmitter_no,_id,_priority
	ClearPin(MCP2515_SS_PIN);
	SendWithSpi ( MCP2515_COMMAND_WRITE );
	SendWithSpi ( 0x30 + _transmitter_no * 0x10 )		;start address
	SendWithSpi ( _priority & 0x03 )				;TXBCTRL
	SendWithSpi ( ( _id & 0x7F8 )/8 )				;SIDH
	SendWithSpi ( ( _id & 0x07 ) * 32 + 8 + ( _id & 0x1FFFF800 )/65536 )	;SIDL = SID<2,1,0>,-,EID,-,EID17,EID16
	SendWithSpi ( ( _id / 2048 ) / 256 )			;EIDH
	SendWithSpi ( ( _id / 2048 ) % 256 )			;EIDL
	SetPin(MCP2515_SS_PIN);
Endm

SendDataWithMcp2515Transmitter macro _transmitter_no,_dt
	ClearPin ( MCP2515_SS_PIN );
	SendWithSpi ( MCP2515_COMMAND_WRITE );
	SendWithSpi ( 0x30 + _transmitter_no * 0x10 + 5 );	//START WITH DLC
	SendWithSpi ( 1 );						//1 byte data
	SendWithSpi ( _dt );
	SetPin ( MCP2515_SS_PIN );
	ClearPin ( MCP2515_SS_PIN );
	SendWithSpi ( MCP2515_COMMAND_RTS_TXB0 + _transmitter_no );
	SetPin ( MCP2515_SS_PIN );
Endm

SendMemory1WithMcp2515Transmitter macro _transmitter_no,_addr
	ClearPin ( MCP2515_SS_PIN );
	SendWithSpi ( MCP2515_COMMAND_WRITE );
	SendWithSpi ( 0x30 + _transmitter_no * 0x10 + 5 );	//START WITH DLC
	SendWithSpi ( 1 );						//1 byte data
	SendMemoryWithSpi ( _addr );
	SetPin ( MCP2515_SS_PIN );
	ClearPin ( MCP2515_SS_PIN );
	SendWithSpi ( MCP2515_COMMAND_RTS_TXB0 + _transmitter_no );
	SetPin ( MCP2515_SS_PIN );
Endm

SendMemoryWithMcp2515Transmitter macro _transmitter_no,_addr,_cnt
	#ifndef MCP2515_MEMORY_MESSAGE_SHOWN
		#define MCP2515_MEMORY_MESSAGE_SHOWN
		#messg "MCP2515 uses memory at address 0x20 for transmitting block of data. So, don't use this location for storing data"
	#endif

	ClearPin ( MCP2515_SS_PIN );
	SendWithSpi ( MCP2515_COMMAND_WRITE );
	SendWithSpi ( 0x30 + _transmitter_no * 0x10 + 5 )	;START WITH DLC
	SendWithSpi ( _cnt )						;1 byte data

	MOVLW	_addr
	MOVWF	FSR
	MOVLW	_cnt
	MOVWF 0x20

	Mcp2515_mem_transmit_loop_4121:
		SendMemoryWithSpi(0);						;INDIRECT ADDRESS AT FSR
		INCF	FSR,F
		DECF	0x20,F
		JumpIfBitClear STATUS,2,Mcp2515_mem_transmit_loop_4121
	
	SetPin ( MCP2515_SS_PIN );
	ClearPin ( MCP2515_SS_PIN );
	SendWithSpi ( MCP2515_COMMAND_RTS_TXB0 + _transmitter_no );
	SetPin ( MCP2515_SS_PIN );
Endm

SendMcp2515SID macro _addr,_id
	ClearPin(MCP2515_SS_PIN);
	SendWithSpi ( MCP2515_COMMAND_WRITE );
	SendWithSpi ( _addr )							;start address of FILTER0
	SendWithSpi ( _id / 8 );					;SIDH = SID<10..3>
	SendWithSpi ( ( _id % 8 ) * 32 );			;SIDL = SID<2..0>,-,EXIDE,-,EID17,EID16
	SetPin(MCP2515_SS_PIN);
Endm

SendMcp2515EID macro _addr,_id
	ClearPin(MCP2515_SS_PIN);
	SendWithSpi ( MCP2515_COMMAND_WRITE );
	SendWithSpi ( _addr )						;start address
	SendWithSpi ( ( _id & 0x7F8 )/8 )				;SIDH
	SendWithSpi ( ( _id & 0x07 ) * 32 + 8 + ( _id & 0x1FFFF800 )/65536 )	;SIDL = SID<2,1,0>,-,EID,-,EID17,EID16
	SendWithSpi ( ( _id / 2048 ) / 256 )			;EIDH
	SendWithSpi ( ( _id / 2048 ) % 256 )			;EIDL
	SetPin(MCP2515_SS_PIN);
Endm

ConfigureMcp2515Receiver0 macro _mask0,_filter0,_filter1 ;2 filters for RXB0, and 4 filters for RXB1
	SendMcp2515SID 0x00,_filter0
	SendMcp2515SID 0x04,_filter1
	SendMcp2515SID 0x20,_mask0
Endm

ConfigureMcp2515Receiver1 macro _mask1,_filter2,_filter3,_filter4,_filter5 ;2 filters for RXB0, and 4 filters for RXB1
	SendMcp2515SID 0x08,_filter2
	SendMcp2515SID 0x10,_filter3
	SendMcp2515SID 0x14,_filter4
	SendMcp2515SID 0x18,_filter5
	SendMcp2515SID 0x23,_mask1
Endm

ConfigureMcp2515Receiver0Ex macro _mask0,_filter0,_filter1 ;2 filters for RXB0, and 4 filters for RXB1
	SendMcp2515EID 0x00,_filter0
	SendMcp2515EID 0x04,_filter1
	SendMcp2515EID 0x20,_mask0
Endm

ConfigureMcp2515Receiver1Ex macro _mask1,_filter2,_filter3,_filter4,_filter5 ;2 filters for RXB0, and 4 filters for RXB1
	SendMcp2515EID 0x08,_filter2
	SendMcp2515EID 0x10,_filter3
	SendMcp2515EID 0x14,_filter4
	SendMcp2515EID 0x18,_filter5
	SendMcp2515EID 0x23,_mask1
Endm

ReadMcp2515RxbData macro _receiver_no,_dest_addr
	SetPin(MCP2515_SS_PIN);
	ClearPin(MCP2515_SS_PIN);
	SendWithSpi ( MCP2515_COMMAND_READ );
	SendWithSpi ( 0x66 + 0x10 * _receiver_no );	RXBD ADDRESS
	SendWithSpi ( 0 );					READ SLOT
	SetPin(MCP2515_SS_PIN);
	MOVF SSPBUF,W
	MOVWF _dest_addr	
Endm

GetMcp2515Status macro _dest_addr
	SetPin(MCP2515_SS_PIN);
	ClearPin(MCP2515_SS_PIN);
	SendWithSpi ( MCP2515_COMMAND_READ );
	SendWithSpi ( 0x2C );					INTF ADDRESS
	SendWithSpi ( 0 );					READ SLOT
	SetPin(MCP2515_SS_PIN);
	MOVF SSPBUF,W
	MOVWF _dest_addr
Endm

;---------------------------------------------------------
;---------------------------------------------------------
LIST