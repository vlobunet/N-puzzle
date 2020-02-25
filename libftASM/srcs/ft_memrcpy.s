section .text
	global _ft_memrcpy

_ft_memrcpy:
	lea rdi, [rel rdi+rdx-1]
	lea rsi, [rel rsi+rdx-1]
	xchg rcx, rdx
	std
	rep movsb
	mov rax, rdi
	ret