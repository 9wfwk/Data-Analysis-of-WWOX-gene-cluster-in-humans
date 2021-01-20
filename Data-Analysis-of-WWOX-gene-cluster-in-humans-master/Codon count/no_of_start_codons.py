def get_codon_numbers(file,str2):
    fptr2 = open(file,"r")
    str3= fptr2.readlines()

    str4 =""
    i=0
    while(i<len(str3)):
        str4 = str4+str3[i]
        i=i+1

    #print(str4). raw transcript is stored in file raw_transcript.txt

    contiguous_sequence_transcript=str4.replace("\n","") #replace enter characters by blank character
                                                         #because "A\nUG" wont't be considered without removing '\n'
                                                         #but "AUG" is a start codon.
    print("Count of "+ str2 + " in raw transcript: " +str(contiguous_sequence_transcript.count(str2)))


get_codon_numbers("raw_transcript.txt","AUG")
