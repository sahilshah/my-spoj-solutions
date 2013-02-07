#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
	string forbidden[]={"bz a a a", "a bz a a", "a a bz a", "a a a bz"};
	//string word;
	// queue<string>;
	for(int i=0; i<4; i++){
		string s = forbidden[i];
		string s1;
		string s2;
		string s3;
		string s4;
		int sp1=s.find(" ",0);
		int sp2=s.find(" ",sp1+1);
		int sp3=s.find(" ",sp2+1);
		s1.assign(s,0,sp1);
		s2.assign(s,sp1+1,sp2-sp1-1);
		s3.assign(s,sp2+1,sp3-sp2-1);
		s4.assign(s,sp3+1,s.length()-sp3-1);
		for(int p=0;p<s1.length();p++){
			for(int q=0;q<s2.length(),q++){
				for(int r=0;r<s2.length(),r++){
					for(int s=0;s<s2.length(),s++){
						states[s1.at(p)-'a'][s2.at(q)-'a'][s3.at(r)-'a'][s4.at(s)-'a']=-1;
					}
				}
			}
		}
	}
	return 0;
}