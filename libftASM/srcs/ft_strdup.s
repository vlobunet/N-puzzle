section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_memcpy
	extern _malloc

_ft_strdup:
	push	rbp
	mov		rbp, rsp

	push	rdi
	sub		rsp, 8
	call	_ft_strlen
	add		rsp, 8
	inc		rax
	push	rax
	mov		rdi, rax
	call	_malloc
	pop		rdx
	pop		rsi
	test	rax, rax
	jz		_ret
	mov		rdi, rax
	call	_ft_memcpy

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
