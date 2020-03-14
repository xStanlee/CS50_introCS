import csv
import sys
from cs50 import SQL

db = SQL ("sqlite:///students.db")
strCharacters = str(sys.argv[1])
NULL = None
my_Sql_push = ''

if strCharacters != NULL:
    with open(strCharacters, 'r', encoding='ISO-8859-1') as csvB:
        #csvBase = csv.reader(csvB)
        csvBase = csv.DictReader(csvB)
        for row in csvBase:
            ### Creating new keys inside Dictionary
            row['middle'] = ''
            row['last'] = ''

            ### Part fullname
            split = row['name'].split( );

            row['name'] = split[0]

            if len(split) == 3:
                row['middle'] = split[1]
                row['last'] = split[2]

            else:
                row['middle'] = None
                row['last'] = split[1]

            f_name = row['name']
            s_name = row['middle']
            l_name = row['last']
            b = row['birth']
            h = row['house']

            my_Sql_push = f"""INSERT INTO students (first, middle , last, house, birth)
            VALUES
            ('{f_name}', '{s_name}', '{l_name}', '{h}', '{b}') """

            ### Push to DB
            db.execute(my_Sql_push)

    csvB.close()
