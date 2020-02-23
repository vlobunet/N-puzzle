;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strncpy.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:44:35 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:44:35 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_strncpy

_fill_zeros:
	mov		BYTE [rcx], 0
	inc		rcx
	dec		rdx
	test	rdx, rdx
	jnz		_fill_zeros
	jmp		_ret


_ft_strncpy:
	push	rbp
	mov		rbp, rsp

	mov		rcx, rdi
	jmp		_loop

_do:
	mov		BYTE [rcx], al
	inc		rcx
	inc		rsi
	dec		rdx

_loop:
	test	rdx, rdx
	jz		_ret
	mov		al, BYTE [rsi]
	test	al, al
	jz		_fill_zeros
	jmp		_do

_ret:
	mov		rax, rdi

	mov		rsp, rbp
	pop		rbp
	ret
