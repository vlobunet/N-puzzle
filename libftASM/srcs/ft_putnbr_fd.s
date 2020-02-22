;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_putnbr_fd.s                                     :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:25:53 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:25:56 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

%define CALL(n)		0x2000000 | n
%define WRITE		4

global  _ft_putnbr_fd
extern  _ft_putchar_fd

section .data
	neg_sign: db "-"
	special_number: db "-2147483648"

section .text

_ft_putnbr_fd:
	mov r8, rsi

_main:
	cmp		edi, -2147483648	; сравниваем с минимальным интеджером
	je		_print_special		; переходим на вывод специального числа
	cmp		edi, 0				; если отрицательное
	jl		_set_neg			; инвертируем число и выводим -
	cmp		edi, 10
	jl		_is_one_dec
	mov		eax, edi
	xor		edx, edx			; обнуляем остаток
	mov		rcx, 10				; делитель
	div		ecx					; делим целое на 10
	push	rdx					; остаток заносив в стек
	mov		rdi, rax
	call	_main
	pop		rdx
	mov		rax, CALL(WRITE)
	mov		rdi, r8
	add		edx, 48
	push	rdx
	mov		rsi, rsp
	pop		rdx
	mov		rdx, 1
	syscall
	ret

_is_one_dec:
	mov rax, CALL(WRITE)
	add rdi, 48
	push rdi
	mov		rdi, r8
	mov rsi, rsp
	mov rdx, 1
	syscall
	pop rdi
	ret

_print_special:
	mov rax, CALL(WRITE)
	mov rdi, r8
	lea rsi, [rel special_number]
	mov rdx, 11
	syscall
	ret

_set_neg:
	push	rdi
	mov		rax, 0x2000004
	mov		rdi, r8
	lea		rsi, [rel neg_sign]
	mov		rdx, 1
	syscall
	pop		rdi
	neg 	edi
	call _main
	ret
