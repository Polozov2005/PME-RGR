;;
;; generic include file for PIC24F
;;

.ifdef __24EP256GU810
.include "p24EP256GU810.inc"
.equ VALID_ID,1
.endif

.ifdef __24EP256GU814
.include "p24EP256GU814.inc"
.equ VALID_ID,1
.endif

.ifdef __24EP512GU810
.include "p24EP512GU810.inc"
.equ VALID_ID,1
.endif

.ifdef __24EP512GU814
.include "p24EP512GU814.inc"
.equ VALID_ID,1
.endif

.ifndef VALID_ID
.error "processor ID not specified in generic include file"
.endif
