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
			push {lr}
		ldr r1, =FlagCligno 
		ldr r2, [r1] 
		cmp r2, #1
		beq equal 
		mov r2, #1  
		str r2, [r1]
		mov r0, #1
		bl GPIOB_Clear
out		pop {pc}
equal                     
		mov r2, #0
		str r2, [r1]
		mov r0, #1
		bl GPIOB_Set
		b out

fin		
		endp
	





		
		
	END	