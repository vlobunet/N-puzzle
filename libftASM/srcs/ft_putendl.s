;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_putendl.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 15:24:27 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 15:24:29 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

%define CALL(n)		0x2000000 | n
%define WRITE		4

extern _ft_puts

section .text

global _ft_putendl

_ft_putendl:
	push	rbp             	; сохраням в стек адрес возврата
	mov		rbp, rsp        	; вершина стека
	push	rdi             	; сохраняем значение rdi

	call _ft_puts

	mov		rdx, 1				; указываем размер массива
	mov		rdi, rsi			; [FD]
	mov		rsi, '\n'			; [CHAR]
	mov		rax, CALL(WRITE)
	syscall

	pop		rdi					; возвращаем из стека указатель
	mov		rsp, rbp			; восстанавливаем адрес возврата
	pop		rbp
	ret
