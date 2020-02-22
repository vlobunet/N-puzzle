section .text					;
	global		_ft_strdel		;
	extern		_ft_memdel		;

_ft_strdel:						;
	push		rbp				; stack frame init
	mov			rbp, rsp		;

	call		_ft_memdel		;

	exit_process:				; exit_process marker
		leave					; leaving stack frame
		ret