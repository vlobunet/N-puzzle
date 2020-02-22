;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strchr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:43:08 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:43:08 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;
section .text
	global _ft_strchr

_ft_strchr:
	push	rbp
	mov		rbp, rsp

	mov		rdx, rsi
	mov		rax, 0
	jmp		_loop
_do:
	inc		rdi

_loop:
	mov		dh, BYTE [rdi]
	cmp		dh, dl
	je		_found
	test	dh, dh
	jz		_not_found
	jmp		_do

_found:
	mov		rax, rdi

_not_found:
	mov		rsp, rbp
	pop		rbp
	ret
