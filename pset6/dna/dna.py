import csv
import sys
from cs50 import get_string
from itertools import *

newstrsCmp = []

## function for change each value inside a list

def lengthTaker(diffrences):
    for everySingle in diffrences:
        if len(everySingle) == 1:
            ## printing match
            print(everySingle[0])
        else:
            return

def typeChanger(comperer):

    for single in comperer:

        single = str(single)
        newstrsCmp.append(single)

def returnNotMatches(listA, listB):

    return [[x for x in listA if x not in listB], [x for x in listB if x not in listA]]

def checkIfMatch(elem, comperer):

    checkbox = False

    for compare in range(1, elem):
        compare = int(compare)
        if compare in comperer:
            checkbox = True
        else:
            checkbox = False
    return checkbox

def main():

     ## Checking theres putted an 2 extra args into program ##

    if len(sys.argv) != 3:
        print("error!")

        ## Main program ##

    else:

        strSeqPath = str(sys.argv[2])
        strDBPath = str(sys.argv[1])

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

            seqStorer = []
            names = []

            ### Reading through the CSV for seq ###
            for index in range(3):
                line = next(justreader)
                #line.pop(0)
                seqStorer.append(line)

            ## Length of each genom ##
            table_of_num = []
            for i in row1:
                num = len(i)
                table_of_num.append(num)

            ## List for separated element ##
            strsCmp = []
            o = 0
            counter = 0

            for z in range(len(table_of_num)):
                j = table_of_num[z]

            ## Appending separated String to list ##
                while(seqLen >= j):
                        if row1[z] == sequence[o:j]:
                            j += table_of_num[z]
                            o += table_of_num[z]
                            counter += 1
                        else:
                            j += 1
                            o += 1
                # Create list for CMPRS
                strsCmp.append(counter)
                # Reset the counters
                counter = 0
                o = 0

            typeChanger(strsCmp)

            for each in seqStorer:

                lengthTaker(returnNotMatches(each, newstrsCmp))


main()
