#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
void printAllStrings(char* text, char* s, int n, int k, int lev){
    static int count=1;
    int i;
    char c;
    if(lev==n){
        s[n]='\0';
        int x=checkInText(text,s);
        if(x)
            cout << count <<  ". " << s << '\n';
        count++;
        return;
    }
    //string s("");
    for(i=0;i<k;i++){
        c='a'+i;
        s[lev]=c;
        lev;
        printAllStrings(s,n,k,lev+1);
    }
}

int main(){
    char s[100];
    printAllStrings(s,3,3,0);
}