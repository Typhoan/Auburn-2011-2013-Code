;Ian McPherson

INCLUDE Irvine32.inc
INCLUDE grading.inc
INCLUDE inputs.inc

.data
nameList DWORD ?
gradeList DWORD ?
gradeString DWORD ?

.code
;runs the program
main PROC
	
	call BubbleSort@0
	call GetNames@0
	mov nameList, edi
	
	call GetGrades@0
	mov gradeList, edi
	
	INVOKE AssignGrades,
		gradeList

	INVOKE ReportGrades,
		nameList

	exit
main ENDP
END main