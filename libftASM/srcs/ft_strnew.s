;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_strnew.s                                        :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 16:23:36 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 16:23:38 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

section	.text
	extern	_ft_memalloc
	global	_ft_strnew

_ft_strnew:
	push rdi
	inc	rdi
	call	_ft_memalloc
	pop rdi
	ret