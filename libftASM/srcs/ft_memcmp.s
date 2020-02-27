section .text
	global _ft_memcmp

_ft_memcmp:
	cmp	rdx, 0x0
	je ret2
	mov r8b, byte[rdi]
	cmp r8b, byte[rsi]
	jne _ret
	inc rdi
	inc rsi
	dec rdx
	jmp _ft_memcmp

ret2:
	mov rax, 0x0
	ret

_ret:
	movzx	rax, r8b
	movzx 	rcx, byte[rsi]
	sub		rax, rcx
	ret
