section .text
	global _ft_tolower

_ft_tolower:
	push	rbp
	mov		rbp, rsp

	mov		rax, rdi
	cmp		rdi, 65
	jl		_ret
	cmp		rdi, 90
	jg		_ret
	add		rax, 32

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
