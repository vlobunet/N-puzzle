section .text
	global _ft_strcat
	extern _ft_strlen
	extern _ft_memcpy

_ft_strcat:
	push	rbp
	mov		rbp, rsp

	push	rdi
	push	rsi
	mov		rdi, rsi
	call	_ft_strlen
	mov		rdx, rax
	inc		rdx
	mov		rdi, [rsp + 8]
	call	_ft_strlen
	pop		rsi
	mov		rdi, [rsp]
	add		rdi, rax
	sub		rsp, 8
	call	_ft_memcpy
	add		rsp, 8
	pop		rax

	mov		rsp, rbp
	pop		rbp
	ret
