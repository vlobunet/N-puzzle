section .text
	
global	_ft_strdel
extern	_ft_memdel

_ft_strdel:
	push	rbp
	mov		rbp, rsp

	call	_ft_memdel

_ret:
	leave
	ret