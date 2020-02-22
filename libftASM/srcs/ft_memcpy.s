;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:39:11 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:39:12 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;
section .text
	global _ft_memcpy

_ft_memcpy:
	push	rbp
	mov		rbp, rsp

	mov		rax, rdi
	mov		rcx, rdx
	rep		movsb

	mov		rsp, rbp
	pop		rbp
	ret
