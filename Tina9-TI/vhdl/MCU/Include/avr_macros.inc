EmptyLoop macro
empty_loop_4121:
	rjmp empty_loop_4121
Endm

Wait macro _cycles
#ifndef WAIT_4121_DECLARED
#define WAIT_4121_DECLARED
	rjmp $+4
setup_loop_4121_1:
	dec	r16
	brne	setup_loop_4121_1
	ret
#endif	
	ldi	r16,_cycles
	rcall setup_loop_4121_1
Endm


ConfigurePortForOutput macro _ddr
	ldi r16, 0xFF
 	out _ddr, r16
Endm


OnSpiInterrupt macro _addr
	org 0x0A
 	rjmp _addr
Endm

ReadSpiData macro _reg
	in r16, SPDR
	out _reg, r16
Endm

EnableSpiTransmitterWithModeAndCkp macro _mode,_ckp
	ldi r16,(0x08+0x20)		
	out DDRB,r16
	ldi r16,(0x40+0x10+_mode)
	out SPCR,r16
Endm


EnableSpiTransmitter macro
	EnableSpiTransmitterWithModeAndCkp(1,1);		FOSC/16
Endm


EnableSpiWaitLoop macro
#ifndef SPI_TRANSMIT_WAIT_4121_DECLARED
#define SPI_TRANSMIT_WAIT_4121_DECLARED
	rjmp $+4
spi_transmit_wait_4121:
	sbis SPSR,SPIF
	rjmp spi_transmit_wait_4121
	ret
#endif
Endm


SendWithSpi macro _dt
	EnableSpiWaitLoop
	ldi r16,_dt
	out SPDR,r16
	rcall spi_transmit_wait_4121	
Endm


EnableSpiReceiver macro
	ldi r16,0x10		
	out DDRB,r16
	ldi r16,0xC0	
	out SPCR,r16	;SPI interrupt enabled
	sei		;global interrupt enabled
Endm

