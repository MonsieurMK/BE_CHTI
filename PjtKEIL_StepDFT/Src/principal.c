

#include "DriverJeuLaser.h"

extern short int LeSignal[64]; 

//int tab[64];

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
CLOCK_Configure();
	

//============================================================================	
	
while	(1)
	{
		DFT_ModuleAuCarre(LeSignal, 17);
		int i = 0;
	}
}

