## Objective to calculate the edit distance:
* The Edit Distance problem is used to measure the similarity between 2 biological sequences
* It is based on minimum cost notion.
* Edit distance = 1/similarity (Edit distance is inversely proportional to the similarity between 2 sequences

## Parameters in the program
* **Cost**
  * An option to redefine cost is given in the program executable.
  * _\_MATCH\_COST_ : __Continue__ Cost to match 2 similar charaters (negative according to defination), default value = 0
  * _\_MISMATCH\_COST_ : __Replacement of character__ Cost to put 2 similar characters at a mismatch (positive cost acc. to definition), default value = 1
  * _\_GAP_COST_ : __Insert a character/ Delete a character in complementary sequence__ Cost to incorporate a gap in the aligned sequnec (positive cost acc. to definition), default value = 1
  
## Output
* The minimum edit distance. The minimum number of changes required to interconvert the sequnces into similar sequences.
