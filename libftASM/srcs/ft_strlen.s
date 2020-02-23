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
    mov rcx, -1
    mov al, 0
    cld
    repne scasb
    not rcx
    dec rcx
    mov rax, rcx
    ret