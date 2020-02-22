;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strchr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/22 15:43:08 by bmisyurk          #+#    #+#              ;
;    Updated: 2020/02/22 15:43:08 by bmisyurk         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global		_ft_strchr

extern		_ft_strlen

section		.text

_ft_strchr:
	cmp		rdi, 0
	je		end
	cmp 	byte[rdi], 0
	je 		end
	cmp		byte [rdi], sil
	je		solution
	inc 	rdi
	jmp 	_ft_strchr

end:
	mov		rax, 0
	ret

solution:
	mov 	rax, rdi
	ret
	