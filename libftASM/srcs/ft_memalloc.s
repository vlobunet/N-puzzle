;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memalloc.s                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:38:08 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:38:08 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;
section .text
	global _ft_memalloc
	extern _ft_bzero
	extern _malloc

_ft_memalloc:
	push	rbp
	mov		rbp, rsp

	test	rdi, rdi
	mov		rax, 0
	jz		_ret
	push	rdi
	sub		rsp, 8
	call	_malloc
	test	rax, rax
	mov		rax, 0
	jz		_ret
	add		rsp, 8
	pop		rsi
	mov		rdi, rax
	push	rax
	sub		rsp, 8
	call _ft_bzero
	add		rsp, 8
	pop		rax

_ret:
	mov		rsp, rbp
	pop		rbp
	ret
