

#include "DriverJeuLaser.h"

extern short int LeSignal[64]; 

int tab[64];

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
		for (int i = 0; i < 64; i++) {
			tab[i] = DFT_ModuleAuCarre(LeSignal, i);
		}
		
		int i = 0;
	}
}

