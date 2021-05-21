

#include "DriverJeuLaser.h"

extern short int LeSignal[64]; 

//int tab[64];

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
	

//============================================================================	
	
while	(1)
	{
		DFT_ModuleAuCarre(LeSignal, 17);
		int i = 0;
	}
}

