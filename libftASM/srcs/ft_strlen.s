;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:43:26 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:43:26 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;
section .text
	global _ft_strlen

_ft_strlen:
	push	rbp
	mov		rbp, rsp

	xor		al, al
	xor		rcx, rcx
	not		rcx
	cld
	repnz	scasb
	not		rcx
	dec		rcx
	mov		rax, rcx

	mov		rsp, rbp
	pop		rbp
	ret
