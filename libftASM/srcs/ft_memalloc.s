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

section	.text

global _ft_memalloc
extern _ft_bzero
extern _malloc

_ft_memalloc:
	push	rdi
	call	_malloc
	cmp		rax, 0
	je		_ret
	pop		rdi
	push	rdi
	push	rax
	mov		rsi, rdi
	mov		rdi, rax
	call	_ft_bzero
	pop		rax

_ret:
	pop		rdi
	ret