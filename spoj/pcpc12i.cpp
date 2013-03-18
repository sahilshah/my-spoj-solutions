#include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <string>
using namespace std;

int main(){
    int n,i,cur,next,prev,ans,sum,max;
    // cout << "hello" << endl;
    while(cin >> n){
        //scanf("\n");
        cout << n << '\n';
        prev=0;cur=0;next=0;max=-1,sum=0,ans=-1;
        cin >> prev;
        cin >> cur;
        cin >> next;
        cout << n << " " << cur << '\n';
        if(prev <= cur && cur >= next)
            sum = (cur-prev) + (next-cur);
        else if (prev >= cur && cur <= next)
            sum = (prev-cur) + (next-cur);
        if(max>sum){
            max=sum;
            ans=cur;
        }
        for(i=3;i<n;i++){
            prev=cur;
            cur=next;
            cin >> next;
            if(prev <= cur && cur >= next)
                sum = (cur-prev) + (next-cur);
            else if (prev >= cur && cur <= next)
                sum = (prev-cur) + (next-cur);
            if(max>sum){
                max=sum;
                ans=cur;
            }
        }
    }
}