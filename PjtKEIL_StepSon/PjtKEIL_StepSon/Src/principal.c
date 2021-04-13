

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
	
// Avec une p�riode de ticks T = 720
// Fr�quence de la PWM : F = 1/720 = 0,0013888888888889 MHz
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
