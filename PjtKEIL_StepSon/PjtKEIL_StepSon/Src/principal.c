

#include "DriverJeuLaser.h"
void CallbackSon(void);
void StartSon(void);

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
	
// Avec une période de ticks T = 720
// Fréquence de la PWM : F = 1/720 = 0,0013888888888889 MHz
PWM_Init_ff(TIM3, 3, 720);
GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);
//PWM_Set_Value_TIM3_Ch3(125);
	

//============================================================================	
	
	while	(1)
	{
		for (int i = 0; i < 10000000; i++) {}
		StartSon();
	}
}
