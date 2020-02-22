;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_putstr_fd.s                                     :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:28:53 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:28:54 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

%define CALL(n)		0x2000000 | n
%define WRITE		4

global	_ft_putstr_fd
extern	_ft_strlen

section	.text

_ft_putstr_fd:
	push	rdi
	call	_ft_strlen

	mov		rdx, rax
	mov		rdi, rsi
	pop		rsi
	mov		rax, CALL(WRITE)
	syscall

	ret
