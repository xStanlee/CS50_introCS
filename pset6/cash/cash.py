#Boloneze

from cs50 import get_float

rest = get_float("What is your rest ? \n")
rest = (rest * 100)
rest_int = int(rest)

quarters = 25
dimes = 10
nickles = 5
pennies = 1

coins = 0

while rest_int > 0:
    if rest_int >= quarters:
        coins += 1
        rest_int -= 25
    elif rest_int < quarters and rest_int >= dimes:
        coins += 1
        rest_int -= 10
    elif rest_int < dimes and rest_int >= nickles:
        coins += 1
        rest_int -= 5
    else:
        coins += 1
        rest_int -= pennies #Not penis lol

print(f"The minimum to return is {coins} coins.")
