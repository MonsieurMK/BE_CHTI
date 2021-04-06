	PRESERVE8
	THUMB   
		

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly

include DriverJeuLaser.inc

;Section RAM (read write):
	area    maram,data,readwrite
		
FlagCligno dcd 0
	EXPORT FlagCligno

	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici

;if (FlagCligno==1)
;{
;	FlagCligno=0;
;	GPIOB_Set(1);
;}
;else
;{
;	FlagCligno=1;
;	GPIOB_Clear(1);
;}

timer_callback proc
	ldr r0, =FlagCligno
	cmp r0, #1
	
	





		
		
	END	