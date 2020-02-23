;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:40:21 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:40:22 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .data

default_null:
	.string db "(null)"
	.len equ $ - default_null.string

section .text
	global _ft_puts
	extern _ft_strlen
	extern _ft_putchar

_null:
	lea		rsi, [rel default_null.string]
	mov		rdx, default_null.len
	jmp		_write

_ft_puts:
	push	rbp
	mov		rbp, rsp

	test	rdi, rdi
	jz		_null
	push	rdi
	sub		rsp, 8
	call	_ft_strlen
	mov		rdx, rax
	add		rsp, 8
	pop		rsi

_write:
	mov		rdi, 1
	mov		rax, 0x2000004
	syscall
	push	rax
	sub		rsp, 8

	mov		rdi, 10
	call	_ft_putchar

	add		rsp, 8
	pop		rax
	inc		rax

	mov		rsp, rbp
	pop		rbp
	ret
