section	.text
	global		_ft_memdel
	extern		_free

_ft_memdel:
	push	rbp
	mov		rbp, rsp
	
	mov		rsi, rdi
	mov		qword [rdi], 0
	mov		rdi, [rsi]
	call	_free

_ret:
	leave
	ret