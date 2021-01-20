#include "pssm.h"

int NO_OF_SEQUENCES=0;
vector<string> seq;
set<char> mp;

int main(int argc, char *argv[]){
	cout.setf(ios::fixed,ios::floatfield);
    	cout.precision(3);

	FILE *fptr = fopen(argv[1],"r");

	char str[1000];
	while(fscanf(fptr,"%s\n",str)!=EOF){
		seq.push_back(str);
	}

	for(vector<string>::iterator it=seq.begin(); it!=seq.end(); ++it){
		cout << *it << endl;
	}
	cout << endl;
	cout << endl;

	NO_OF_SEQUENCES=seq.size();

	vector<vector<int>> vec=frequencyMatrix(seq);
	calculatePSSM(vec);

	cout << endl;
	cout << endl;
	
	cout << "   ";
	for(set<char>::iterator it=mp.begin(); it!=mp.end(); ++it){
		cout << " " << *it << " "; 
	}
	cout << endl;

	for(int i=0; i<mp.size() ; ++i){
		cout << "---";
	}
	cout << "---";
	cout << endl;
	for(int i=0; i<vec.size(); ++i){
		if((i+1)<10){
			cout << " ";
		}
		cout << UNDERLINE << i+1 << "|" << CLOSEUNDERLINE;
		for(int j=0; j<vec[0].size(); ++j){
			cout << UNDERLINE  << " " << vec[i][j] << " " << CLOSEUNDERLINE;
		}
		cout << endl;
		//cout << endl; //Uncomment to have more space b/w 2 lines
	}
	
}

vector<vector<int>> frequencyMatrix(vector<string> seq){
	string str;

	for(vector<string>::iterator it=seq.begin(); it!=seq.end(); ++it){
		for(int i=0; i<(*it).size(); ++i){
			str=*it;
			mp.insert(str[i]);
		}
	}

	set<char>::iterator it1=mp.begin();
	mp.erase(*it1);

	vector<vector<int>> vec;
	for(int i=0; i<seq[0].size(); ++i){
		vector<int> temp;
		for(int j=0; j<mp.size(); ++j){
			temp.push_back(0);
		}
		vec.push_back(temp);
	}

	char ch;
	set<char>::iterator it2;
	int index;
	it1=mp.begin();

	for(int i=0; i<seq[0].size(); ++i){
		for(int j=0; j<seq.size(); ++j){
			ch=seq[j][i];
			it2=mp.find(ch);
			index = distance(mp.begin(),it2);
			++vec[i][index];
		}
	}

	return vec;
}


void calculatePSSM(vector<vector<int>> &vec){
	vector<vector<double>> pssm;
	double val=0.00000000;
	
	for(int i=0; i<vec.size(); ++i){
		vector<double> temp;
		for(int j=0; j<vec[0].size(); ++j){
			temp.push_back(0.00000000);
		}
		pssm.push_back(temp);
	}
	
	for(int i=0; i<vec.size(); ++i){
		for(int j=0; j<vec[0].size(); ++j){		
			val=((double)(vec[i][j]+PSEUDOCOUNT)/(NO_OF_SEQUENCES+20*PSEUDOCOUNT));
			pssm[i][j]=log10(val/FI);
		}
	}

	cout << "     ";
	for(set<char>::iterator it=mp.begin(); it!=mp.end(); ++it){
		cout << " " << *it << "      "; 
	}
	cout << endl;
	
	for(int i=0; i<mp.size() ; ++i){
		cout << "-----";
	}
	cout << "-------";
	cout << endl;

	for(int i=0; i<pssm.size(); ++i){
		if((i+1) < 10){
			cout << UNDERLINE << " " << CLOSEUNDERLINE;
		}
		cout << UNDERLINE << i+1 << "|" << CLOSEUNDERLINE;
		for(int j=0; j<pssm[0].size(); ++j){
			if(pssm[i][j]>0){
				cout << UNDERLINE << " " << CLOSEUNDERLINE;
			}
			cout << UNDERLINE << " " << pssm[i][j] << " " << CLOSEUNDERLINE;
		}
		cout << endl;
		//cout << endl; //Uncomment for more space
	}
}
