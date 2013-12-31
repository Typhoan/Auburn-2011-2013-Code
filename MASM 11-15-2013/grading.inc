EXTERN AssignGrades@4:PROC
EXTERN ReportGrades@4:PROC

AssignGrades PROTO,
	gradeList: PTR DWORD

ReportGrades PROTO,
	nameList: PTR DWORD