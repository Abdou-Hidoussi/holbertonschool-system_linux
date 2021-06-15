BITS 64

global asm_strncmp				; export to the gcc link

asm_strncmp:
	push rbp					; push the base
	mov rbp, rsp				; start new base

	mov R9, 0h					; set counter to 0
asm_loop:
	mov al, [rdi + R9]			; store the char of first argument + counter in al
	mov bl, [rsi + R9]			; store the char of second argument + counter in ab

	cmp R9, rdx                 ; compare counter to n
	je asm_end_count                  ; return if true

	cmp al, bl					; compare the char + counter of first and second argument
	je equal_char				; if equal jump to equal_char
	jl al_big					; if al is bigger jump to al_big
	jg bl_big					; if bl is bigger jump to bl_big

equal_char:
	cmp al, 0h					; compare al to Null
	je asm_end					; jmp to asm_end

	inc R9						; increace counter
	jmp asm_loop				; loop again

al_big:
	movzx R12, al
	movzx R13, bl
	sub R12, R13
	jmp asm_end					; jmp to asm_end

bl_big:
	movzx R12, al
	movzx R13, bl
	sub R12, R13
	jmp asm_end					; jmp to asm_end

asm_end:
	mov rax, R12
	mov rsp, rbp				; return to old base
	pop rbp						; pop to the call base
	ret

asm_end_count:
	mov rax, 0h
	mov rsp, rbp				; return to old base
	pop rbp						; pop to the call base
	ret
