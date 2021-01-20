## Objective
* Perform global alignment of 2 DNA sequences by two methods -
  * Cost minimisation - Minimizes the cost of alignment
  * Score maximisation - Maximizes the score of the alignment
  
## Input
* Needleman_Wunsch_cost.cpp 
  * _\_MATCH\_COST_ : The cost of match (negative)
  * _\_MISMATCH\_COST_ : The cost of mis-match (positive cost)
  * _\_GAP\_COST_ : The cost of introducing a gap )positive cost)
  
* Needleman_Wunsch_score.cpp
  * _\_MATCH\_SCORE_ : The score of match (negative score)
  * _\_MISMATCH\_SCORE_ : The score of mis-match (positive score)
  * _\_GAP\_SCORE_ : The score of introducing a gap (positive score)
  
## Using instruction
* **$ g++ Needleman\_Wunsh\_score.cpp**  
  **$ ./a.out**
  
* **$ g++ Needleman\_Wunsch\_cost.cpp**  
  **$ ./a.out**
