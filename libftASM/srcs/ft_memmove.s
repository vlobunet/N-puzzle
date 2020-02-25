section .text
	global _ft_memmove
	extern _ft_memcpy
	extern _ft_memrcpy

_ft_memmove:
	cmp rdi, rsi
	je memrcpy
	jmp memcpy

memcpy:
	call _ft_memcpy
	ret

memrcpy:
	call _ft_memrcpy
	ret