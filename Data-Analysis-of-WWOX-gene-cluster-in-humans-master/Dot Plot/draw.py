from Bio import SeqIO
import pylab

with open("fasta_format_sequence.fasta") as in_handle:
    record_iterator = SeqIO.parse(in_handle,"fasta")
    rec_one = next(record_iterator)
    rec_two = rec_one


for index,letter in enumerate(rec_one):
    print(letter,end='')


print()
for index,letter in enumerate(rec_two):
    print(letter,end='')

'''
window = 100
seq_one = str(rec_one.seq).upper()
seq_two = str(rec_two.seq).upper()
data = [
    [
        (seq_one[i : i+window] != seq_two[j : j+window])
        for j in range(len(seq_one)-window)
    ]
    for i in range(len(seq_two)-window)
]

pylab.gray()
pylab.scatter(data)
pylab.xlabel("%s (length %i bp)" % (rec_one.id, len(rec_one)))
pylab.ylabel("%s (length %i bp)" % (rec_two.id, len(rec_two)))
pylab.title("Dot Plot using window size %i\n(allowing no mis_matches)" % window)
pylab.show()
'''

window = 100
dict_one = {}
dict_two = {}
for(seq,section_dict) in [
    (str(rec_one.seq).upper(), dict_one),
    (str(rec_two.seq).upper(), dict_two),
]:
    for i in range(len(seq) - window):
        section = seq[i : i+window]
        try:
            section_dict[section].append(i)
        except KeyError:
            section_dict[section] = [i]


matches = set(dict_one).intersection(dict_two)
print("%i unique matches" % len(matches))

x=[]
y=[]
for section in matches:
    for i in dict_one[section]:
        for j in dict_two[section]:
            x.append(i)
            y.append(j)


pylab.cla()
pylab.gray()
pylab.scatter(x,y)
pylab.xlim(0, len(rec_one) - window)
pylab.ylim(0, len(rec_two) - window)
pylab.xlabel("%s (length %i bp)" % (rec_one.id, len(rec_one)))
pylab.ylabel("%s (length %i bp)" % (rec_two.id, len(rec_two)))
pylab.title("Dot plot using window size %i\n(allowing no mis_matches)" % window)
pylab.show()
