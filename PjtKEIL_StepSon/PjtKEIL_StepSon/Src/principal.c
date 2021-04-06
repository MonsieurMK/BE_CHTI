

#include "DriverJeuLaser.h"
void CallbackSon(void);

extern int SortieSon;

extern int indexTable;

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
CLOCK_Configure();
// Ck = 72MHz, Tck = 1/72MHz = 0,0138�s
// T = 10 * Tck = 10*1/72MHz = 0,138�s
// x/72MHz = 91�s = 0.000091s
// x = 72 000 000 * 0.000091 = 6�552
// ou F = 1/91�s = 1/0.000091
	
// Tson = 91�s = 0.000091s
Timer_1234_Init_ff(TIM4, 6552);
Active_IT_Debordement_Timer(TIM4, 2, CallbackSon);
	
	

//============================================================================	
	
	while	(1)
	{

	}
}
