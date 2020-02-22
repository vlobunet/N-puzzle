section .text
	global _ft_strlen

_ft_strlen:
	push	rbp
	mov		rbp, rsp

	xor		al, al
	xor		rcx, rcx
	not		rcx
	cld
	repnz	scasb
	not		rcx
	dec		rcx
	mov		rax, rcx

	mov		rsp, rbp
	pop		rbp
	ret
