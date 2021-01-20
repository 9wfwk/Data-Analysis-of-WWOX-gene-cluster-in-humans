#include <bits/stdc++.h>

using namespace std;

int _MATCH_COST;
int _GAP_COST;
int _MISMATCH_COST;

void printArr(int **arr, int n, int m){
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void printAlignment(const string &hor,const string &ver){
	cout << "Global alignment results: " << endl;
	cout << "-------------------------------------------" << endl;
	for(int i=0; i<hor.size(); ++i){
		cout << hor[i] << " ";
	}
	
	cout << endl;
	
	for(int i=0; i<hor.size(); ++i){
		if(hor[i]==ver[i]){
			cout << "* ";
		}
		else if(hor[i]=='-' || ver[i]=='-'){
			cout << "  ";
		}
		else{
			cout << "| ";
		}
	}
	
	cout << endl;
	
	for(int i=0; i<ver.size(); ++i){
		cout << ver[i] << " ";
	}
	cout << endl;
	cout << "--------------------------------------------" << endl;
}

int needlemanWunsch(string s, string t){
	int n=s.size()+1;
	int m=t.size()+1;
	int **arr= new int*[n];
	for(int i=0; i<n; ++i){
		arr[i]=new int[m];
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
				arr[i][j]=arr[i-1][j-1] + _MATCH_COST;
			}
			else{
				arr[i][j]=min(_GAP_COST + min(arr[i-1][j],arr[i][j-1]),arr[i-1][j-1] + _MISMATCH_COST);
			}
		}
	}
	
	//Uncomment to print the matrix
	printArr(arr,n,m);
	
	string hor = string();
	string ver = string();
	int i = n-1;
	int j = m-1;
	
	while(i>0 || j>0){
		if(s[i-1]==t[j-1]){
//			cout << "Match: " << " i: " << i << " j: " << j << endl;
//			cout << "----------------------------------------------------------" << endl;
			hor += s[i-1];
			ver += s[i-1];
			--i;
			--j;
		}
		else{			
			int miscost=INT_MAX, hor_gcost = INT_MAX, ver_gcost = INT_MAX;
			if(i>0 && j>0){
				miscost = arr[i-1][j-1]+ _MISMATCH_COST;
				hor_gcost = arr[i-1][j] + _GAP_COST;
				ver_gcost = arr[i][j-1] + _GAP_COST;
			}
			else if(i>0){
				hor_gcost = arr[i-1][j] + _GAP_COST;
			}
			else{
				ver_gcost = arr[i][j-1] + _GAP_COST;
			}
			
			if(miscost <= min(hor_gcost, ver_gcost)){
//				cout << "Mis Match: " << " i: " << i << " j: " << j << endl;
				hor += t[j-1];
				ver += s[i-1];
				--i;
				--j;
			}
			else if(hor_gcost <= min(miscost, ver_gcost)){
//				cout << "hor gap: " << " i: " << i << " j: " << j << endl;
				hor += '-';
				ver += s[i-1];
				--i;
			}
			else if(ver_gcost <= min(miscost, ver_gcost)){
//				cout << "ver gap: " << " i: " << i << " j: " << j << endl;
				ver += '-';
				hor += t[j-1];
				--j;
			}
			
//			cout << "miscost : " << miscost << " hor_gcost: " << hor_gcost << " ver_gcost: " << ver_gcost << endl;
//			cout << "-------------------------------------------------------" << endl;			
		}
	}
	
	reverse(hor.begin(), hor.end());
	reverse(ver.begin(), ver.end());
	
	printAlignment(hor,ver);
	
	return arr[n-1][m-1];
}

int main(){
	cout << "Enter match cost: " << endl;
	cin >> _MATCH_COST;
	cout << "Enter mismatch cost: " << endl;
	cin >> _MISMATCH_COST;
	cout << "Enter gap cost: " << endl;
	cin >> _GAP_COST;
	
	string sequence_1, sequence_2;
	cout << "Enter sequences: " << endl;
	cin >> sequence_1 >> sequence_2;
	
	cout << endl;
	int min_ed = needlemanWunsch(sequence_1, sequence_2);
	
	cout << "Cost of the optimal global alignment: " << min_ed << endl;
}

