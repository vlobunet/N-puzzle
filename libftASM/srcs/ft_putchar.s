section .text
	global _ft_putchar

_ft_putchar:
	push	rbp
	mov		rbp, rsp

	push	rdi
	lea		rsi, [rsp]
	mov		rdi, 1
	mov		rdx, 1
	mov		rax, 0x2000004
	syscall

	mov		rsp, rbp
	pop		rbp
	ret
