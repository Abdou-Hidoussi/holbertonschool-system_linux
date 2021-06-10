BITS 64

global asm_strncmp				; export to the gcc link

asm_strncmp:
	push rbp					; push the base 
	mov rbp, rsp				; start new base

	mov R8, 0h					; set return to 0
	mov R9, 0h					; set counter to 0
asm_loop:
	mov al, [rdi + R9]			; store the char of first argument + counter in al
	mov bl, [rsi + R9]			; store the char of second argument + counter in ab

    cmp R9, rdx                 ; compare counter to n
    je asm_end                  ; return if true

	cmp al, bl					; compare the char + counter of first and second argument
	je equal_char				; if equal jump to equal_char
	jl al_big					; if al is bigger jump to al_big
	jg bl_big					; if bl is bigger jump to bl_big

equal_char:
	cmp al, 0h					; compare al to Null
	mov R8, 0					; set return to 0 if true
	je asm_end					; jmp to asm_end

	inc R9						; increace counter
	jmp asm_loop				; loop again

al_big:
    inc R9                      ; increace counter
    neg R9                      ; negate counter
	mov R8, R9					; set return to - counter
	jmp asm_end					; jmp to asm_end

bl_big:
    inc R9                      ; increace counter
	mov R8, R9					; set return to counter
	jmp asm_end					; jmp to asm_end

asm_end:
	mov rax, R8					; pass the counter to the return register 
	mov rsp, rbp				; return to old base
	pop rbp						; pop to the call base
	ret