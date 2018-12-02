Title MY_INT			; процедура прерывания
PUBLIC MY_INT

.Model Small
.STACK 100h			; 100h под стек

.DATA
mes db "color interrupt $"
color db

.CODE
MY_INT PROC FAR
	mov color, dl
	push ax 		
	push bx
	push dx			; > сохраняем все изменяемые регистры в стек
	push cx
	
	mov ah,09h		
	mov bl,color
	mov cx, 6
	int 10h			; задаем цвет
	lea dx,mes 		
 	int 21h			; > вывод сообщения
	mov dl, 10
	mov ah, 02h
	int 21h

	pop dx 			
	pop ax			;/  восстанавливаем регистры
	pop bx
	pop cx
	inc bx

	mov al,20h
	out 20h,al
	IRET
MY_INT ENDP
end