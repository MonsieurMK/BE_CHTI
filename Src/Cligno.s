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

timer_callback proc
	





		
		
	END	