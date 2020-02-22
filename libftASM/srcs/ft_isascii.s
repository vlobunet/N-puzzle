section .text
	global _ft_isascii

_ft_isascii:
	push	rbp
	mov		rbp, rsp

	mov		rax, 0
	cmp		rdi, 0
	jl		_ret
	cmp		rdi, 127
	jg		_ret
	mov		rax, 1

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
