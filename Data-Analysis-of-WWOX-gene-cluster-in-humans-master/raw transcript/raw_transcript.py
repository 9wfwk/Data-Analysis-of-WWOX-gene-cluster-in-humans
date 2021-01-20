filename = "nucleotides.txt"


def raw_transcript(file):
    fptr = open(file,"r")
    str1=fptr.readlines()
    fptr1 = open("raw_transcript.txt","w")

    length=len(str1)
    i=0
    while(i<length):
        each_element=str1[i]
        #each_element.replace("T","U")
        fptr1.write(each_element.replace('T','U'))
        #print(each_element.replace('T','U'))
        i=i+1
    print("Raw transcript stored in file raw_transcript.txt")
    print()


raw_transcript(filename)
