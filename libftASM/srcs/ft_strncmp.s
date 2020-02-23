;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strncmp.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:43:34 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:43:34 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_strncmp

_return_greater:
	mov		rax, -1
	jmp		_ret

_return_less:
	mov		rax, 1
	jmp		_ret

_ft_strncmp:
	push	rbp
	mov		rbp, rsp

	mov		rax, 0
	jmp		_loop

_do:
	inc		rdi
	inc		rsi
	dec		rdx

_loop:
	test	rdx, rdx
	jz		_ret
	mov		ch, BYTE [rdi]
	mov		cl, BYTE [rsi]
	test	cx, cx
	jz		_ret
	cmp		cl, ch
	je		_do
	jg		_return_greater
	jl		_return_less
	jmp		_do

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
