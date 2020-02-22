section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	push	rbp
	mov		rbp, rsp
	call	_ft_isdigit

	test	rax, 1
	jnz		_ret
	call	_ft_isalpha

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
