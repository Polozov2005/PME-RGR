LIBRARY ieee;
use ieee.std_logic_1164.all;


PACKAGE primitives_vendor_lib IS

	COMPONENT BUFG
	PORT (
                O : OUT std_logic;
	 	I : IN std_logic );
	END COMPONENT;

	COMPONENT BUFGP
	PORT (
                O : OUT std_logic;
	 	I : IN std_logic );
	END COMPONENT;

	
END primitives_vendor_lib;

LIBRARY ieee;
use ieee.std_logic_1164.all;

-- BUFG --
ENTITY BUFG IS
PORT (O : OUT std_logic;
      I : IN std_logic);
END BUFG;

ARCHITECTURE arch OF BUFG IS

BEGIN

O <= I after 360 ps;

END arch;

-- BUFGP --
LIBRARY ieee;
use ieee.std_logic_1164.all;

ENTITY BUFGP IS
PORT (O : OUT std_logic;
      I : IN std_logic);
END BUFGP;

ARCHITECTURE arch OF BUFGP IS

BEGIN

O <= I after 360 ps;

END arch;
