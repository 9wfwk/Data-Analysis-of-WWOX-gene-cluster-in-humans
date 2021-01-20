from Bio import SeqIO

filename = "fasta_format_sequence.fasta"


def processfile(file):
    fo = open(file,"r")

    str1= fo.readlines(); #str1 forms a list with elements as different lines in the fasta file

    #print(isinstance(str1,str))
    #print(isinstance(str1,list))
    i=0

    #str1 is a list, concatanate it to get sequence
    seq=""
    length=len(str1)
    #print(length)
    i=1;
    while i<length:
        seq=seq+str1[i]
        i=i+1

    fo1 = open("nucleotides.txt","w+")
    fo1.write(seq)
    g_count = seq.count('G')
    c_count = seq.count('C')
    a_count = seq.count('A')
    t_count = seq.count('T')
    u_count = seq.count('U')
    tot_len=len(seq)
    no_of_nucleotides = tot_len-16002 #tot_len also accounts for 16002 '\n' characters at the end of each line.
                                      #actual no. of nucleotides is obtained by subtracting 16002 from total_length
    print("G nucleotide: " + str(g_count))
    print("C nucleotide: " + str(c_count))
    print("A nucleotide: " + str(a_count))
    print("T nucleotide: " + str(t_count))
    print("U nucleotide: " + str(u_count))
    print("Total no. of nucleotides: " + str(no_of_nucleotides))

    print("%GC content: "+str(float((g_count+c_count)/no_of_nucleotides)*100))
    #print(seq)
    fo.close()
    fo1.close()


processfile(filename)
