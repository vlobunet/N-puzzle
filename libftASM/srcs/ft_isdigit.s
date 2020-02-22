;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:37:48 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:37:49 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;
section .text
	global _ft_isdigit

_ft_isdigit:
	push	rbp
	mov		rbp, rsp

	mov		rax, 0
	cmp		rdi, 48
	jl		_ret
	cmp		rdi, 57
	jg		_ret
	mov		rax, 1

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
