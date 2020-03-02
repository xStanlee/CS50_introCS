# Mario recursion

from cs50 import get_int

def main():

    height = get_int("Put the hight of the pyramid object: \n")

    def mariostep(n):

        if n == 0:
            return
        else:
            mariostep(n - 1)
            for i in range(n):
                print("#", end = '')
            print("", end = '\n')

    mariostep(height)

main()
