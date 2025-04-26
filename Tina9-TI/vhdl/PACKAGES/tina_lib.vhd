LIBRARY ieee;
use ieee.std_logic_1164.all;


PACKAGE primitives IS

	
	--------------------
	-- synth
	--------------------
	COMPONENT comp_latch_jkffpc_synth
	GENERIC (
		latching : integer := 0);
	PORT (
                j, k, clk, cl,
	 	pr   : IN  std_logic;
		q    : OUT std_logic;
	 	qNot : OUT std_logic );
	END COMPONENT;
	
	
	COMPONENT comp_latch_jkffpc_ms_synth
	GENERIC (
		latching : integer := 0);
	PORT (
                j, k, clk, p,
	 	c    : IN  std_logic;
		q    : OUT std_logic;
	 	qNot : OUT std_logic );
	END COMPONENT;


	COMPONENT comp_latch_jkffpc_ms_falling_synth
	GENERIC (
		latching : integer := 0);
	PORT (
                j, k, clk, p,
	 	c    : IN  std_logic;
		q    : OUT std_logic;
	 	qNot : OUT std_logic );
	END COMPONENT;
	

	COMPONENT comp_dlatch
	PORT (q : OUT std_logic;
	 	d : IN std_logic;
	 	e : IN std_logic
	 	);
	END COMPONENT;

	COMPONENT comp_dlatch2
	PORT (q : OUT std_logic;
	 	d : IN std_logic;
	 	e : IN std_logic;
	 	pr : IN std_logic;
	 	cl : IN std_logic
	 	); 	
	END COMPONENT;

	COMPONENT comp_tsb
	PORT (q : OUT std_logic;
	 	d : IN std_logic;
	 	e : IN std_logic
	 	);
	END COMPONENT;

	COMPONENT comp_pullup 
	PORT (d : IN std_logic;
	      q : OUT std_logic
	 	);
	END COMPONENT;
		
	COMPONENT comp_switch1 
	PORT (d : IN std_logic;
	      q : OUT std_logic;
	 	  e : IN integer
	 	 );
	END COMPONENT;
	
	COMPONENT comp_alt_switch
	PORT (d1, d2 : IN std_logic;
	      q : OUT std_logic;
	      e : IN integer
	 	 );
	END COMPONENT;
	
	COMPONENT comp_dip2 IS
	PORT (d0, d1 : IN std_logic;
		  q0, q1 : OUT std_logic;
		  e0, e1 : IN integer
		 );
	END COMPONENT;
        
	COMPONENT comp_dip3 IS
	PORT (d0, d1, d2 : IN std_logic;
		  q0, q1, q2 : OUT std_logic;
		  e0, e1, e2 : IN integer
		 );
	END COMPONENT;
	
	COMPONENT comp_dip4 IS
	PORT (d0, d1, d2, d3 : IN std_logic;
		  q0, q1, q2, q3 : OUT std_logic;
		  e0, e1, e2, e3 : IN integer
		 );
	END COMPONENT;
	
	
	COMPONENT comp_dip5 IS
	PORT (d0, d1, d2, d3, d4 : IN std_logic;
		  q0, q1, q2, q3, q4 : OUT std_logic;
		  e0, e1, e2, e3, e4 : IN integer
		 );
	END COMPONENT;
	
	COMPONENT comp_dip6 IS
	PORT (d0, d1, d2, d3, d4, d5 : IN std_logic;
		  q0, q1, q2, q3, q4, q5 : OUT std_logic;
		  e0, e1, e2, e3, e4, e5 : IN integer
		 );
	END COMPONENT;
	
	COMPONENT comp_dip7 IS
	PORT (d0, d1, d2, d3, d4, d5, d6 : IN std_logic;
		  q0, q1, q2, q3, q4, q5, q6 : OUT std_logic;
		  e0, e1, e2, e3, e4, e5, e6 : IN integer
		 );
	END COMPONENT;
	
	COMPONENT comp_dip8 IS
	PORT (d0, d1, d2, d3, d4, d5, d6, d7 : IN std_logic;
		  q0, q1, q2, q3, q4, q5, q6, q7 : OUT std_logic;
		  e0, e1, e2, e3, e4, e5, e6, e7 : IN integer
		 );
	END COMPONENT;
	
	COMPONENT comp_battery
	PORT (d : IN std_logic;
	      q : OUT std_logic
	 	);
	END COMPONENT;
		
	COMPONENT comp_resistor
	PORT (d : IN std_logic;
	      q : OUT std_logic
	 	);
	END COMPONENT;

        COMPONENT comp_hexkeypad
        PORT (d : IN integer;
              q0, q1, q2, q3 : OUT std_logic
                 );
        END COMPONENT;


	COMPONENT comp_dffpc 
	PORT (q : OUT std_logic;
		qNot : OUT std_logic;
		d : IN std_logic;
		clk : IN std_logic;
		cl : IN std_logic;
		pr : IN std_logic
		);
	END COMPONENT;

	COMPONENT comp_cmos_ram_256x4  
	PORT (
	 a0, a1, a2, a3, a4, a5, a6, a7: IN std_logic;
	 di1, di2, di3, di4: IN std_logic;
	 ce1, ce2, rw, od: IN std_logic;
	 do1, do2, do3, do4: OUT std_logic
	); 	
	END COMPONENT; 

	COMPONENT comp_cmos_ram_2048x8 is 
	PORT (
	 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10: IN std_logic;
	 di1, di2, di3, di4, di5, di6, di7, di8: IN std_logic;
	 cs, rw, od: IN std_logic;
	 do1, do2, do3, do4, do5, do6, do7, do8: OUT std_logic
	); 	
	END COMPONENT; 

	COMPONENT comp_cmos_ram_1024x4 is 
	PORT (
	 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9: IN std_logic;
	 di1, di2, di3, di4: IN std_logic;
	 cs, rw, od: IN std_logic;
	 do1, do2, do3, do4: OUT std_logic
	); 	
	END COMPONENT; 

	
END primitives;


--------------------
-- synth
--------------------
LIBRARY ieee;
use ieee.std_logic_1164.all;


ENTITY comp_latch_jkffpc_synth IS
GENERIC (
	latching : integer := 0
	);
PORT (q : OUT std_logic;
 	qNot : OUT std_logic;
 	j : IN std_logic;
 	k : IN std_logic;
 	clk : IN std_logic;
 	cl : IN std_logic;
 	pr : IN std_logic
 	);
END comp_latch_jkffpc_synth;

ARCHITECTURE a_comp_latch_jkffpc OF comp_latch_jkffpc_synth IS

signal q_s : std_logic := '0';

BEGIN

comp_jkffpc_process: PROCESS (cl, clk, pr)
BEGIN

  if (cl = '0') then
    q_s <= '0';
  elsif (pr = '0') then
    q_s <= '1';
  elsif (clk = '1' and clk'event and latching = 0) or (clk = '0' and clk'event and latching = 1) then
   if (j = '1' and k = '1') then
    q_s  <= not q_s;
   elsif k = '1' then
    q_s  <= '0';
   elsif j = '1' then
    q_s  <= '1';
   end if;    
  end if;  

END PROCESS;

q <= q_s;
qNot <= not q_s;

END a_comp_latch_jkffpc;



LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_latch_jkffpc_ms_synth IS 
GENERIC (
 latching : integer := 0
	);
PORT (q : OUT std_logic;
 	qNot : OUT std_logic;
 	j : IN std_logic;
 	k : IN std_logic;
 	clk : IN std_logic;
 	c : IN std_logic;
 	p : IN std_logic
 	);
END comp_latch_jkffpc_ms_synth; 

ARCHITECTURE a_comp_latch_jkffpc_ms of comp_latch_jkffpc_ms_synth IS

COMPONENT comp_latch_jkffpc_synth
GENERIC (
	latching : integer := 0);
PORT (
	j, k, clk, cl,
	pr   : IN  std_logic;
	q    : OUT std_logic;
	qNot : OUT std_logic );
END COMPONENT;

 signal N2 : std_logic;
 signal N9 : std_logic;
 signal N10 : std_logic;

BEGIN

 JKFFPC_1: comp_latch_JKFFPC_synth
  GENERIC MAP (latching=>0)
  PORT MAP (q=>N9, qNot=>N10, j=>J, k=>K, clk=>CLK, cl=>C, pr=>P);
 JKFFPC_2: comp_latch_JKFFPC_synth
  GENERIC MAP (latching=>0)
  PORT MAP (q=>Q, qNot=>qNot, j=>N9, k=>N10, clk=>N2, cl=>C, pr=>P);


 N2 <= NOT ( CLK );

END a_comp_latch_jkffpc_ms;



LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_latch_jkffpc_ms_falling_synth IS 
GENERIC (
 latching : integer := 0
	);
PORT (q : OUT std_logic;
 	qNot : OUT std_logic;
 	j : IN std_logic;
 	k : IN std_logic;
 	clk : IN std_logic;
 	c : IN std_logic;
 	p : IN std_logic
 	);
END comp_latch_jkffpc_ms_falling_synth;

ARCHITECTURE a_comp_latch_jkffpc_ms_falling of comp_latch_jkffpc_ms_falling_synth IS

COMPONENT comp_latch_jkffpc_synth
GENERIC (
	latching : integer := 0);
PORT (
	j, k, clk, cl,
	pr   : IN  std_logic;
	q    : OUT std_logic;
	qNot : OUT std_logic );
END COMPONENT;

 signal N2, not_clk : std_logic;
 signal N9 : std_logic;
 signal N10 : std_logic;

BEGIN

 JKFFPC_1: comp_latch_JKFFPC_synth
  GENERIC MAP (latching=>0)
  PORT MAP (q=>N9, qNot=>N10, j=>J, k=>K, clk=>not_clk, cl=>C, pr=>P);
 JKFFPC_2: comp_latch_JKFFPC_synth
  GENERIC MAP (latching=>0)
  PORT MAP (q=>Q, qNot=>qNot, j=>N9, k=>N10, clk=>N2, cl=>C, pr=>P);


 not_clk <= NOT ( CLK );
 N2 <= NOT ( not_clk );

END a_comp_latch_jkffpc_ms_falling;




LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_dlatch IS
PORT (q : OUT std_logic;
 	d : IN std_logic;
 	e : IN std_logic
 	);
END comp_dlatch;

ARCHITECTURE a_comp_latch OF comp_dlatch IS
 SIGNAL N1  : std_logic := '0';
BEGIN

comp_latch_process: PROCESS (d, e)
BEGIN
 IF ( e = '1' ) THEN
  N1 <= d;
 END IF;
END PROCESS;

q <= N1;

END a_comp_latch;


LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_dlatch2 IS
PORT (q : OUT std_logic;
 	d : IN std_logic;
 	e : IN std_logic;
 	pr : IN std_logic;
 	cl : IN std_logic
 	);
END comp_dlatch2;

ARCHITECTURE a_comp_latch2 OF comp_dlatch2 IS
 SIGNAL N1  : std_logic := '0';
BEGIN

comp_latch_process: PROCESS (d, e, pr, cl)
BEGIN
 IF ( pr = '0' ) THEN
  N1 <= '1'; 
 ELSIF ( cl = '0' ) THEN
  N1 <= '0'; 
 ELSIF ( e = '1' ) THEN
  N1 <= d;
 END IF;
END PROCESS;

q <= N1;

END a_comp_latch2;


LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_tsb IS
PORT (q : OUT std_logic;
 	d : IN std_logic;
 	e : IN std_logic
 	);
END comp_tsb;

ARCHITECTURE a_tsb OF comp_tsb IS
BEGIN

comp_tsb_process: PROCESS (d, e)
BEGIN
 IF ( e = '1' ) THEN
  q <= d;
 ELSE
  q <= 'Z';
 END IF;
END PROCESS;

END a_tsb;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_pullup IS
PORT (q : OUT std_logic;
      d : IN std_logic
 	 );
END comp_pullup;

ARCHITECTURE arch OF comp_pullup IS
BEGIN

comp_process: PROCESS (d)
BEGIN
 IF ( d = '1' ) THEN
  q <= 'H';
 ELSIF ( d = '0' ) THEN
  q <= 'L';
 ELSE 
  q <= 'Z';
 END IF;
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_switch1 IS
PORT ( q : OUT std_logic;
       d : IN std_logic;
       e : IN integer
 	 );
END comp_switch1;

ARCHITECTURE arch OF comp_switch1 IS
BEGIN

comp_process: PROCESS (d, e)
BEGIN
 IF ( e = 1 ) THEN
  q <= d;
 ELSE
  q <= 'Z';
 END IF; 
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_alt_switch IS
PORT (q : OUT std_logic;
      d1, d2 : IN std_logic;
      e : IN integer
 	 );
END comp_alt_switch;

ARCHITECTURE arch OF comp_alt_switch IS
BEGIN

comp_process: PROCESS (d1, d2, e)
BEGIN
 IF ( e = 1 ) THEN
  q <= d1;
 ELSE
  q <= d2;
 END IF; 
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_dip2 IS
PORT (
      q0, q1 : OUT std_logic;
      d0, d1 : IN std_logic;
      e0, e1 : IN integer
 	 );
END comp_dip2;

ARCHITECTURE arch OF comp_dip2 IS
BEGIN

comp_process: PROCESS (d0, d1, e0, e1)
BEGIN
 IF ( e0 = 1 ) THEN q0 <= d0; ELSE q0 <= 'Z'; END IF; 
 IF ( e1 = 1 ) THEN q1 <= d1; ELSE q1 <= 'Z'; END IF; 
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_dip3 IS
PORT (
      q0, q1, q2 : OUT std_logic;
      d0, d1, d2 : IN std_logic;
      e0, e1, e2 : IN integer
 	 );
END comp_dip3;

ARCHITECTURE arch OF comp_dip3 IS
BEGIN

comp_process: PROCESS (d0, d1, d2, e0, e1, e2)
BEGIN
 IF ( e0 = 1 ) THEN q0 <= d0; ELSE q0 <= 'Z'; END IF; 
 IF ( e1 = 1 ) THEN q1 <= d1; ELSE q1 <= 'Z'; END IF; 
 IF ( e2 = 1 ) THEN q2 <= d2; ELSE q2 <= 'Z'; END IF; 
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_dip4 IS
PORT (
      q0, q1, q2, q3 : OUT std_logic;
      d0, d1, d2, d3 : IN std_logic;
      e0, e1, e2, e3 : IN integer
 	 );
END comp_dip4;

ARCHITECTURE arch OF comp_dip4 IS
BEGIN

comp_process: PROCESS (d0, d1, d2, d3, e0, e1, e2, e3)
BEGIN
 IF ( e0 = 1 ) THEN q0 <= d0; ELSE q0 <= 'Z'; END IF; 
 IF ( e1 = 1 ) THEN q1 <= d1; ELSE q1 <= 'Z'; END IF; 
 IF ( e2 = 1 ) THEN q2 <= d2; ELSE q2 <= 'Z'; END IF; 
 IF ( e3 = 1 ) THEN q3 <= d3; ELSE q3 <= 'Z'; END IF; 
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_dip5 IS
PORT (
      q0, q1, q2, q3, q4 : OUT std_logic;
      d0, d1, d2, d3, d4 : IN std_logic;
      e0, e1, e2, e3, e4 : IN integer
 	 );
END comp_dip5;

ARCHITECTURE arch OF comp_dip5 IS
BEGIN

comp_process: PROCESS (d0, d1, d2, d3, d4, e0, e1, e2, e3, e4)
BEGIN
 IF ( e0 = 1 ) THEN q0 <= d0; ELSE q0 <= 'Z'; END IF; 
 IF ( e1 = 1 ) THEN q1 <= d1; ELSE q1 <= 'Z'; END IF; 
 IF ( e2 = 1 ) THEN q2 <= d2; ELSE q2 <= 'Z'; END IF; 
 IF ( e3 = 1 ) THEN q3 <= d3; ELSE q3 <= 'Z'; END IF; 
 IF ( e4 = 1 ) THEN q4 <= d4; ELSE q4 <= 'Z'; END IF; 
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_dip6 IS
PORT (
      q0, q1, q2, q3, q4, q5 : OUT std_logic;
      d0, d1, d2, d3, d4, d5 : IN std_logic;
      e0, e1, e2, e3, e4, e5 : IN integer
 	 );
END comp_dip6;

ARCHITECTURE arch OF comp_dip6 IS
BEGIN

comp_process: PROCESS (d0, d1, d2, d3, d4, d5, e0, e1, e2, e3, e4, e5)
BEGIN
 IF ( e0 = 1 ) THEN q0 <= d0; ELSE q0 <= 'Z'; END IF; 
 IF ( e1 = 1 ) THEN q1 <= d1; ELSE q1 <= 'Z'; END IF; 
 IF ( e2 = 1 ) THEN q2 <= d2; ELSE q2 <= 'Z'; END IF; 
 IF ( e3 = 1 ) THEN q3 <= d3; ELSE q3 <= 'Z'; END IF; 
 IF ( e4 = 1 ) THEN q4 <= d4; ELSE q4 <= 'Z'; END IF; 
 IF ( e5 = 1 ) THEN q5 <= d5; ELSE q5 <= 'Z'; END IF; 
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_dip7 IS
PORT (
      q0, q1, q2, q3, q4, q5, q6 : OUT std_logic;
      d0, d1, d2, d3, d4, d5, d6 : IN std_logic;
      e0, e1, e2, e3, e4, e5, e6 : IN integer
 	 );
END comp_dip7;

ARCHITECTURE arch OF comp_dip7 IS
BEGIN

comp_process: PROCESS (d0, d1, d2, d3, d4, d5, d6, e0, e1, e2, e3, e4, e5, e6)
BEGIN
 IF ( e0 = 1 ) THEN q0 <= d0; ELSE q0 <= 'Z'; END IF; 
 IF ( e1 = 1 ) THEN q1 <= d1; ELSE q1 <= 'Z'; END IF; 
 IF ( e2 = 1 ) THEN q2 <= d2; ELSE q2 <= 'Z'; END IF; 
 IF ( e3 = 1 ) THEN q3 <= d3; ELSE q3 <= 'Z'; END IF; 
 IF ( e4 = 1 ) THEN q4 <= d4; ELSE q4 <= 'Z'; END IF; 
 IF ( e5 = 1 ) THEN q5 <= d5; ELSE q5 <= 'Z'; END IF; 
 IF ( e6 = 1 ) THEN q6 <= d6; ELSE q6 <= 'Z'; END IF; 
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_dip8 IS
PORT (
      q0, q1, q2, q3, q4, q5, q6, q7 : OUT std_logic;
      d0, d1, d2, d3, d4, d5, d6, d7 : IN std_logic;
      e0, e1, e2, e3, e4, e5, e6, e7 : IN integer
 	 );
END comp_dip8;

ARCHITECTURE arch OF comp_dip8 IS
BEGIN

comp_process: PROCESS (d0, d1, d2, d3, d4, d5, d6, d7, e0, e1, e2, e3, e4, e5, e6, e7)
BEGIN
 IF ( e0 = 1 ) THEN q0 <= d0; ELSE q0 <= 'Z'; END IF; 
 IF ( e1 = 1 ) THEN q1 <= d1; ELSE q1 <= 'Z'; END IF; 
 IF ( e2 = 1 ) THEN q2 <= d2; ELSE q2 <= 'Z'; END IF; 
 IF ( e3 = 1 ) THEN q3 <= d3; ELSE q3 <= 'Z'; END IF; 
 IF ( e4 = 1 ) THEN q4 <= d4; ELSE q4 <= 'Z'; END IF; 
 IF ( e5 = 1 ) THEN q5 <= d5; ELSE q5 <= 'Z'; END IF; 
 IF ( e6 = 1 ) THEN q6 <= d6; ELSE q6 <= 'Z'; END IF; 
 IF ( e7 = 1 ) THEN q7 <= d7; ELSE q7 <= 'Z'; END IF; 
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_battery IS
PORT (q : OUT std_logic;
      d : IN std_logic
 	 );
END comp_battery;

ARCHITECTURE arch OF comp_battery IS
BEGIN

comp_process: PROCESS (d)
BEGIN
  q <= '1';
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_resistor IS
PORT (q : OUT std_logic;
      d : IN std_logic
 	 );
END comp_resistor;

ARCHITECTURE arch OF comp_resistor IS
BEGIN

comp_process: PROCESS (d)
BEGIN
  q <= d;
END PROCESS;

END arch;

LIBRARY ieee;
use ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;
USE ieee.std_logic_arith.all;


ENTITY comp_hexkeypad IS
PORT (
      q0, q1, q2, q3 : OUT std_logic;
      d : IN integer
 	 );
END comp_hexkeypad;

ARCHITECTURE arch OF comp_hexkeypad IS
BEGIN

comp_process: PROCESS (d)
 variable O: STD_LOGIC_VECTOR(3 DOWNTO 0);
BEGIN
  O := CONV_STD_LOGIC_VECTOR( d, 4 );
  q0 <= O(0);
  q1 <= O(1);
  q2 <= O(2);
  q3 <= O(3);
END PROCESS;

END arch;



LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_dffpc IS
PORT (q : OUT std_logic;
 	qNot : OUT std_logic;
 	d : IN std_logic;
 	clk : IN std_logic;
 	cl : IN std_logic;
 	pr : IN std_logic
 	);
END comp_dffpc;

ARCHITECTURE arch OF comp_dffpc IS
 signal q_s : std_logic := '0';
BEGIN

proc: PROCESS (cl, clk, pr)
BEGIN
  if (cl = '0') then
    q_s <= '0';
  elsif (pr = '0') then
    q_s <= '1';
  elsif (clk = '1' and clk'event) then
    q_s <= d;
  end if;  
END PROCESS;

q <= q_s after 10 ns;
qNot <= not q_s after 10 ns;

END arch;



library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use std.textio.all;

entity comp_cmos_ram_256x4 is 
port (
 a0, a1, a2, a3, a4, a5, a6, a7: IN std_logic;
 di1, di2, di3, di4: IN std_logic;
 ce1, ce2, rw, od: IN std_logic;
 do1, do2, do3, do4: OUT std_logic
); 	
end comp_cmos_ram_256x4; 

architecture arch of comp_cmos_ram_256x4 is
 type mem_typ is array(0 to 255) of std_logic_vector(3 downto 0);
 signal mem_reserved_signal: mem_typ; 
begin
 mem_proc: process( a0, a1, a2, a3, a4, a5, a6, a7, di1, di2, di3, di4, ce1, ce2, rw, od )
  variable idx: integer;
  variable data: std_logic_vector(3 downto 0); 
  variable addr: std_logic_vector(7 downto 0); 
 begin		 
	 
  addr(0) := a0; addr(1) := a1; addr(2) := a2; addr(3) := a3; addr(4) := a4; addr(5) := a5; addr(6) := a6; addr(7) := a7;
  
  data := "ZZZZ";
  idx := conv_integer(addr(7 downto 0));

  -- rd
  if (od = '0' and rw = '1' and ce1 = '0' and ce2 = '1') then
   data := mem_reserved_signal(idx);
  end if;

  -- wr
  if (od = '0' and rw = '0' and ce1 = '0' and ce2 = '1') then
   data(3) := di4;
   data(2) := di3;
   data(1) := di2;
   data(0) := di1;
   mem_reserved_signal(idx) <= data;
  end if;

  do4 <= data(3);
  do3 <= data(2);
  do2 <= data(1);
  do1 <= data(0); 
  
 end process;
end arch; 

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity comp_cmos_ram_2048x8 is 
port (
 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10: IN std_logic;
 di1, di2, di3, di4, di5, di6, di7, di8: IN std_logic;
 cs, rw, od: IN std_logic;
 do1, do2, do3, do4, do5, do6, do7, do8: OUT std_logic
); 	
end comp_cmos_ram_2048x8; 

architecture arch of comp_cmos_ram_2048x8 is
 type mem_typ is array(0 to 2047) of std_logic_vector(7 downto 0);
 signal mem_reserved_signal: mem_typ; 
begin
 mem_proc: process( a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, di1, di2, di3, di4, di5, di6, di7, di8, cs, rw, od )
  variable idx: integer;
  variable data: std_logic_vector(7 downto 0); 
  variable addr: std_logic_vector(10 downto 0); 
 begin		 
	 
  addr(0) := a0; addr(1) := a1; addr(2) := a2; addr(3) := a3; addr(4) := a4; addr(5) := a5; addr(6) := a6; addr(7) := a7;
  addr(8) := a8; addr(9) := a9; addr(10) := a10; 
  
  data := "ZZZZZZZZ";
  idx := conv_integer(addr(10 downto 0));

  -- rd
  if (od = '0' and rw = '1' and cs = '0') then
   data := mem_reserved_signal(idx);
  end if;

  -- wr
  if (od = '0' and rw = '0' and cs = '0') then
   data(7) := di8;
   data(6) := di7;
   data(5) := di6;
   data(4) := di5;
   data(3) := di4;
   data(2) := di3;
   data(1) := di2;
   data(0) := di1;
   mem_reserved_signal(idx) <= data;
  end if;

  do8 <= data(7);
  do7 <= data(6);
  do6 <= data(5);
  do5 <= data(4);
  do4 <= data(3);
  do3 <= data(2);
  do2 <= data(1);
  do1 <= data(0); 
  
 end process;
end arch; 

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity comp_cmos_ram_1024x4 is 
port (
 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9: IN std_logic;
 di1, di2, di3, di4: IN std_logic;
 cs, rw, od: IN std_logic;
 do1, do2, do3, do4: OUT std_logic
); 	
end comp_cmos_ram_1024x4; 

architecture arch of comp_cmos_ram_1024x4 is
 type mem_typ is array(0 to 1023) of std_logic_vector(3 downto 0);
 signal mem_reserved_signal: mem_typ; 
begin
 mem_proc: process( a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, di1, di2, di3, di4, cs, rw, od )
  variable idx: integer;
  variable data: std_logic_vector(3 downto 0); 
  variable addr: std_logic_vector(9 downto 0); 
 begin		 
	 
  addr(0) := a0; addr(1) := a1; addr(2) := a2; addr(3) := a3; addr(4) := a4; addr(5) := a5; addr(6) := a6; addr(7) := a7;
  addr(8) := a8; addr(9) := a9; 
  
  data := "ZZZZ";
  idx := conv_integer(addr(9 downto 0));

  -- rd
  if (od = '0' and rw = '1' and cs = '0') then
   data := mem_reserved_signal(idx);
  end if;

  -- wr
  if (od = '0' and rw = '0' and cs = '0') then
   data(3) := di4;
   data(2) := di3;
   data(1) := di2;
   data(0) := di1;
   mem_reserved_signal(idx) <= data;
  end if;

  do4 <= data(3);
  do3 <= data(2);
  do2 <= data(1);
  do1 <= data(0); 
  
 end process;
end arch; 

