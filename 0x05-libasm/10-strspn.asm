BITS 64

global asm_strspn

asm_strspn:
	push rbp
	mov rbp, rsp

	mov rax, 0h
	mov r8, 0h
	mov r9, 0h

asm_loop:
	mov bl, [rdi + R9]

	test bl, bl
	jz asm_end

	mov R8, 0h

asm_loop_1:
	mov cl, [rsi + R8]

	test cl, cl
	jz asm_end

	cmp bl, cl
	je equal

	inc R8
	jmp asm_loop_1

equal:
    inc R9
	inc rax
	jmp asm_loop

asm_end:
	mov rsp, rbp
	pop rbp
	ret
