;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_putchar_fd.s                                    :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:25:45 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:25:47 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

%define CALL(n)		0x2000000 | n
%define WRITE		4

global	_ft_putchar_fd

section	.text

_ft_putchar_fd:
	push	rdi

	mov		rdx, 1					; указываем размер массива
	mov		rdi, rsi				; [FD]
	mov		rsi, rsp				; [CHAR]
	mov		rax, CALL(WRITE)
	syscall

	pop		rax
	ret
