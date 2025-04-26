LIST
NOLIST
    #DEFINE REF_80085    1
    #DEFINE DEVICE_ATTINY48    1

    TWHSR      EQU     0BEH
    TWAMR      EQU     0BDH
    TWCR       EQU     0BCH
    TWDR       EQU     0BBH
    TWAR       EQU     0BAH
    TWSR       EQU     0B9H
    TWBR       EQU     0B8H
    OCR1BH     EQU     08BH
    OCR1BL     EQU     08AH
    OCR1AH     EQU     089H
    OCR1AL     EQU     088H
    ICR1H      EQU     087H
    ICR1L      EQU     086H
    TCNT1H     EQU     085H
    TCNT1L     EQU     084H
    TCCR1C     EQU     082H
    TCCR1B     EQU     081H
    TCCR1A     EQU     080H
    DIDR1      EQU     07FH
    DIDR0      EQU     07EH
    ADMUX      EQU     07CH
    ADCSRB     EQU     07BH
    ADCSRA     EQU     07AH
    ADCH       EQU     079H
    ADCL       EQU     078H
    TIMSK1     EQU     06FH
    TIMSK0     EQU     06EH
    PCMSK2     EQU     06DH
    PCMSK1     EQU     06CH
    PCMSK0     EQU     06BH
    PCMSK3     EQU     06AH
    EICRA      EQU     069H
    PCICR      EQU     068H
    OSCCAL     EQU     066H
    PRR        EQU     064H
    CLKPR      EQU     061H
    WDTCSR     EQU     060H
    SREG       EQU     03FH
    SPL        EQU     03DH
    SPMCSR     EQU     037H
    MCUCR      EQU     035H
    MCUSR      EQU     034H
    SMCR       EQU     033H
    ACSR       EQU     030H
    SPDR       EQU     02EH
    SPSR       EQU     02DH
    SPCR       EQU     02CH
    GPIOR2     EQU     02BH
    GPIOR1     EQU     02AH
    OCR0B      EQU     028H
    OCR0A      EQU     027H
    TCNT0      EQU     026H
    TCCR0A     EQU     025H
    GTCCR      EQU     023H
    EEARL      EQU     021H
    EEDR       EQU     020H
    EECR       EQU     01FH
    GPIOR0     EQU     01EH
    EIMSK      EQU     01DH
    EIFR       EQU     01CH
    PCIFR      EQU     01BH
    TIFR1      EQU     016H
    TIFR0      EQU     015H
    PORTA      EQU     00EH
    DDRA       EQU     00DH
    PINA       EQU     00CH
    PORTD      EQU     00BH
    DDRD       EQU     00AH
    PIND       EQU     009H
    PORTC      EQU     008H
    DDRC       EQU     007H
    PINC       EQU     006H
    PORTB      EQU     005H
    DDRB       EQU     004H
    PINB       EQU     003H

;---------- BIT POSITIONS --------------------------

;   TWHSR
    TWHS               EQU     0

;   TWAMR
    TWAM6              EQU     7
    TWAM5              EQU     6
    TWAM4              EQU     5
    TWAM3              EQU     4
    TWAM2              EQU     3
    TWAM1              EQU     2
    TWAM0              EQU     1

;   TWCR
    TWINT              EQU     7
    TWEA               EQU     6
    TWSTA              EQU     5
    TWSTO              EQU     4
    TWWC               EQU     3
    TWEN               EQU     2
    TWIE               EQU     0

;   TWAR
    TWA6               EQU     7
    TWA5               EQU     6
    TWA4               EQU     5
    TWA3               EQU     4
    TWA2               EQU     3
    TWA1               EQU     2
    TWA0               EQU     1
    TWGCE              EQU     0

;   TWSR
    TWS7               EQU     7
    TWS6               EQU     6
    TWS5               EQU     5
    TWS4               EQU     4
    TWS3               EQU     3
    TWPS1              EQU     1
    TWPS0              EQU     0

;   TCCR1C
    FOC1A              EQU     7
    FOC1B              EQU     6

;   TCCR1B
    ICNC1              EQU     7
    ICES1              EQU     6
    WGM13              EQU     4
    WGM12              EQU     3
    CS12               EQU     2
    CS11               EQU     1
    CS10               EQU     0

;   TCCR1A
    COM1A1             EQU     7
    COM1A0             EQU     6
    COM1B1             EQU     5
    COM1B0             EQU     4
    WGM11              EQU     1
    WGM10              EQU     0

;   DIDR1
    AIN1D              EQU     1
    AIN0D              EQU     0

;   DIDR0
    ADC7D              EQU     7
    ADC6D              EQU     6
    ADC5D              EQU     5
    ADC4D              EQU     4
    ADC3D              EQU     3
    ADC2D              EQU     2
    ADC1D              EQU     1
    ADC0D              EQU     0

;   ADMUX
    REFS0              EQU     6
    ADLAR              EQU     5
    MUX3               EQU     3
    MUX2               EQU     2
    MUX1               EQU     1
    MUX0               EQU     0

;   ADCSRB
    ACME               EQU     6
    ADTS2              EQU     2
    ADTS1              EQU     1
    ADTS0              EQU     0

;   ADCSRA
    ADEN               EQU     7
    ADSC               EQU     6
    ADATE              EQU     5
    ADIF               EQU     4
    ADIE               EQU     3
    ADPS2              EQU     2
    ADPS1              EQU     1
    ADPS0              EQU     0

;   TIMSK1
    ICIE1              EQU     5
    OCIE1B             EQU     2
    OCIE1A             EQU     1
    TOIE1              EQU     0

;   TIMSK0
    OCIE0B             EQU     2
    OCIE0A             EQU     1
    TOIE0              EQU     0

;   PCMSK2
    PCINT23            EQU     7
    PCINT22            EQU     6
    PCINT21            EQU     5
    PCINT20            EQU     4
    PCINT19            EQU     3
    PCINT18            EQU     2
    PCINT17            EQU     1
    PCINT16            EQU     0

;   PCMSK1
    PCINT14            EQU     6
    PCINT13            EQU     5
    PCINT12            EQU     4
    PCINT11            EQU     3
    PCINT10            EQU     2
    PCINT9             EQU     1
    PCINT8             EQU     0

;   PCMSK0
    PCINT7             EQU     7
    PCINT6             EQU     6
    PCINT5             EQU     5
    PCINT4             EQU     4
    PCINT3             EQU     3
    PCINT2             EQU     2
    PCINT1             EQU     1
    PCINT0             EQU     0

;   PCMSK3
    PCINT27            EQU     3
    PCINT26            EQU     2
    PCINT25            EQU     1
    PCINT24            EQU     0

;   EICRA
    ISC11              EQU     3
    ISC10              EQU     2
    ISC01              EQU     1
    ISC00              EQU     0

;   PCICR
    PCIE3              EQU     3
    PCIE2              EQU     2
    PCIE1              EQU     1
    PCIE0              EQU     0

;   PRR
    PRTWI              EQU     7
    PRTIM0             EQU     5
    PRTIM1             EQU     3
    PRSPI              EQU     2
    PRADC              EQU     0

;   CLKPR
    CLKPCE             EQU     7
    CLKPS3             EQU     3
    CLKPS2             EQU     2
    CLKPS1             EQU     1
    CLKPS0             EQU     0

;   WDTCSR
    WDIF               EQU     7
    WDIE               EQU     6
    WDP3               EQU     5
    WDCE               EQU     4
    WDE                EQU     3
    WDP2               EQU     2
    WDP1               EQU     1
    WDP0               EQU     0

;   SPMCSR
    CTPS               EQU     4
    RFLB               EQU     3
    PGWRT              EQU     2
    PGERS              EQU     1
    SELFPRGEN          EQU     0

;   MCUCR
    BPDS               EQU     6
    BPDSE              EQU     5
    PUD                EQU     4

;   MCUSR
    WDRF               EQU     3
    BORF               EQU     2
    EXTRF              EQU     1
    PORF               EQU     0

;   SMCR
    SM1                EQU     2
    SM0                EQU     1
    SE                 EQU     0

;   ACSR
    ACD                EQU     7
    ACBG               EQU     6
    ACO                EQU     5
    ACI                EQU     4
    ACIE               EQU     3
    ACIC               EQU     2
    ACIS1              EQU     1
    ACIS0              EQU     0

;   SPSR
    SPIF               EQU     7
    WCOL               EQU     6
    SPI2X              EQU     0

;   SPCR
    SPIE               EQU     7
    SPE                EQU     6
    DORD               EQU     5
    MSTR               EQU     4
    CPOL               EQU     3
    CPHA               EQU     2
    SPR1               EQU     1
    SPR0               EQU     0

;   TCCR0A
    CTC0               EQU     3
    CS02               EQU     2
    CS01               EQU     1
    CS00               EQU     0

;   GTCCR
    TSM                EQU     7
    PSRSYNC            EQU     0

;   EECR
    EEPM1              EQU     5
    EEPM0              EQU     4
    EERIE              EQU     3
    EEMPE              EQU     2
    EEPE               EQU     1
    EERE               EQU     0

;   EIMSK
    INT1               EQU     1
    INT0               EQU     0

;   EIFR
    INTF1              EQU     1
    INTF0              EQU     0

;   PCIFR
    PCIF3              EQU     3
    PCIF2              EQU     2
    PCIF1              EQU     1
    PCIF0              EQU     0

;   TIFR1
    ICF1               EQU     5
    OCF1B              EQU     2
    OCF1A              EQU     1
    TOV1               EQU     0

;   TIFR0
    OCF0B              EQU     2
    OCF0A              EQU     1
    TOV0               EQU     0

;---------- Alternative Pin Names ----------------

    #define    PCINT14_PIN     PC6
    #define    RESET_PIN       PC6
    #define    PCINT16_PIN     PD0
    #define    PCINT17_PIN     PD1
    #define    PCINT18_PIN     PD2
    #define    INT0_PIN        PD2
    #define    PCINT19_PIN     PD3
    #define    INT1_PIN        PD3
    #define    PCINT20_PIN     PD4
    #define    T0_PIN          PD4
    #define    PCINT6_PIN      PB6
    #define    CLKI_PIN        PB6
    #define    PCINT7_PIN      PB7
    #define    PCINT21_PIN     PD5
    #define    T1_PIN          PD5
    #define    PCINT22_PIN     PD6
    #define    AIN0_PIN        PD6
    #define    PCINT23_PIN     PD7
    #define    AIN1_PIN        PD7
    #define    PCINT0_PIN      PB0
    #define    CLKO_PIN        PB0
    #define    ICP1_PIN        PB0
    #define    OC1A_PIN        PB1
    #define    PCINT1_PIN      PB1
    #define    SS_PIN          PB2
    #define    OC1B_PIN        PB2
    #define    PCINT2_PIN      PB2
    #define    MOSI_PIN        PB3
    #define    PCINT3_PIN      PB3
    #define    MISO_PIN        PB4
    #define    PCINT4_PIN      PB4
    #define    SCK_PIN         PB5
    #define    PCINT5_PIN      PB5
    #define    PCINT15_PIN     PC7
    #define    ADC0_PIN        PC0
    #define    PCINT8_PIN      PC0
    #define    ADC1_PIN        PC1
    #define    PCINT9_PIN      PC1
    #define    ADC2_PIN        PC2
    #define    PCINT10_PIN     PC2
    #define    ADC3_PIN        PC3
    #define    PCINT11_PIN     PC3
    #define    ADC4_PIN        PC4
    #define    SDA_PIN         PC4
    #define    PCINT12_PIN     PC4
    #define    ADC5_PIN        PC5
    #define    SCL_PIN         PC5
    #define    PCINT13_PIN     PC5

;--------- SRAM ----------------

    #define    SRAM_START    96
    #define    SRAM_END      351
    #define    SRAM_SIZE     256

;--------- Interrupt Vector ----------------

    #define    RESETaddr       0
    #define    INT0addr        1
    #define    INT1addr        2
    #define    PCI0addr        3
    #define    PCI1addr        4
    #define    PCI2addr        5
    #define    PCI3addr        6
    #define    WDTaddr         7
    #define    ICP1addr        8
    #define    OC1Aaddr        9
    #define    OC1Baddr        10
    #define    OVF1addr        11
    #define    OC0Aaddr        12
    #define    OC0Baddr        13
    #define    OVF0addr        14
    #define    SPIaddr         15
    #define    ADCCaddr        16
    #define    ERDYaddr        17
    #define    ACIaddr         18
    #define    TWIaddr         19

LIST
