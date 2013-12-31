;Ian McPherson

INCLUDE Irvine32.inc
INCLUDE stats.inc


.data

student BYTE 4 Dup(?), 0dh, 0ah, 0

gradeA DWORD 0
gradeB DWORD 0
gradeC DWORD 0
gradeD DWORD 0
gradeF DWORD 0

;print messages
comma BYTE ", "
recievedA BYTE "Students that recieved A's:", 0dh, 0ah, 0
recievedB BYTE "Students that recieved B's:", 0dh, 0ah, 0
recievedC BYTE "Students that recieved C's:", 0dh, 0ah, 0
recievedD BYTE "Students that recieved D's:", 0dh, 0ah, 0
recievedF BYTE "Students that recieved F's:", 0dh, 0ah, 0
endMsg BYTE " ", 0dh, 0ah, 0

.code

; Scans through the grade array and increments 
; how many a's, b's, c's, d's, and f's there are.
AssignGrades PROC,
	gradeList:PTR DWORD

	mov esi, gradeList
	mov ecx, 25

	L1:
		lodsb

	L2: cmp al, 60
		jb goToF

	L3: cmp al, 70
		jb goToD

	L4: cmp al, 80
		jb goToC

	L5: cmp al, 90
		jb goToB

	L6: cmp al, 101
		jb goToA

	goToF:
		add gradeF, 1
		loop L1
		jmp L11

	goToD:
		add gradeD, 1
		loop L1
		

	goToC:
		add gradeC, 1
		loop L1
		

	goToB:
		add gradeB, 1
		loop L1
		

	goToA:
		add gradeA, 1
		loop L1
L11:
	
	mov eax, gradeA
	mov eax, gradeB
	ret
AssignGrades ENDP

;Scans the array and outputs each students name along with what grade they recieved.
ReportGrades PROC,
	nameList: PTR DWORD

	mov esi, nameList
	mov ecx, gradeF
	mov edx, offset recievedF
	call WriteString
	L1:
		lodsd
		mov DWORD PTR[student],eax
		mov edx, offset student
		call WriteString
		loop L1

	mov ecx, gradeD
	mov edx, offset recievedD
	call WriteString
	L2:
		lodsd
		mov DWORD PTR[student],eax
		mov edx, offset student
		call WriteString
		loop L2

	mov ecx, gradeC
	mov edx, offset recievedC
	call WriteString
	L3:
		lodsd
		mov DWORD PTR[student],eax
		mov edx, offset student
		call WriteString
		loop L3

	mov ecx, gradeB
	mov edx, offset recievedB
	call WriteString
	L4:
		lodsd
		mov DWORD PTR[student],eax
		mov edx, offset student
		call WriteString
		loop L4

	mov ecx, gradeA
	mov edx, offset recievedA
	call WriteString
	L5:
		lodsd
		mov DWORD PTR[student],eax
		mov edx, offset student
		call WriteString
		loop L5

; Calls the min, max and median
call ToString@0

	ret

ReportGrades ENDP
end