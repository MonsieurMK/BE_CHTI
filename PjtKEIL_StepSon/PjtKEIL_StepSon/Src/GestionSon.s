	PRESERVE8
	THUMB   
		

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly
	IMPORT Son
	IMPORT LongueurSon
	include DriverJeuLaser.inc

;Section RAM (read write):
	area    maram,data,readwrite
		
SortieSon dcw 0
	EXPORT SortieSon

indexTable dcd 0
	EXPORT indexTable
		
	EXPORT CallbackSon
	EXPORT StartSon
	
; ===============================================================================================
	
		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici	

; algo en c:
; static int i = 0;
; if (i < ValeurMax) {
; 	son = Son[i];
; 	son = (son + 32768) / 91;
; 	PWM_Set_Value(son);
; 	i++;
; }

CallbackSon proc ; -32768 = 0, 32767 = 719
	ldr		r3, =indexTable
	ldr		r1, [r3]	; r1 prend la valeur de l'index
	ldr		r12, =LongueurSon
	ldr		r12, [r12]	; on stocke la Longueur du son dans r12
	cmp		r1, r12
	bge		ValeurMax	; si index >= LongueurSon (donc si l'index dépasse la valeur max du tableau), on se rend au label ValeurMax et on sort donc de la fonction
	ldr		r2, =Son
	ldrsh	r0, [r2, r1, lsl #1]	; on stocke dans r0 la valeur du Son avec l'indice comme offset
	add		r0, #32768
	mov		r12, #91
	udiv	r0, r12   ; on ramène les valeurs de r0 dans la plage des valeurs possibles : [0, 719]
	add		r1, #1   ; on incrémente l'index
	str		r1, [r3]
	;ldr		r12, =SortieSon
	;strh	r0, [r12]
	push	{lr}
	bl		PWM_Set_Value_TIM3_Ch3
ValeurMax
	pop		{pc}
	endp
		
StartSon	proc
	; remise à zero de l'index
	ldr		r1, =indexTable
	mov		r2,	#0
	str		r2, [r1]
	bx		lr
	endp

	END
