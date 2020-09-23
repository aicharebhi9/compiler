
TITLE : Test

PILE SEGMENT stack
		100 DD dup (?)
PILE ENDS

DATA SEGMENT
	S DW 0
	Z DW 0
	E DW 0
	'b' DW 0
	G DW 0
	X DW 0
	't' DW 0
	J DW 0
	P DW 0
DATA ENDS

CODE SEGMENT
BEGIN:
		ASSUME SS: PILE, DS: DATA, CS: CODE
			Mov AX,DATA
			Mov DX,AX

END
