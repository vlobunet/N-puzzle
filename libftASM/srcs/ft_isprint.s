;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:37:56 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:37:57 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;
section .text
	global _ft_isprint

_ft_isprint:
	push	rbp
	mov		rbp, rsp

	mov		rax, 0
	cmp		rdi, 32
	jl		_ret
	cmp		rdi, 126
	jg		_ret
	mov		rax, 1

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
