#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
 
//----------------------------
// KMP:
//Returns a vector containing the zero based index of 
//  the start of each match of the string K in S.
//  Matches may overlap
//----------------------------
int checkInText(string S, string K){
    vector<int> T(K.size() + 1, -1);
    vector<int> matches;
    if(K.size() == 0){
        matches.push_back(0);
        //return matches;
    }
    for(int i = 1; i <= K.size(); i++){
            int pos = T[i - 1];
            while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
            T[i] = pos + 1;
    }
    int sp = 0;
    int kp = 0;
    while(sp < S.size()){
        while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
        kp++;
        sp++;
        if(kp == K.size()) matches.push_back(sp - K.size());
    }
    // return matches;
    return matches.size();
}

int printAllStrings(string text, char* s, int m, int k, int lev, int flag){
    int i;
    char c;
    if(flag)
        return flag;
    if(lev==m){
        int x;
        s[m]='\0';
        string s1(s);
        x=checkInText(text,s1);
        if(x==0){
            cout << s << '\n';
            flag=1;
        }
        else{
            flag=0;
        }
        return flag;
    }
    //string s("");
    for(i=0;i<k;i++){
        c='a'+i;
        s[lev]=c;
        flag=printAllStrings(text,s,m,k,lev+1,flag);
    }
    return flag;
}

int main(){
    char text[10010],s[110];
    int t,n,m,k;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        scanf("%s\n",text);
        // cout << "TEXT is: " << text <<'\n';
        printAllStrings(text,s,m,k,0,0);
        // cout << "next\n";
    }
}