

#include "DriverJeuLaser.h"
void CallbackSon(void);

extern int SortieSon;

extern int indexTable;

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
// Ck = 72MHz, Tck = 1/72MHz = 0,0138µs
// T = 10 * Tck = 10*1/72MHz = 0,138µs
// x/72MHz = 91µs = 0.000091s
// x = 72 000 000 * 0.000091 = 6 552
// ou F = 1/91µs = 1/0.000091
	
// Tson = 91µs = 0.000091s
Timer_1234_Init_ff(TIM4, 6552);
Active_IT_Debordement_Timer(TIM4, 2, CallbackSon);
	
	

//============================================================================	
	
	while	(1)
	{

	}
}
