;Ian McPherson

INCLUDE Irvine32.inc
INCLUDE inputs.inc

.data

minMsg BYTE "Min: ", 0
maxMsg BYTE " Max: ", 0
medMsg BYTE " Median: ", 0
endMSG BYTE ".", 0dh, 0ah, 0

.code

;Finds the min
Min PROC

	INVOKE GetGrades
	mov esi, edi
	lodsb
	movzx eax, al
	ret

Min ENDP

;finds the max
Max PROC

	INVOKE GetGrades
	mov esi, edi
	add esi, 25
	sub esi, 1
	movzx eax, BYTE PTR [esi]
	ret

Max ENDP

;finds the median
Median PROC
	
	INVOKE GetGrades
	mov esi, edi
	mov eax, 25
	shr eax, 1
	add esi, eax
	movzx eax, BYTE PTR [esi]
	ret

Median ENDP

;outputs the min, max, and median
ToString PROC
	
	;displaying the min, max and median
	mov edx, offset minMSg
	call WriteString
	INVOKE Min
	call WriteDec

	mov edx, offset maxMsg
	call WriteString

	INVOKE Max
	call WriteDec

	mov edx, offset medMsg
	call WriteString

	INVOKE Median
	call WriteDec

	mov edx, offset endMsg
	call WriteString

	ret
ToString ENDP
END