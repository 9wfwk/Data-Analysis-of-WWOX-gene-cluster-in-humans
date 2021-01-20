#include <bits/stdc++.h>

using namespace std;

string printLCS(string &s1, string &s2){
	int m=s1.length(), n=s2.length();

	int L[m+1][n+1];
	for(int i=0; i<=m; ++i){
		for(int j=0; j<=n; ++j){
			if(i==0 || j==0){
				L[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1]){
				L[i][j] = L[i-1][j-1]+1;
			}
			else{
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	
	int index = L[m][n];
	
	char *lcs = (char*)malloc(sizeof(char)*(index+1));
	lcs[index] = '\0';

	int i =m, j=n;
	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]){
			lcs[index-1] = s1[i-1];
			--i;
			--j;
			--index;
		}
		else if(L[i-1][j] > L[i][j-1]){
			--i;
		}
		else{
			--j;
		}
	}

	string ans = string(lcs);
	return ans;
}

int main(){
	string seq_1, seq_2;
	cout << "Enter the sequences: " << endl;
	cin >> seq_1 >> seq_2;

	string lcs = printLCS(seq_1, seq_2);
	cout << "LCS of " << seq_1 << " and " << seq_2 << " : " << lcs << endl;
}
