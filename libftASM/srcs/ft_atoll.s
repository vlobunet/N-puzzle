section .text
	global _ft_atoll

_sign_negative:
	xor		rdx, rdx
_sign:
	inc		rdi
	mov		cl, BYTE [rdi]
	jmp		_loop

_ft_atoll:
	push	rbp
	mov		rbp, rsp
	mov		rax, 0
	mov		rdx, 1
	mov		rcx, 0
	jmp		_space_loop

_is_spaces:
	inc		rdi

_space_loop:
	mov		cl, BYTE [rdi]
	cmp		cl, 32
	je		_is_spaces
	cmp		cl, 9
	jl		_is_sign
	cmp		cl, 13
	jg		_is_sign
	jmp		_is_spaces

_is_sign:

	cmp		cl, 0x2b
	je		_sign
	cmp		cl, 0x2d
	je		_sign_negative
	jmp		_loop

_is_digits:
	inc		rdi
	mov		cl, BYTE [rdi]

_loop:
	cmp		cl, 48
	jl		_ret
	cmp		cl, 57
	jg		_ret
	imul	rax, 10
	sub		cl, 48
	add		rax, rcx
	jmp		_is_digits

_ret:

	test	rdx, rdx
	jnz		_exit
	neg		rax

_exit:
	mov		rsp, rbp
	pop		rbp
	ret
