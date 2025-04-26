LIBRARY ieee;
use ieee.std_logic_1164.all;


PACKAGE primitives_not_synth IS

     -- Latching: 0: rising, 1: falling, 3: MS
     
	
	COMPONENT comp_latch_jkffpc
	GENERIC (
		trise_clk_q,
		tfall_clk_q : time := 1 ns;
		latching : integer := 0);
	PORT (
                j, k, clk, cl,
	 	pr   : IN  std_logic;
		q    : OUT std_logic;
	 	qNot : OUT std_logic );
	END COMPONENT;
	
	
	COMPONENT comp_latch_jkffpc_ms
	GENERIC (
		trise_clk_q,
		tfall_clk_q : time := 1 ns;
		latching : integer := 0);
	PORT (
                j, k, clk, p,
	 	c    : IN  std_logic;
		q    : OUT std_logic;
	 	qNot : OUT std_logic );
	END COMPONENT;


	COMPONENT comp_latch_jkffpc_ms_falling
	GENERIC (
		trise_clk_q,
		tfall_clk_q : time := 1 ns;
		latching : integer := 0);
	PORT (
                j, k, clk, p,
	 	c    : IN  std_logic;
		q    : OUT std_logic;
	 	qNot : OUT std_logic );
	END COMPONENT;

	
END primitives_not_synth;

LIBRARY ieee;
use ieee.std_logic_1164.all;


ENTITY comp_latch_jkffpc IS
GENERIC (
	trise_clk_q : time := 1 ns; 
	tfall_clk_q : time := 1 ns;
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
END comp_latch_jkffpc;

ARCHITECTURE a_comp_latch_jkffpc OF comp_latch_jkffpc IS

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

q <= q_s after trise_clk_q;
qNot <= not q_s after trise_clk_q;

END a_comp_latch_jkffpc;



LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_latch_jkffpc_ms IS 
GENERIC (
 trise_clk_q : time := 1 ns;  
 tfall_clk_q : time := 1 ns;
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
END comp_latch_jkffpc_ms;

ARCHITECTURE a_comp_latch_jkffpc_ms of comp_latch_jkffpc_ms IS

COMPONENT comp_latch_jkffpc
GENERIC (
	trise_clk_q,
	tfall_clk_q : time := 1 ns;
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

 JKFFPC_1: comp_latch_JKFFPC
  GENERIC MAP (trise_clk_q=>30 ns, tfall_clk_q=>30 ns, latching=>0)
  PORT MAP (q=>N9, qNot=>N10, j=>J, k=>K, clk=>CLK, cl=>C, pr=>P);
 JKFFPC_2: comp_latch_JKFFPC
  GENERIC MAP (trise_clk_q=>30 ns, tfall_clk_q=>30 ns, latching=>0)
  PORT MAP (q=>Q, qNot=>qNot, j=>N9, k=>N10, clk=>N2, cl=>C, pr=>P);


 N2 <= NOT ( CLK );

END a_comp_latch_jkffpc_ms;



LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY comp_latch_jkffpc_ms_falling IS 
GENERIC (
 trise_clk_q : time := 1 ns;  
 tfall_clk_q : time := 1 ns;
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
END comp_latch_jkffpc_ms_falling; 

ARCHITECTURE a_comp_latch_jkffpc_ms_falling of comp_latch_jkffpc_ms_falling IS

COMPONENT comp_latch_jkffpc
GENERIC (
	trise_clk_q,
	tfall_clk_q : time := 1 ns;
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

 JKFFPC_1: comp_latch_JKFFPC
  GENERIC MAP (trise_clk_q=>30 ns, tfall_clk_q=>30 ns, latching=>0)
  PORT MAP (q=>N9, qNot=>N10, j=>J, k=>K, clk=>not_clk, cl=>C, pr=>P);
 JKFFPC_2: comp_latch_JKFFPC
  GENERIC MAP (trise_clk_q=>30 ns, tfall_clk_q=>30 ns, latching=>0)
  PORT MAP (q=>Q, qNot=>qNot, j=>N9, k=>N10, clk=>N2, cl=>C, pr=>P);

 not_clk <= NOT ( CLK );
 N2 <= NOT ( not_clk );

END a_comp_latch_jkffpc_ms_falling;

