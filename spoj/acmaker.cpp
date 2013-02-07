#include <iostream>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>

vs phrase;
string acr,str,wInsig;
vs insig;

int main(){
	int n;
	stringstream ss;
	string s;
	map <string,bool> isw;
	while(cin >> n && n){
		string temp;
		while(n--){
			cin >> temp;
			isw.insert(pair<string,bool>(temp,1));
			cout << temp << endl;
		}
		getline(cin,s);
		getline(cin,s);
		cout << s<< endl;
		ss << s;
		ss >> acr;
		for(int i=0;i<acr.size();i++) acr[i]=tolower(acr[i]);
		while(ss >> temp){
			cout << temp << endl;
			if(isw.find(temp)==isw.end())
				phrase.pb(temp);
		}
		
		



		//check
/*		for(vs::iterator it=phrase.begin(); it!=phrase.end(); ++it) 
			cout << *it << endl;*/
	}
}