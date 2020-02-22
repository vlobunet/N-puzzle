section	.text
	global		_ft_memdel
	extern		_free

_ft_memdel:
	push		rbp						; stack frame init
	mov			rbp, rsp				;
	
	mov rsi, rdi						; store the pointer into rsi
	mov qword [rdi], 0					; set the pointer to NULL

	mov rdi, [rsi]						; load the pointer to rdi
	call _free							; free the pointer

	exit_process:						; exit marker
		leave							; leave stack frame
		ret								; return