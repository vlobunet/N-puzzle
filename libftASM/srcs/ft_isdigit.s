section .text
	global _ft_isdigit

_ft_isdigit:
	push	rbp
	mov		rbp, rsp

	mov		rax, 0
	cmp		rdi, 48
	jl		_ret
	cmp		rdi, 57
	jg		_ret
	mov		rax, 1

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
