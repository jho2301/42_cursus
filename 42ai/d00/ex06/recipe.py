# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    recipe.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 22:12:07 by hjeon             #+#    #+#              #
#    Updated: 2020/04/13 22:12:07 by hjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


cookbook = {'sandwitch': {'ingredients': ['ham', 'bread', 'cheese', 'tomatoes'],
                        'meal': 'lunch',
                        'prep_time': 10},
            'cake': {'ingredients': ['flour', 'sugar', 'eggs'],
                    'meal': 'dessert',
                    'prep_time': 60},
            'salad': {'ingredients': ['avocado', 'arugula', 'tomatoes', 'spinach'],
                    'meal': 'lunch',
                    'prep_time': 15}}


def print_recipe(recipe):
    if recipe in cookbook.keys():
        print(f'Recipe for {recipe}:')
        print(f'Ingredients list: ', cookbook[recipe]['ingredients'], sep='')
        print(f'To be eaten for ', cookbook[recipe]['meal'], '.', sep='')
        print('Takes', cookbook[recipe]['prep_time'],'minutes of cooking.\n')
    else:
        print('there\'s no recipe\n')



def delete_recipe(recipe):
    if recipe in cookbook.keys():
        del cookbook[recipe]
        print('deletion success\n')
    else:
        print('there\'s no recipe\n')


def add_recipe(recipe, ingredients, meal, prep_time: str):
    ingredients_list = ingredients.split(',')
    for i in range(len(ingredients_list)):
        ingredients_list[i] = ingredients_list[i].strip()

    if recipe not in cookbook.keys() and prep_time.isnumeric():
        cookbook[recipe] = {'ingredients': ingredients_list,
                            'meal': meal,
                            'prep_time': int(prep_time)}
        print('insertion success\n')
    else:
        print('already exist\n')


def recipe_dict():
    print('''Please select an option by typing the corresponding number:
1: Add a recipe
2: Delete a recipe
3: Print a recipe
4: Print the cookbook
5: Quit''')
    while True:
        user_input = input('>> ')
        print()
        if user_input == '1':
            print("Please enter the recipe's name to add:")
            recipe = input('>> ')
            print()
            print("Please enter the recipe's ingredients: (sperate with ',')")
            ingredients = input('>> ')
            print()
            print("Please enter the recipe's meal type:")
            meal = input('>> ')
            print()
            print("Please enter the recipe's preperation time:")
            prep_time = input('>> ')
            print()
            add_recipe(recipe, ingredients, meal, prep_time)
        elif user_input == '2':
            print("Please enter the recipe's name to delete:")
            recipe = input('>> ')
            print()
            delete_recipe(recipe)
        elif user_input == '3':
            print("Please enter the recipe's name to get its details:")
            recipe = input('>> ')
            print()
            print_recipe(recipe)
        elif user_input == '4':
            print(list(cookbook.keys()), '\n')
        elif user_input == '5':
            print("Cookbook closed.")
            exit()
        else:
            print("\nThis option does not exist, \
                please type the corresponding number.")
            print("To exit, enter 5.")
            continue
        recipe_dict()


recipe_dict()
