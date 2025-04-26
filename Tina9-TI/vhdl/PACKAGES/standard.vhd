PACKAGE standard IS

  TYPE boolean is ( false, true ); 
  TYPE bit IS ( '0', '1' );
  type severity_level is (note, warning, error, failure); 
  type string is array (positive range <>) of character; 
  TYPE bit_vector IS ARRAY ( natural RANGE <> ) OF bit;

END standard;
