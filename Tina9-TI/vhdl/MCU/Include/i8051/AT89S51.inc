    B          EQU     0F0H
    ACC        EQU     0E0H
    PSW        EQU     0D0H
    IP         EQU     0B8H
    P3         EQU     0B0H
    IE         EQU     0A8H
    P2         EQU     0A0H
    AUXR1      EQU     0A2H
    WDTRST     EQU     0A6H
    SCON       EQU     098H
    SBUF       EQU     099H
    P1         EQU     090H
    TCON       EQU     088H
    TMOD       EQU     089H
    TL0        EQU     08AH
    TL1        EQU     08BH
    TH0        EQU     08CH
    TH1        EQU     08DH
    AUXR       EQU     08EH
    P0         EQU     080H
    SP         EQU     081H
    DP0L       EQU     082H
    DP0H       EQU     083H
    DP1L       EQU     084H
    DP1H       EQU     085H
    PCON       EQU     087H

;---------- BIT POSITIONS --------------------------
	; --- 8051 register bit fields ---		
	; IE		
	EA         	EQU     	0xAF
	ES         	EQU     	0xAC
	ET1        	EQU     	0xAB
	EX1        	EQU     	0xAA
	ET0        	EQU     	0xA9
	EX0        	EQU     	0xA8
	; IP 		
	PS         	EQU     	0xBC
	PT1        	EQU     	0xBB
	PX1        	EQU     	0xBA
	PT0        	EQU     	0xB9
	PX0        	EQU     	0xB8
	; P3		
	RD         	EQU     	0xB7
	WR         	EQU     	0xB6
	T1         	EQU     	0xB5
	T0         	EQU     	0xB4
	INT1       	EQU     	0xB3
	INT0       	EQU     	0xB2
	TXD        	EQU     	0xB1
	RXD        	EQU     	0xB0
	; PSW		
	CY         	EQU     	0xD7
	AC         	EQU     	0xD6
	F0         	EQU     	0xD5
	RS1        	EQU     	0xD4
	RS0        	EQU     	0xD3
	OV         	EQU     	0xD2
	P          	EQU     	0xD0
	; TCON		
	TF1        	EQU     	0x8F
	TR1        	EQU     	0x8E
	TF0        	EQU     	0x8D
	TR0        	EQU     	0x8C
	IE1        	EQU     	0x8B
	IT1        	EQU     	0x8A
	IE0        	EQU     	0x89
	IT0        	EQU     	0x88
	; SCON		
	SM0        	EQU     	0x9F
	SM1        	EQU     	0x9E
	SM2        	EQU     	0x9D
	REN        	EQU     	0x9C
	TB8        	EQU     	0x9B
	RB8        	EQU     	0x9A
	TI         	EQU     	0x99
	RI         	EQU     	0x98
