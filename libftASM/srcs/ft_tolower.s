;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:44:51 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:44:52 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_tolower

_ft_tolower:
	push	rbp
	mov		rbp, rsp

	mov		rax, rdi
	cmp		rdi, 65
	jl		_ret
	cmp		rdi, 90
	jg		_ret
	add		rax, 32

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
