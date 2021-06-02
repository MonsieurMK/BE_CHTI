#include "DriverJeuLaser.h"
#include "GestionSon.h"

extern short int LeSignal[64]; 

int nbAppels = 0;
int x;
int tab[64];
short int dma_buf[64];

int scoreJoueurs[6];

void callbackSystick();

extern int indexTable;

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();

// Tck = 0,0138µs
// il nous faut 320kHz = 0,000003125s = 3,125µs
// 3,125 / 0,0138 = 227
Systick_Period_ff(360000);
Systick_Prio_IT( 3, callbackSystick );
SysTick_On;
SysTick_Enable_IT;
	
Init_TimingADC_ActiveADC_ff( ADC1, 72 );
Single_Channel_ADC( ADC1, 2 );
Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
Init_ADC1_DMA1( 0, dma_buf );
	
// initialisations Son
Timer_1234_Init_ff(TIM4, 6552);
Active_IT_Debordement_Timer(TIM4, 2, CallbackSon);

// initialisation PWM
PWM_Init_ff(TIM3, 3, 720);
GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);

//============================================================================	
	
while	(1)
	{
		
		
		int i = 0;
	}
}

void callbackSystick() {
	// appelé toutes les 5ms
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;
	for (int i = 0; i < 64; i++) {
			tab[i] = DFT_ModuleAuCarre(dma_buf, i);
			if (tab[i] > 335544 && nbAppels == 0) {
				if (i >= 17 && i <= 20) {
					scoreJoueurs[i - 17]++;
					StartSon();
				} else if (i == 23 || i == 24) {
					scoreJoueurs[i - 19]++;
					StartSon();
				}
			}
	}
	nbAppels = (nbAppels +1)%20;
}