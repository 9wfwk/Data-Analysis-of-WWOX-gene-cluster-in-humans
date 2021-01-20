#include <bits/stdc++.h>

using namespace std;

/* Default Scoring scheme:
	--> Match - 0;
	--> Gap - +1 cost
	--> Mismatch - +1 cost
*/

int _MATCH_COST=0;
int _GAP_COST=1;
int _MISMATCH_COST=1;

void printArr(int **arr, int n, int m){
	for(int i=0; i<=n; ++i){
		for(int j=0; j<=m; ++j){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int** editDistance(string s, string t){
	int n=s.size()+1;
	int m=t.size()+1;
	int **arr= new int*[n];
	for(int i=0; i<n; ++i){
		arr[i]=new int[m];
		for(int j=0; j<m; ++j){
			arr[i][j]=0;
		}
	}

	arr[0][0]=0;
	for(int i=1; i<n; ++i){
		arr[i][0]=arr[i-1][0] + _GAP_COST;
	}
	for(int j=1; j<m; ++j){
		arr[0][j]=arr[0][j-1] + _GAP_COST;
	}

	for(int i=1; i<n; ++i){
		for(int j=1; j<m; ++j){
			if(s[i-1]==t[j-1]){
				arr[i][j]=arr[i-1][j-1]+ _MATCH_COST;
			}
			else{
				arr[i][j]=min(_GAP_COST + min(arr[i-1][j],arr[i][j-1]),arr[i-1][j-1] + _MISMATCH_COST);
			}
		}
	}
		
	return arr;
}

int main(){
	int op;
	cout << "Redefine cost (1/0): " << endl;
	cin >> op;
	if(op==1){
		cout << "Enter match cost: " << endl;
		cin >> _MATCH_COST;

		cout << "Enter mismatch cost: " << endl;
		cin >> _MISMATCH_COST;

		cout << "Enter gap cost: " << endl;
		cin >> _GAP_COST;
	}
	
	string sequence_1, sequence_2;
	cout << "Enter sequences: " << endl;
	cin >> sequence_1 >> sequence_2;
	
	int** matrix = editDistance(sequence_1, sequence_2);
	
	cout << "Min edit distance after global alignment: " << matrix[sequence_1.size()][sequence_2.size()] << endl;
	cout << endl;
	cout << "Print DP matrix (1/0): " << endl;
	int temp;
	cin >> temp;
	if(temp==1){
		printArr(matrix, sequence_1.size(), sequence_2.size());
	}
}

