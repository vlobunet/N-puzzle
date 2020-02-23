section .text
	global _ft_memcpy

_ft_memcpy:
	push	rbp
	mov		rbp, rsp

	mov		rax, rdi
	mov		rcx, rdx
	rep		movsb

	mov		rsp, rbp
	pop		rbp
	ret
