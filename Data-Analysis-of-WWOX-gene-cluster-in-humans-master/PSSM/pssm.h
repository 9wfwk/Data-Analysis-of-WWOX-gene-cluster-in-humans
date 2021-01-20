#include <bits/stdc++.h>

#ifndef PSSM_H
#define PSSM_H

#define PSEUDOCOUNT 1
#define FI 0.05
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

using namespace std;

extern int NO_OF_SEQUENCES;
extern vector<string> seq;
extern set<char> map;

vector<vector<int>> frequencyMatrix(vector<string> seq);
/* fills the frequency matrix and returns it*/


void calculatePSSM(vector<vector<int>> &vec);

#endif
