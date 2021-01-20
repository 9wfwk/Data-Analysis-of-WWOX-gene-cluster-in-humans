from Bio.Seq import Seq
from Bio.Alphabet import IUPAC
from collections import OrderedDict


filename = "isoform3.txt"


def single_to_aa(argument):
    switcher = {
        'D':"Asp",
        'T':"Thr",
        'S':"Ser",
        'E':"Glu",
        'P':"Pro",
        'G':"Gly",
        'A':"Ala",
        'C':"Cys",
        'V':"Val",
        'M':"Met",
        'I':"Ile",
        'L':"Leu",
        'Y':"Tyr",
        'F':"Phe",
        'H':"His",
        'K':"Lys",
        'R':"Arg",
        'W':"Trp",
        'Q':"Gln",
        'N':"Asn",
    }
    return switcher.get(argument,"invalid")


def processfile(file):
    fo = open(file,"r")
    str = fo.readlines() #reads the sequence and creates a list

    #we append the elements to form a single sequence string
    str1=""
    for x in str:
        str1=  str1+x

    #print(str1)
    my_seq = Seq(str1, IUPAC.protein)
    #print(my_seq.count("Q"))
    dict = {'D':0,'T':0,'S':0,'E':0,'P':0,'G':0,'A':0,'C':0,'V':0,'M':0,'I':0,'L':0,'Y':0,'F':0,'H':0,'K':0,'R':0,'W':0,'Q':0,'N':0}
    for aa in dict:
        dict[aa] = my_seq.count(aa)

    for aa in dict:
        print(single_to_aa(aa),end=" : ")
        print(dict[aa])


processfile(filename)