global _ft_strcpy

_ft_strcpy:
_loop:
	mov		rdx, [rsi]
	cmp		byte [rsi], 0
	jz		_end
	inc		rsi
	inc		rdx
	jmp		_loop
_end:
	mov rax, rdx
	ret