# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    whois.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 19:34:01 by hjeon             #+#    #+#              #
#    Updated: 2020/04/13 19:34:01 by hjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


import sys

def whois(argv):
    if len(argv) != 2 or not argv[1].isnumeric():
        print("ERROR")
    elif int(argv[1]) == 0:
        print("I'm Zero.")
    elif int(argv[1]) % 2 == 0:
        print("I'm Even.")
    else:
        print("I'm Odd.")

whois(sys.argv)
