;ft_strjoin(const char *s1, const char *s2);

global _ft_strjoin
extern _ft_strdup
extern _ft_strlen
extern _ft_strnew
extern _ft_strcat

section .text

_ft_strjoin:
			cmp rdi, 0
			je s1null
			cmp rsi, 0
			je s2null
			push rdi
			call _ft_strlen
			mov rbx, rax
			push rsi
			mov rdi, rsi
			call _ft_strlen
			add rax, rbx
			mov rdi, rax
			call _ft_strnew
			cmp rax, 0
			je _fail
			mov rdi, rax
			pop rbx
			pop rsi
			push rbx
			call _ft_strcat
			pop rsi
			call _ft_strcat
			ret

s1null:
		cmp rsi, 0
		je _fail
		mov rdi, rsi
		call _ft_strdup
		ret

s2null:
		cmp rdi, 0
		je _fail
		call _ft_strdup
		ret

_fail:
		mov rax, 0
		ret