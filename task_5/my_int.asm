Title MY_INT			; ��������� ����������
PUBLIC MY_INT

.Model Small
.STACK 100h			; 100h ��� ����

.DATA
mes db "color interrupt $"
color db

.CODE
MY_INT PROC FAR
	mov color, dl
	push ax 		
	push bx
	push dx			; > ��������� ��� ���������� �������� � ����
	push cx
	
	mov ah,09h		
	mov bl,color
	mov cx, 6
	int 10h			; ������ ����
	lea dx,mes 		
 	int 21h			; > ����� ���������
	mov dl, 10
	mov ah, 02h
	int 21h

	pop dx 			
	pop ax			;/  ��������������� ��������
	pop bx
	pop cx
	inc bx

	mov al,20h
	out 20h,al
	IRET
MY_INT ENDP
end