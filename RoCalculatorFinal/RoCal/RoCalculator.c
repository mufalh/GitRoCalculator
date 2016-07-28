#include "cut.h"
#include <stdio.h>

void __CUT_BRINGUP__Pass( void )
{
}

void __CUT__TestA( void )
{
  ASSERT( 1 == 1, "One should always be equal to one." );
}



void __CUT_TAKEDOWN__Pass( void )
{
}

