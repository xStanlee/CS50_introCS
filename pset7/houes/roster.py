#SPAGHETTI

import sys
import sqlite3

def main():

    allInTheHouse = str(sys.argv[1])
    con = sqlite3.connect("students.db")
    db = con.cursor()
    NULL = None
    houses = ['Gryffindor', 'Ravenclaw', 'Slytherin', 'Hufflepuff']

    academic = []
    names = []
    listOfNames = []
    births = []

    if len(sys.argv) != 2:
        print("Wrong quantity of arguments!")
    elif allInTheHouse == NULL:
        print("You forgot pass House as Argument")

    ## main func
    else:
        if allInTheHouse not in houses:
            print(f"There's no house with that name: {allInTheHouse}")
        else:
            select_query = """SELECT first, middle, last, birth, house FROM students ORDER BY last;"""

            db.execute(select_query)
            data = db.fetchall()

            for row in data:
                if allInTheHouse in row:
                    singleRow = []
                    for each in row:
                        singleRow.append(each)
                    academic.append(singleRow[-1])
                    births.append(singleRow[-2])
                    names.append(singleRow[0:len(singleRow)-2])
                else:
                    continue
        for x in names:
            student = ''
            for each in x:
                if each == 'None':
                    continue
                else:
                    student += each
                    student += ' '
            listOfNames.append(student)

        for i in range(1, len(births)):
            print(listOfNames[i] + 'born in: ' + str(births[i]))

main()
