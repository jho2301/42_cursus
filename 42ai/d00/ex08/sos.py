# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sos.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/14 00:24:20 by hjeon             #+#    #+#              #
#    Updated: 2020/04/14 00:24:20 by hjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


import sys


def morsify(word):
    morse_word = []
    for letter in word:
        if letter == 'A':
            morse_word.append('.-');
        elif letter == 'B':
            morse_word.append('-...');
        elif letter == 'C':
            morse_word.append('-.-.');
        elif letter == 'D':
            morse_word.append('-..');
        elif letter == 'E':
            morse_word.append('.');
        elif letter == 'F':
            morse_word.append('..-.');
        elif letter == 'G':
            morse_word.append('--.');
        elif letter == 'H':
            morse_word.append('....');
        elif letter == 'I':
            morse_word.append('..');
        elif letter == 'J':
            morse_word.append('.---');
        elif letter == 'K':
            morse_word.append('-.-');
        elif letter == 'L':
            morse_word.append('.-..');
        elif letter == 'M':
            morse_word.append('--');
        elif letter == 'N':
            morse_word.append('-.');
        elif letter == 'O':
            morse_word.append('---');
        elif letter == 'P':
            morse_word.append('.--.');
        elif letter == 'Q':
            morse_word.append('--.-');
        elif letter == 'R':
            morse_word.append('.-.');
        elif letter == 'S':
            morse_word.append('...');
        elif letter == 'T':
            morse_word.append('-');
        elif letter == 'U':
            morse_word.append('..-');
        elif letter == 'V':
            morse_word.append('...-');
        elif letter == 'W':
            morse_word.append('.--');
        elif letter == 'X':
            morse_word.append('-..-');
        elif letter == 'Y':
            morse_word.append('-.--');
        elif letter == 'Z':
            morse_word.append('--..');
        elif letter == '1':
            morse_word.append('.----');
        elif letter == '2':
            morse_word.append('..---');
        elif letter == '3':
            morse_word.append('...--');
        elif letter == '4':
            morse_word.append('....-');
        elif letter == '5':
            morse_word.append('.....');
        elif letter == '6':
            morse_word.append('-....');
        elif letter == '7':
            morse_word.append('--...');
        elif letter == '8':
            morse_word.append('---..');
        elif letter == '9':
            morse_word.append('----.');
        elif letter == '0':
            morse_word.append('-----');
    result = ' '.join(morse_word)
    return result


words = []
morse_words = []
for argv in sys.argv[1:]:
    words += argv.split()
for word in words:
    if word.isalnum():
        morse_words.append(morsify(word.upper()))
    else:
        print('ERROR')
        exit()
result = ' / '.join(morse_words)
if result:
    print(result)
