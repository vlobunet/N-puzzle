section .text
	global _ft_isprint

_ft_isprint:
	push	rbp
	mov		rbp, rsp

	mov		rax, 0
	cmp		rdi, 32
	jl		_ret
	cmp		rdi, 126
	jg		_ret
	mov		rax, 1

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
