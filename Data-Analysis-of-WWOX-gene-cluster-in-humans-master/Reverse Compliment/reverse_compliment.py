from Bio.Seq import Seq
from Bio.Alphabet import IUPAC

def reverse_compliment(file):
    fptr = open(file,"r")
    str1 = fptr.readlines()
    fptr1 = open("reverse compliment.txt","w")

    str2=""
    i=0
    while(i<len(str1)):
        str2 = str2+str1[i]
        i=i+1;

    str2.replace("\n","") #remove all '\n' to make the Seq an instance of IUPAC unambiguous DNA(only ATGC)

    my_seq = Seq(str2,IUPAC.unambiguous_dna)
    fptr1.write(str(my_seq.reverse_complement())) #convert seq to string by str(Seq)
    print("Open file reverse compliment.txt to get the reverse compliment")


reverse_compliment("nucleotides.txt")
