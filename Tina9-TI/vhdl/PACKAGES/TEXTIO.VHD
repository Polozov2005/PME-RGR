package TEXTIO is

    procedure READLINE(file f: TEXT; L: out LINE);

    procedure READ(L:inout LINE; VALUE: out bit);
    procedure READ(L:inout LINE; VALUE: out bit_vector);
    
    procedure READ(L:inout LINE; VALUE: out integer);
    procedure READ(L:inout LINE; VALUE: out integer; GOOD: out BOOLEAN);

    procedure READ(L:inout LINE; VALUE: out real);
    procedure READ(L:inout LINE; VALUE: out time);
    
    function ENDFILE(file F : TEXT) return boolean;
    
end;

