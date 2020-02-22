section .text
	global _ft_memset

_ft_memset:
	push	rbp
	mov		rbp, rsp

	mov		rcx, rdx
	mov		rdx, rdi
	mov		ax, si
	rep		stosb
	mov		rax, rdx

	mov		rsp, rbp
	pop		rbp
	ret
