section .text
	global _ft_strchr

_ft_strchr:
	push	rbp
	mov		rbp, rsp

	mov		rdx, rsi
	mov		rax, 0
	jmp		_loop
_do:
	inc		rdi

_loop:
	mov		dh, BYTE [rdi]
	cmp		dh, dl
	je		_found
	test	dh, dh
	jz		_not_found
	jmp		_do

_found:
	mov		rax, rdi

_not_found:
	mov		rsp, rbp
	pop		rbp
	ret
