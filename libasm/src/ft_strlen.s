# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/14 20:44:12 by hjeon             #+#    #+#              #
#    Updated: 2020/06/14 20:44:13 by hjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

segment .text

global ft_strlen

ft_strlen:
	mov rax, 0
compare:
	cmp byte [rdi+rax], 0
	jne inc_cnt
	ret
inc_cnt:
	inc rax
	jmp compare
