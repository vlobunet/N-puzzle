;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putchar.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:39:39 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:39:40 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_putchar

_ft_putchar:
	push	rbp
	mov		rbp, rsp

	push	rdi
	lea		rsi, [rsp]
	mov		rdi, 1
	mov		rdx, 1
	mov		rax, 0x2000004
	syscall

	mov		rsp, rbp
	pop		rbp
	ret
