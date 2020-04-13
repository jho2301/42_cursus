# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    count.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 19:45:14 by hjeon             #+#    #+#              #
#    Updated: 2020/04/13 19:45:14 by hjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


import sys
from string import punctuation


def text_analyzer(*text):
    upper, lower, punc, space, other = 0, 0, 0, 0, 0

    if not text:
        text = input("What is the text to analyse?\n")
    else:
        text = text[0]
    for letter in text:
        if letter.isupper():
            upper += 1
        elif letter.islower():
            lower += 1
        elif letter.isspace():
            space += 1
        elif letter in punctuation:
            punc += 1
        else:
            other += 1
    print(\
f'''The text contains {upper + lower + punc + space + other} characters:

- {upper} upper letters

- {lower} lower letters

- {punc} punctuation marks

- {space} spaces''')
