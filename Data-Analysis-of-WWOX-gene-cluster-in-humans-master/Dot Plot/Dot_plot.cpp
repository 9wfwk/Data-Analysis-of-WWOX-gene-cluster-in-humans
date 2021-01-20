#include <bits/stdc++.h>

using namespace std;

int main(){
	string str1;
	cin >> str1;
	int n = str1.size();

	char **dp = new char*[n];
	for(int i=0; i<n; ++i){
		dp[i] = new char[n];
		for(int j=0; j<n; ++j){
			dp[i][j] = '-';
		}
	}

	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(str1[i]==str1[j]){
				dp[i][j]='*';
			}
		}
	}

	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}
