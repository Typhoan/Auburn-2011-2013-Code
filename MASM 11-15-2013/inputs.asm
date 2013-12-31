;Ian McPherson
INCLUDE Irvine32.inc

.data
names byte "00S1", "00S2", "00S3", "00S4", "00S5", "00S6", "00S7", "00S8", "00S9", "0S10", "0S11", "0S12", "0S13", "0S14", "0S15", "0S16", "0S17", "0S18", "0S19", "0S20", "0S21", "0S22", "0S23", "0S24", "0S25"
grades byte 40, 60, 95, 84, 74, 64, 81, 98, 100, 80, 64, 71, 45, 83, 74, 76, 62, 87, 45, 50, 67, 85, 97, 96, 54

.code
;sorts the two array, keeps the grades with the students
BubbleSort PROC

	mov ecx, 24

	L1: push ecx
		mov esi, offset grades
		mov edi, offset names

	L2: mov al,[esi]
		cmp [esi+1],al
		jg L3

		xchg al, [esi+1]
		mov [esi], al

		mov ebx, DWORD PTR [edi]
		xchg ebx, DWORD PTR [edi+4]
		mov [edi], ebx

	L3: inc esi
		add edi, 4
		loop L2

		pop ecx
		loop L1
	ret
BubbleSort ENDP

;returns array of student names
GetNames PROC
	mov edi, offset names
	ret

GetNames ENDP

;returns array of student grades
GetGrades PROC

	mov edi, offset grades
	ret

GetGrades ENDP
END