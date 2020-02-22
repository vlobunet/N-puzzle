%define BUF_SIZE           1024

section .text
	global _ft_cat

_ft_cat:
	push	bp
	mov		rbp, rsp

	push	rbx
	sub		rsp, 8
	sub		rsp, BUF_SIZE
	mov		rbx, rdi

_loop:

	mov		rdi, rbx
	mov		rsi, rsp
	mov		rdx, BUF_SIZE - 1
	mov		rax, 0x2000003

	jc		_exit
	cmp		rax, 0
	jle		_exit


	mov		rdi, 1
	mov		rsi, rsp
	mov		rdx, rax
	mov		rax, 0x2000004
	syscall
	jmp		_loop

_exit:
	add		rsp, BUF_SIZE
	add		rsp, 8
	pop		rbx

	mov		rsp, rbp
	pop		rbp
	ret
