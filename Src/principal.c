

#include "DriverJeuLaser.h"

extern void timer_callback(void);

extern char FlagCligno;

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
CLOCK_Configure();

// configuration du Timer 4 en d�bordement 100ms

//** Placez votre code l� ** //	
	
// Activation des interruptions issues du Timer 4
// Association de la fonction � ex�cuter lors de l'interruption : timer_callback
// cette fonction (si �crite en ASM) doit �tre conforme � l'AAPCS
	
//** Placez votre code l� ** // 	
// Ck = 72MHz, Tck = 1/72MHz = 0,0138�s
// T = 10 * Tck = 10*1/72MHz = 0,138�s
// x/72MHz = 100 000�s
// x = 7 200 0000
Timer_1234_Init_ff(TIM4, 7200000);
Active_IT_Debordement_Timer(TIM4, 2, timer_callback);
	
// configuration de PortB.1 (PB1) en sortie push-pull
GPIO_Configure(GPIOB, 1, OUTPUT, OUTPUT_PPULL);
	
	
	

//============================================================================	
	
	
while	(1)
	{
	}
}


/*
char FlagCligno;

void timer_callback(void)
{
	if (FlagCligno==1)
	{
		FlagCligno=0;
		GPIOB_Set(1);
	}
	else
	{
		FlagCligno=1;
		GPIOB_Clear(1);
	}
		
}
*/

