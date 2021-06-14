BITS 64

global asm_strchr				; export to the gcc link

asm_strchr:
	push rbp					; push the base
	mov rbp, rsp				; start new base

asm_loop:
    mov al, [rdi]               ; set al to the address of rdi
    test al, al                 ; make flag
    jz null_end                 ; if flag zero then jump to null responce

    cmp [rdi], sil              ; compare char with the lower half of rsi
    je found_end                ; if equal then jump to found responce

    inc rdi                     ; advance in rdi
    jmp asm_loop                ; loop again
found_end:
	mov rax, rdi				; pass current rdi
	mov rsp, rbp				; return to old base
	pop rbp						; pop to the call base
	ret
null_end:
	mov rax, 0h				    ; pass null
	mov rsp, rbp				; return to old base
	pop rbp						; pop to the call base
	ret
