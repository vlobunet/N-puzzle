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
		cmp		rdi, 0
		je		exit
		dec		rsi
		cmp 	rsi, 0
		jl		exit
		mov		byte[rdi + rsi], 0
		jmp		_ft_bzero
exit:
	ret