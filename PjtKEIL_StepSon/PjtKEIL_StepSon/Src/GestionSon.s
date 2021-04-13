	PRESERVE8
	THUMB   
		

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly
	IMPORT Son
	IMPORT LongueurSon

;Section RAM (read write):
	area    maram,data,readwrite
		
SortieSon dcw 0
	EXPORT SortieSon

indexTable dcd 0
	EXPORT indexTable
		
	EXPORT CallbackSon
	
; ===============================================================================================
	
		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		

CallbackSon proc ; -32768 = 0, 32767 = 719
	ldr		r0, =indexTable
	ldr		r1, [r0]
	ldr		r12, =LongueurSon
	ldr		r12, [r12]
	cmp		r1, r12
	bge		ValeurMax
	ldr		r2, =Son
	ldrsh	r3, [r2, r1, lsl #1]
	add		r3, #32768
	mov		r12, #91
	udiv	r3, r12
	add		r1, #1
	str		r1, [r0]
	ldr		r0, =SortieSon
	strh	r3, [r0]
ValeurMax
	bx lr
	endp

	END