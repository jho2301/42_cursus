# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    exec.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 19:33:52 by hjeon             #+#    #+#              #
#    Updated: 2020/04/13 19:33:52 by hjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


import sys


def reverse_case(word):
    reversed_word = ''
    for i in range(len(word)):
        if word[i].islower():
            reversed_word += word[i].upper()
        elif word[i].isupper():
            reversed_word += word[i].lower()
        else:
            reversed_word += word[i]
    return reversed_word


def print_rev_alpha(words):
    words_splitted = []
    result = []

    for word in words:
        words_splitted += word.split()
    words_splitted.reverse()
    for word in words_splitted:
        word = list(reverse_case(word))
        word.reverse()
        result.append(''.join(word))
    print(' '.join(result))


if 1 < len(sys.argv):
    print_rev_alpha(sys.argv[1:])
