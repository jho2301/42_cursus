# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    operations.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 20:26:04 by hjeon             #+#    #+#              #
#    Updated: 2020/04/13 20:26:04 by hjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


import sys


def operations(oprnd1, oprnd2):
    print(f'Sum: {oprnd1 + oprnd2}')
    print(f'Difference: {oprnd1 - oprnd2}')
    print(f'Product: {oprnd1 * oprnd2}')
    print(f'Quotient: {oprnd1 / oprnd2 if oprnd2 else "ERROR (div by zero)"}')
    print(f'Remainder: {oprnd1 % oprnd2 if oprnd2 else "ERROR (modulo by zero)"}')


if len(sys.argv) == 1:
    print("InputError: too few arguments")
elif 3 < len(sys.argv):
    print("InputError: too many arguments")
elif not sys.argv[1].isnumeric() or not sys.argv[2].isnumeric():
    print("InputError: only numbers")
else:
    operations(int(sys.argv[1]), int(sys.argv[2]))
