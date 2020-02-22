;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:44:58 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:44:58 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;
section .text
	global _ft_toupper

_ft_toupper:
	push	rbp
	mov		rbp, rsp

	mov		rax, rdi
	cmp		rdi, 97
	jl		_ret
	cmp		rdi, 122
	jg		_ret
	sub		rax, 32

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
