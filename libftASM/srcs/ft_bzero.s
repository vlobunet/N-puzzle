;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:36:41 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:36:42 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;
section .text
	global _ft_bzero

_ft_bzero:
	push	rbp
	mov		rbp, rsp

	mov		rcx, rsi
	xor		al, al
	rep		stosb

	mov		rsp, rbp
	pop		rbp
	ret
