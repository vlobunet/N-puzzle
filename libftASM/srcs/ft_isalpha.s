section .text
	global _ft_isalpha

_ft_isalpha:
	push	rbp
	mov		rbp, rsp

	mov		rax, 0
	cmp		rdi, 65
	jl		_ko
	cmp		rdi, 91
	jl		_ok
	cmp		rdi, 97
	jl		_ko
	cmp		rdi, 122
	jg		_ko

_ok:
	mov		rax, 1

_ko:
	mov		rsp, rbp
	pop		rbp
	ret
