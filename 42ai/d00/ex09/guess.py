# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    guess.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/14 00:58:16 by hjeon             #+#    #+#              #
#    Updated: 2020/04/14 00:58:16 by hjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random

answer = random.randint(1, 99)
attempt = 0

print("This is an interactive guessing game!\n\
You have to enter a number between 1 and 99 to find out the secret number.\n\
Type 'exit' to end the game.\n\
Good luck!")

while (True):
    user_input = input("What's your guess between 1 and 99?\n>> ")
    if user_input.isnumeric():
        if int(user_input) > answer:
            print('Too high!')
            attempt += 1
        elif int(user_input) < answer:
            print('Too Low!')
            attempt += 1
        elif int(user_input) == answer and answer == 42:
            print("The answer to the ultimate question of life,")
            print('the universe and everything is 42.')
            break
        elif int(user_input) == answer and attempt == 0:
            print("Congratulations, you've got it at first time!")
            break
        elif int(user_input) == answer:
            print("Congratulations, you've got it!")
            print(f'You won in {attempt + 1} attempts!!')
            break
    elif user_input == 'exit':
        print("Goodbye!")
        break
    else:
        print("That's not a number.")
