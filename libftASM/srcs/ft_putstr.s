;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putstr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:42:25 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:42:27 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;
section .text

global _ft_putstr
extern _ft_strlen

_ft_putstr:
	push	rbp
	mov		rbp, rsp

	mov		rsi, rdi
	call	_ft_strlen
	mov		rdx, rax
	mov		rdi, 1
	mov		rax, 0x2000004
	syscall

	mov		rsp, rbp
	pop		rbp
	ret
