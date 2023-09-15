PrintChar macro chr  
          mov ah,02h
          mov dl,chr
          int 21h
          endm

PrintStr macro string 
         mov ah,09h
         mov dx,offset string
         int 21h
         endm

GetChar macro         
        mov ah,10h
        int 16h
        endm

SetMode macro mode   
        mov ah,00h
        mov al,mode
        int 10h
        endm

SetColor macro color  
         mov ah,0bh 
         mov bh,00h
         mov bl,color  
         int 10h
         endm

WrPixel macro col,row,color  
        mov ah,0ch
        mov bh,00h
        mov al,color
        mov cx,col
        mov dx,row
        int 10h
        endm

SetCursor macro row,col  
          mov dh,row
          mov dl,col
          mov bx,00h
          mov ah,02h
          int 10h
          endm

SetChar	macro Char,type,times  
	mov ah,09h
	mov al,Char
	mov bh,0
	mov bl,type
	mov cx,times
	int 10h
	endm

printstr13h macro str,atr,len,row,col,cursor_move  
	    mov ax,ds
	    mov es,ax
            mov bp,offset str
	    mov ah,13h
	    mov al,cursor_move
            mov bh,00
	    mov bl,atr	    
            mov cx,len
	    mov dh,row
	    mov dl,col
	    int 10h
	    endm

MUS_RESET macro			 	
	  mov ax,0000h
	  int 33h
	  endm

MUS_SHOW macro		
	 mov ax,0001h
	 int 33h
	 endm
			
MUS_HIND macro 		
	 mov ax,0002h
	 int 33h
	 endm
			
MUS_GET03 macro 	
	  mov ax,0003h
	  int 33h
	  endm
SET_MUS	macro	Col,Row	
	mov ax,0004h
	mov dx,Row
	mov cx,Col
	int 33h
	endm

MUS_range_x macro max,min	
	    mov ax,0007h
            mov dx,max
	    mov cx,min
	    int 33h
            endm

MUS_range_y macro max,min	
       	    mov ax,0008h
	    mov dx,max
	    mov cx,min
            int 33h
	    endm
color_get_mid	macro	col,row,color
		mov	cx,col
		mov	dx,row
		add	cx,5
		add	dx,5
		mov	bh,00h
		mov	ah,0Dh
		int	10h
		mov	color,al
		endm
color_get_down	macro	col,row,color
		mov	cx,col
		mov	dx,row
		add	cx,5
		add	dx,45
		mov	bh,00h
		mov	ah,0Dh
		int	10h
		mov	color,al
		endm
color_get_up	macro	col,row,color
		mov	cx,col
		mov	dx,row
		add	cx,5
		sub	dx,5
		mov	bh,00h
		mov	ah,0Dh
		int	10h
		mov	color,al
		endm
color_get_left	macro	col,row,color
		mov	cx,col
		mov	dx,row
		sub	cx,5
		add	dx,5
		mov	bh,00h
		mov	ah,0Dh
		int	10h
		mov	color,al
		endm
color_get_right	macro	col,row,color
		mov	cx,col
		mov	dx,row
		add	cx,25
		add	dx,5
		mov	bh,00h
		mov	ah,0Dh
		int	10h
		mov	color,al
		endm
random_number	macro	num
		mov	ah,2ch
		int	21h
		xor	ax,ax
		mov	al,dl
		mov	bl,7
		div	bl
		mov	num,ah
		xor	ax,ax
		endm
block	macro	col,row,color
	local	L2
	local	L3
	mov	dx,row
	mov	cx,col
	push	dx
L2:
	push	cx
	inc	dx
	inc	cx
L3:
	WrPixel	cx,dx,color
	inc	cx
	dec	data1
	cmp	data1,0
	jne	L3
	mov	data1,18
	pop	cx
	dec	data2
	cmp	data2,0
	jne	L2
	mov	data2,18
	pop	dx
	endm
Lblock	macro	col,row,color
	mov	cx,col
	mov	dx,row
	sub	cx,20
	block	cx,dx,color
	add	dx,20	
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	endm
Lblock1	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	add	dx,20
	block	cx,dx,color
	sub	dx,40
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	endm
Lblock2	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	sub	cx,20
	block	cx,dx,color
	add	cx,40
	block	cx,dx,color
	add	dx,20
	block	cx,dx,color
	endm
Lblock3	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	sub	dx,20
	block	cx,dx,color
	add	dx,40
	block	cx,dx,color
	sub	cx,20
	block	cx,dx,color
	endm
Lvblock	macro	col,row,color
	mov	cx,col
	mov	dx,row
	add	cx,20
	block	cx,dx,color
	add	dx,20
	block	cx,dx,color
	sub	cx,20
	block	cx,dx,color
	sub	cx,20
	block	cx,dx,color
	endm
Lvblock1	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	sub	dx,20
	block	cx,dx,color
	add	dx,40
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	endm
Lvblock2	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	sub	cx,40
	block	cx,dx,color
	add	dx,20
	block	cx,dx,color
	endm
Lvblock3	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	add	dx,20
	block	cx,dx,color
	sub	dx,40
	block	cx,dx,color
	sub	cx,20
	block	cx,dx,color
	endm
zblock	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	sub	cx,20
	add	dx,20
	block	cx,dx,color
	sub	cx,20
	block	cx,dx,color
	endm
zblock1	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	sub	dx,20
	block	cx,dx,color
	add	dx,20
	add	cx,20
	block	cx,dx,color
	add	dx,20
	block	cx,dx,color
	endm
zvblock	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	sub	cx,20
	block	cx,dx,color
	add	cx,20
	add	dx,20
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	endm
zvblock1	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	add	dx,20
	block	cx,dx,color
	sub	dx,20
	add	cx,20
	block	cx,dx,color
	sub	dx,20
	block	cx,dx,color
	endm
Iblock	macro	col,row,color
	mov	cx,col
	mov	dx,row
	add	dx,20
	sub	cx,40
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	endm
Iblock1	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	sub	dx,20
	block	cx,dx,color
	add	dx,40
	block	cx,dx,color
	add	dx,20
	block	cx,dx,color
	endm
Tblock	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	sub	cx,20
	add	dx,20
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	endm
Tblock1	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	sub	cx,20
	sub	dx,20
	block	cx,dx,color
	add	dx,40
	block	cx,dx,color
	endm
Tblock2	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	sub	cx,20
	block	cx,dx,color
	add	cx,40
	block	cx,dx,color
	sub	cx,20
	add	dx,20
	block	cx,dx,color
	endm
Tblock3	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	sub	cx,20
	block	cx,dx,color
	add	cx,20
	sub	dx,20
	block	cx,dx,color
	add	dx,40
	block	cx,dx,color
	endm
tenblock	macro	col,row,color
	mov	cx,col
	mov	dx,row
	block	cx,dx,color
	add	cx,20
	block	cx,dx,color
	add	dx,20
	block	cx,dx,color
	sub	cx,20
	block	cx,dx,color
	endm
