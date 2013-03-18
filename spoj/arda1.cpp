#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int kmp(string S, int sSt, string K, int kSt){
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

char map[2002][2002],marsh[302][302];
int main(){
    int n1,n2,m1,m2;
    cin >> m1 >> m2;
    for(i=0;i<m1;i++){
        scanf("%s\n",marsh[i]);
    }
    cin >> n1 >> n2;
    for(i=0;i<n1;i++){
        scanf("%s\n",map[i]);
    }
    char *sp,*tp;
    int prevs=-1,s;
    for(i=0;i<n1;i++){
        tp=&map[i][0];
        for(j=0;j<m1;j++){     
            sp=&marsh[j][0];
            string t(tp);
            string s(sp);
            s=kmp(t,s);
            if(prevs!=-1){
                if(s==prevs){
                    i++
                }
            }
   
        }
            string text()            
    }






}

