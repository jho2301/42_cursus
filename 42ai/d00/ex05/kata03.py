# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    kata03.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 22:01:17 by hjeon             #+#    #+#              #
#    Updated: 2020/04/13 22:01:17 by hjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

phrase = "The right format"
padding_len = 42 - len(phrase)
padding_str = '-' * padding_len
print(f'{padding_str}{phrase}')

