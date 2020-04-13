# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    kata02.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 21:54:42 by hjeon             #+#    #+#              #
#    Updated: 2020/04/13 21:54:42 by hjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


time = (3,30,2019,9,25)
year = time[2]
month = time[3]
day = time[4]
hour = time[0] if 9 < time[0] else '0' + str(time[0])
minutes = time[1] if 9 < time[1] else '0' + str(time[1])

print(f'{month}/{day}/{year} {hour}:{minutes}')
