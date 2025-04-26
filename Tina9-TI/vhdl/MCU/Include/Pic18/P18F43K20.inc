LIST
NOLIST
    #DEFINE REF_41303    1
    #DEFINE DEVICE_PIC18F43K20    1

    TOSU               EQU     FFFH
    TOSH               EQU     FFEH
    TOSL               EQU     FFDH
    STKPTR             EQU     FFCH
    PCLATU             EQU     FFBH
    PCLATH             EQU     FFAH
    PCL                EQU     FF9H
    TBLPTRU            EQU     FF8H
    TBLPTRH            EQU     FF7H
    TBLPTRL            EQU     FF6H
    TABLAT             EQU     FF5H
    PRODH              EQU     FF4H
    PRODL              EQU     FF3H
    INTCON             EQU     FF2H
    INTCON2            EQU     FF1H
    INTCON3            EQU     FF0H
    INDF0              EQU     FEFH
    POSTINC0           EQU     FEEH
    POSTDEC0           EQU     FEDH
    PREINC0            EQU     FECH
    PLUSW0             EQU     FEBH
    FSR0H              EQU     FEAH
    FSR0L              EQU     FE9H
    WREG               EQU     FE8H
    INDF1              EQU     FE7H
    POSTINC1           EQU     FE6H
    POSTDEC1           EQU     FE5H
    PREINC1            EQU     FE4H
    PLUSW1             EQU     FE3H
    FSR1H              EQU     FE2H
    FSR1L              EQU     FE1H
    BSR                EQU     FE0H
    INDF2              EQU     FDFH
    POSTINC2           EQU     FDEH
    POSTDEC2           EQU     FDDH
    PREINC2            EQU     FDCH
    PLUSW2             EQU     FDBH
    FSR2H              EQU     FDAH
    FSR2L              EQU     FD9H
    STATUS             EQU     FD8H
    TMR0H              EQU     FD7H
    TMR0L              EQU     FD6H
    T0CON              EQU     FD5H
    OSCCON             EQU     FD3H
    HLVDCON            EQU     FD2H
    WDTCON             EQU     FD1H
    RCON               EQU     FD0H
    TMR1H              EQU     FCFH
    TMR1L              EQU     FCEH
    T1CON              EQU     FCDH
    TMR2               EQU     FCCH
    PR2                EQU     FCBH
    T2CON              EQU     FCAH
    SSPBUF             EQU     FC9H
    SSPADD             EQU     FC8H
    SSPSTAT            EQU     FC7H
    SSPCON1            EQU     FC6H
    SSPCON2            EQU     FC5H
    ADRESH             EQU     FC4H
    ADRESL             EQU     FC3H
    ADCON0             EQU     FC2H
    ADCON1             EQU     FC1H
    ADCON2             EQU     FC0H
    CCPR1H             EQU     FBFH
    CCPR1L             EQU     FBEH
    CCP1CON            EQU     FBDH
    CCPR2H             EQU     FBCH
    CCPR2L             EQU     FBBH
    CCP2CON            EQU     FBAH
    PSTRCON            EQU     FB9H
    BAUDCTL            EQU     FB8H
    PWM1CON            EQU     FB7H
    ECCP1AS            EQU     FB6H
    CVRCON             EQU     FB5H
    CVRCON2            EQU     FB4H
    TMR3H              EQU     FB3H
    TMR3L              EQU     FB2H
    T3CON              EQU     FB1H
    SPBRGH             EQU     FB0H
    SPBRG              EQU     FAFH
    RCREG              EQU     FAEH
    TXREG              EQU     FADH
    TXSTA              EQU     FACH
    RCSTA              EQU     FABH
    EEADRH             EQU     FAAH
    EEADR              EQU     FA9H
    EEDATA             EQU     FA8H
    EECON2             EQU     FA7H
    EECON1             EQU     FA6H
    IPR2               EQU     FA2H
    PIR2               EQU     FA1H
    PIE2               EQU     FA0H
    IPR1               EQU     F9FH
    PIR1               EQU     F9EH
    PIE1               EQU     F9DH
    OSCTUNE            EQU     F9BH
    TRISE              EQU     F96H
    TRISD              EQU     F95H
    TRISC              EQU     F94H
    TRISB              EQU     F93H
    TRISA              EQU     F92H
    LATE               EQU     F8DH
    LATD               EQU     F8CH
    LATC               EQU     F8BH
    LATB               EQU     F8AH
    LATA               EQU     F89H
    PORTE              EQU     F84H
    PORTD              EQU     F83H
    PORTC              EQU     F82H
    PORTB              EQU     F81H
    PORTA              EQU     F80H
    ANSELH             EQU     F7FH
    ANSEL              EQU     F7EH
    IOCB               EQU     F7DH
    WPUB               EQU     F7CH
    CM1CON0            EQU     F7BH
    CM2CON0            EQU     F7AH
    CM2CON1            EQU     F79H
    SLRCON             EQU     F78H
    SSPMSK             EQU     F77H

;---------- BIT POSITIONS --------------------------

;   STKPTR
    STKFUL             EQU     7
    STKUNF             EQU     6
    SP4                EQU     4
    SP3                EQU     3
    SP2                EQU     2
    SP1                EQU     1
    SP0                EQU     0

;   INTCON
    GIE                EQU     7
    PEIE               EQU     6
    TMR0IE             EQU     5
    INT0IE             EQU     4
    RBIE               EQU     3
    TMR0IF             EQU     2
    INT0IF             EQU     1
    RBIF               EQU     0

;   INTCON2
    RBPU               EQU     7
    INTEDG0            EQU     6
    INTEDG1            EQU     5
    INTEDG2            EQU     4
    TMR0IP             EQU     2
    RBIP               EQU     0

;   INTCON3
    INT2IP             EQU     7
    INT1IP             EQU     6
    INT2IE             EQU     4
    INT1IE             EQU     3
    INT2IF             EQU     1
    INT1IF             EQU     0

;   STATUS
    OV                 EQU     3
    DC                 EQU     1

;   T0CON
    TMR0ON             EQU     7
    T08BIT             EQU     6
    T0CS               EQU     5
    T0SE               EQU     4
    PSA                EQU     3
    T0PS2              EQU     2
    T0PS1              EQU     1
    T0PS0              EQU     0

;   OSCCON
    IDLEN              EQU     7
    IRCF2              EQU     6
    IRCF1              EQU     5
    IRCF0              EQU     4
    OSTS               EQU     3
    IOFS               EQU     2
    SCS1               EQU     1
    SCS0               EQU     0

;   HLVDCON
    VDIRMAG            EQU     7
    IRVST              EQU     5
    HLVDEN             EQU     4
    HLVDL3             EQU     3
    HLVDL2             EQU     2
    HLVDL1             EQU     1
    HLVDL0             EQU     0

;   WDTCON
    SWDTEN             EQU     0

;   RCON
    IPEN               EQU     7
    SBOREN             EQU     6
    RI                 EQU     4
    TO                 EQU     3
    PD                 EQU     2
    POR                EQU     1
    BOR                EQU     0

;   T1CON
    RD16               EQU     7
    T1RUN              EQU     6
    T1CKPS1            EQU     5
    T1CKPS0            EQU     4
    T1OSCEN            EQU     3
    T1SYNC             EQU     2
    TMR1CS             EQU     1
    TMR1ON             EQU     0

;   T2CON
    T2OUTPS3           EQU     6
    T2OUTPS2           EQU     5
    T2OUTPS1           EQU     4
    T2OUTPS0           EQU     3
    TMR2ON             EQU     2
    T2CKPS1            EQU     1
    T2CKPS0            EQU     0

;   SSPSTAT
    SMP                EQU     7
    CKE                EQU     6
    D_A                EQU     5
    R_W                EQU     2
    UA                 EQU     1
    BF                 EQU     0

;   SSPCON1
    WCOL               EQU     7
    SSPOV              EQU     6
    SSPEN              EQU     5
    CKP                EQU     4
    SSPM3              EQU     3
    SSPM2              EQU     2
    SSPM1              EQU     1
    SSPM0              EQU     0

;   SSPCON2
    GCEN               EQU     7
    ACKSTAT            EQU     6
    ACKDT              EQU     5
    ACKEN              EQU     4
    RCEN               EQU     3
    PEN                EQU     2
    RSEN               EQU     1
    SEN                EQU     0

;   ADCON0
    CHS3               EQU     5
    CHS2               EQU     4
    CHS1               EQU     3
    CHS0               EQU     2
    GO_DONE            EQU     1
    ADON               EQU     0

;   ADCON1
    VCFG1              EQU     5
    VCFG0              EQU     4

;   ADCON2
    ADFM               EQU     7
    ACQT2              EQU     5
    ACQT1              EQU     4
    ACQT0              EQU     3
    ADCS2              EQU     2
    ADCS1              EQU     1
    ADCS0              EQU     0

;   CCP1CON
    P1M1               EQU     7
    P1M0               EQU     6
    DC1B1              EQU     5
    DC1B0              EQU     4
    CCP1M3             EQU     3
    CCP1M2             EQU     2
    CCP1M1             EQU     1
    CCP1M0             EQU     0

;   CCP2CON
    DC2B1              EQU     5
    DC2B0              EQU     4
    CCP2M3             EQU     3
    CCP2M2             EQU     2
    CCP2M1             EQU     1
    CCP2M0             EQU     0

;   PSTRCON
    STRSYNC            EQU     4
    STRD               EQU     3
    STRC               EQU     2
    STRB               EQU     1
    STRA               EQU     0

;   BAUDCTL
    ABDOVF             EQU     7
    RCIDL              EQU     6
    DTRXP              EQU     5
    CKTXP              EQU     4
    BRG16              EQU     3
    WUE                EQU     1
    ABDEN              EQU     0

;   PWM1CON
    PRSEN              EQU     7
    PDC6               EQU     6
    PDC5               EQU     5
    PDC4               EQU     4
    PDC3               EQU     3
    PDC2               EQU     2
    PDC1               EQU     1
    PDC0               EQU     0

;   ECCP1AS
    ECCPASE            EQU     7
    ECCPAS2            EQU     6
    ECCPAS1            EQU     5
    ECCPAS0            EQU     4
    PSSAC1             EQU     3
    PSSAC0             EQU     2
    PSSBD1             EQU     1
    PSSBD0             EQU     0

;   CVRCON
    CVREN              EQU     7
    CVROE              EQU     6
    CVRR               EQU     5
    CVRSS              EQU     4
    CVR3               EQU     3
    CVR2               EQU     2
    CVR1               EQU     1
    CVR0               EQU     0

;   CVRCON2
    FVREN              EQU     7
    FVRST              EQU     6

;   T3CON
;   RD16               EQU     7
    T3CCP2             EQU     6
    T3CKPS1            EQU     5
    T3CKPS0            EQU     4
    T3CCP1             EQU     3
    T3SYNC             EQU     2
    TMR3CS             EQU     1
    TMR3ON             EQU     0

;   TXSTA
    CSRC               EQU     7
    TX9                EQU     6
    TXEN               EQU     5
    SYNC               EQU     4
    SENDB              EQU     3
    BRGH               EQU     2
    TRMT               EQU     1
    TX9D               EQU     0

;   RCSTA
    SPEN               EQU     7
    RX9                EQU     6
    SREN               EQU     5
    CREN               EQU     4
    ADDEN              EQU     3
    FERR               EQU     2
    OERR               EQU     1
    RX9D               EQU     0

;   EECON1
    EEPGD              EQU     7
    CFGS               EQU     6
    FREE               EQU     4
    WRERR              EQU     3
    WREN               EQU     2
    WR                 EQU     1
    RD                 EQU     0

;   IPR2
    OSCFIP             EQU     7
    C1IP               EQU     6
    C2IP               EQU     5
    EEIP               EQU     4
    BCLIP              EQU     3
    HLVDIP             EQU     2
    TMR3IP             EQU     1
    CCP2IP             EQU     0

;   PIR2
    OSCFIF             EQU     7
    C1IF               EQU     6
    C2IF               EQU     5
    EEIF               EQU     4
    BCLIF              EQU     3
    HLVDIF             EQU     2
    TMR3IF             EQU     1
    CCP2IF             EQU     0

;   PIE2
    OSCFIE             EQU     7
    C1IE               EQU     6
    C2IE               EQU     5
    EEIE               EQU     4
    BCLIE              EQU     3
    HLVDIE             EQU     2
    TMR3IE             EQU     1
    CCP2IE             EQU     0

;   IPR1
    PSPIP              EQU     7
    ADIP               EQU     6
    RCIP               EQU     5
    TXIP               EQU     4
    SSPIP              EQU     3
    CCP1IP             EQU     2
    TMR2IP             EQU     1
    TMR1IP             EQU     0

;   PIR1
    PSPIF              EQU     7
    ADIF               EQU     6
    RCIF               EQU     5
    TXIF               EQU     4
    SSPIF              EQU     3
    CCP1IF             EQU     2
    TMR2IF             EQU     1
    TMR1IF             EQU     0

;   PIE1
    PSPIE              EQU     7
    ADIE               EQU     6
    RCIE               EQU     5
    TXIE               EQU     4
    SSPIE              EQU     3
    CCP1IE             EQU     2
    TMR2IE             EQU     1
    TMR1IE             EQU     0

;   OSCTUNE
    INTSRC             EQU     7
    PLLEN              EQU     6
    TUN5               EQU     5
    TUN4               EQU     4
    TUN3               EQU     3
    TUN2               EQU     2
    TUN1               EQU     1
    TUN0               EQU     0

;   TRISE
    IBF                EQU     7
    OBF                EQU     6
    IBOV               EQU     5
    PSPMODE            EQU     4
    TRISE2             EQU     2
    TRISE1             EQU     1
    TRISE0             EQU     0

;   CM1CON0
    C1ON               EQU     7
    C1OUT              EQU     6
    C1OE               EQU     5
    C1POL              EQU     4
    C1SP               EQU     3
    C1R                EQU     2
    C1CH1              EQU     1
    C1CH0              EQU     0

;   CM2CON0
    C2ON               EQU     7
    C2OUT              EQU     6
    C2OE               EQU     5
    C2POL              EQU     4
    C2SP               EQU     3
    C2R                EQU     2
    C2CH1              EQU     1
    C2CH0              EQU     0

;   CM2CON1
    MC1OUT             EQU     7
    MC2OUT             EQU     6
    C1RSEL             EQU     5
    C2RSEL             EQU     4

;   SLRCON
    SLRE               EQU     4
    SLRD               EQU     3
    SLRC               EQU     2
    SLRB               EQU     1
    SLRA               EQU     0

;---------- Alternative Pin Names ----------------

    #define    VPP_PIN         MCLR
    #define    RE3_PIN         MCLR
    #define    AN0_PIN         RA0
    #define    C12IN0_MINUS_PIN  RA0
    #define    AN1_PIN         RA1
    #define    C12IN1_MINUS_PIN  RA1
    #define    AN2_PIN         RA2
    #define    VREF_MINUS_PIN  RA2
    #define    CVREF_PIN       RA2
    #define    C2IN_PLUS_PIN   RA2
    #define    AN3_PIN         RA3
    #define    VREF_PLUS_PIN   RA3
    #define    C1IN_PLUS_PIN   RA3
    #define    T0CKI_PIN       RA4
    #define    C1OUT_PIN       RA4
    #define    AN4_PIN         RA5
    #define    SS_PIN          RA5
    #define    HLVDIN_PIN      RA5
    #define    C2OUT_PIN       RA5
    #define    RD_PIN          RE0
    #define    AN5_PIN         RE0
    #define    WR_PIN          RE1
    #define    AN6_PIN         RE1
    #define    CS_PIN          RE2
    #define    AN7_PIN         RE2
    #define    OSC1_PIN        RA7
    #define    CLKIN_PIN       RA7
    #define    OSC2_PIN        RA6
    #define    CLKOUT_PIN      RA6
    #define    T1OSO_PIN       RC0
    #define    T13CKI_PIN      RC0
    #define    T1OSI_PIN       RC1
    #define    CCP2_PIN        RC1
    #define    CCP1_PIN        RC2
    #define    P1A_PIN         RC2
    #define    SCK_PIN         RC3
    #define    SCL_PIN         RC3
    #define    PSP0_PIN        RD0
    #define    PSP1_PIN        RD1
    #define    PSP2_PIN        RD2
    #define    PSP3_PIN        RD3
    #define    SDI_PIN         RC4
    #define    SDA_PIN         RC4
    #define    SDO_PIN         RC5
    #define    TX_PIN          RC6
    #define    CK_PIN          RC6
    #define    RX_PIN          RC7
    #define    DT_PIN          RC7
    #define    PSP4_PIN        RD4
    #define    PSP5_PIN        RD5
    #define    P1B_PIN         RD5
    #define    PSP6_PIN        RD6
    #define    P1C_PIN         RD6
    #define    PSP7_PIN        RD7
    #define    P1D_PIN         RD7
    #define    INT0_PIN        RB0
    #define    FLT0_PIN        RB0
    #define    AN12_PIN        RB0
    #define    INT1_PIN        RB1
    #define    AN10_PIN        RB1
    #define    C12IN3_MINUS_PIN  RB1
    #define    INT2_PIN        RB2
    #define    AN8_PIN         RB2
    #define    AN9_PIN         RB3
    #define    C12IN2_MINUS_PIN  RB3
    #define    CCP2_PIN        RB3
    #define    KBI0_PIN        RB4
    #define    AN11_PIN        RB4
    #define    KBI1_PIN        RB5
    #define    PGM_PIN         RB5
    #define    KBI2_PIN        RB6
    #define    PGC_PIN         RB6
    #define    KBI3_PIN        RB7
    #define    PGD_PIN         RB7

LIST
