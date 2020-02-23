section	.text

global	_ft_strsplit
extern	_malloc

_ft_strsplit:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 32
	mov		al, sil
	mov		rsi, rdi
	xor		rdx, rdx
	xor		r8, r8

.calc_size:
	mov		rcx, -1
	rep		scasb
	dec		rdi
	cmp		byte [rdi], 0
	je		.alloc_array
	inc		rdx
.count_chars:
	inc		r8
	cmp		byte [rdi], 0
	je		.alloc_array
	scasb
	jne		.count_chars
	jmp		.calc_size

.alloc_array:
	inc		rdx
	shl		rdx, 3
	add		r8, rdx
	mov		rdi, r8
	mov		[rbp - 8], rdx
	mov		[rbp - 16], rsi
	mov		[rbp - 24], al
	call	_malloc
	test	rax, rax
	je		.done
	mov		r8, rax
	mov		rdx, rax
	mov		rdi, [rbp - 8]
	add		rdi, rax
	mov		rsi, [rbp - 16]
	mov		al, [rbp - 24]

.build_array:
	xchg	rdi, rsi
	mov		rcx, -1
	rep		scasb
	dec		rdi
	xchg	rdi, rsi
	cmp		byte [rsi], 0
	je		.terminate
	mov		[rdx], rdi
	add		rdx, 8

.copy_chars:
	movsb
	cmp		byte [rsi], 0
	je		.terminate
	cmp		[rsi], al
	jne		.copy_chars
	mov		byte [rdi], 0
	inc		rdi
	jmp		.build_array

.terminate:
	mov		qword [rdx], 0
	mov		byte [rdi], 0
	mov		rax, r8

.done:
	add		rsp, 32
	pop		rbp
	ret