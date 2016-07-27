#include "cut.h"
#include <stdio.h>
#include "Methods.c"

void __CUT_BRINGUP__Pass( void )
{
}

void AddTwoRomanNumeralsTest( void )
{
//	ASSERT_EQUALS("IV", addRn("I", "III"));
  ASSERT(strcmp(addRn("I", "III"),"IV") == 0, "One should always be equal to one." );
}


void __CUT_TAKEDOWN__Pass( void )
{
}

