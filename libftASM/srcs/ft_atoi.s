section .text
	global _ft_atoi


_sign_negative:
	xor		edx, edx

_sign:
	inc		rdi
	mov		cl, BYTE [rdi]
	jmp		_loop

_ft_atoi:
	push	rbp
	mov		rbp, rsp
	mov		rax, 0
	mov		edx, 1
	mov		ecx, 0
	jmp		_spaces

_is_space:
	inc		rdi

_spaces:
	mov		cl, BYTE [rdi]
	cmp		cl, 32
	je		_is_space
	cmp		cl, 9
	jl		_is_sign
	cmp		cl, 13
	jg		_is_sign
	jmp		_is_space

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
	imul	eax, 10
	sub		cl, 48
	add		eax, ecx
	jmp		_is_digits

_ret:
	test	edx, edx
	jnz		_exit
	neg		eax

_exit:
	mov		rsp, rbp
	pop		rbp
	ret
