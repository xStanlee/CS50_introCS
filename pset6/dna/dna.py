import csv
import sys
from cs50 import get_string
from itertools import *

strSeqPath = str(sys.argv[2])
strDBPath = str(sys.argv[1])

## Checking theres putted an 2 extra args into program ##

if len(sys.argv) != 3:
    print("error!")

## Main program ##

else:
    ## Read path ##
    f = open('sequences/' + strSeqPath, 'r')
    ## Read file ##
    sequence = f.read()
    ## Length of string file ##
    seqLen = len(sequence)

    print(sequence)

           ########## OPEN DB AS STRING ##############

        ## Again search a path in ##

    with open('databases/' + strDBPath, 'r') as database:

        ## Read CSV file ##
        justreader = csv.reader(database)
        ## Take only 1st row of file ##
        row1 = next(justreader)
        ## Delete index 0 ##
        row1.pop(0)
                                                    #print(row1[0])
        ## Length of each genom ##
        table_of_num = []
        for i in row1:
            num = len(i)
            table_of_num.append(num)

        ## List for separated element ##
        STRS = []
        o = 0                                            #print(table_of_num[0])
        for z in range(len(table_of_num)):
            j = table_of_num[z]

        ## Appending separated String to list ##
            while(seqLen >= j):
                STRS.append(sequence[o:j])
                j += table_of_num[z]
                o += table_of_num[z]
            o = 0
        print(STRS[0])
        print(row1[0])
        count = 0

        for eachOne in STRS:
            if row1[0] in STRS[eachOne]:
                print("true")




         ############## OPEN DB AS COL ##################

    with open(f'databases/{str(sys.argv[1])}', 'r') as datatable:
        reader = csv.DictReader(datatable)
        #for row in reader:
            #print(row['name'], row['AGATC'], row['AATG'], row['TATC'])
