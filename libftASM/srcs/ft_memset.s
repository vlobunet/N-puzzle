;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:39:16 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:39:17 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_memset

_ft_memset:
	push	rbp
	mov		rbp, rsp

	mov		rcx, rdx
	mov		rdx, rdi
	mov		ax, si
	rep		stosb
	mov		rax, rdx

	mov		rsp, rbp
	pop		rbp
	ret
