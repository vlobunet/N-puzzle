section .text
	global _ft_toupper

_ft_toupper:
	push	rbp
	mov		rbp, rsp

	mov		rax, rdi
	cmp		rdi, 97
	jl		_ret
	cmp		rdi, 122
	jg		_ret
	sub		rax, 32

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
