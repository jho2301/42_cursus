# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filterwords.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 23:57:29 by hjeon             #+#    #+#              #
#    Updated: 2020/04/13 23:57:29 by hjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


from string import punctuation
import sys


def filter_words(target_str: str, standard: int):
    result = ''
    result_list = []
    for letter in target_str:
        if letter not in punctuation:
            result += letter
    for word in result.split():
        if standard < len(word):
            result_list.append(word)
    print(result_list)


if len(sys.argv) != 3 or not sys.argv[2].isnumeric():
    print('ERROR')
else:
    filter_words(sys.argv[1], int(sys.argv[2]))
