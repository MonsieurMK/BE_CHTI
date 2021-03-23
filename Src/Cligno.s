	PRESERVE8
	THUMB   
		

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly

	include DriverJeuLaser.inc

;Section RAM (read write):
	area    maram,data,readwrite
		
FlagCligno dcb 0
	EXPORT FlagCligno

	
; ===============================================================================================
	
	EXPORT timer_callback

		
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
	mov r0, #1
	ldr r1, =FlagCligno
	ldrb r2, [r1]
	cmp r2, #1
	bne	Sinon
	mov r2, #0
	strb r2, [r1]
	push {LR}
	BL GPIOB_Set
	pop {PC}
	B FinSi
Sinon
	mov r2, #1
	strb r2, [r1]
	push {LR}
	BL GPIOB_Clear
	pop {pc}
FinSi
	BX LR
	endp	
	END	