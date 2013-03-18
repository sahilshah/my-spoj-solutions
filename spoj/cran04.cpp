#include <iostream>
#include <cstdio>
using namespace std;

int cum[1000000];
char q[1000000];

int main(){
	int t;
	scanf("%d\n",&t);
	while(t--){
		int n,k,i,j;
		scanf("%d %d\n",&n,&k);
		if(k>n){
			cout << "0\n";
			continue; 
		}
		k--;
		scanf("%s\n",q);
		cout << q << endl;
		cum[0]=0;
		for(i=1;i<n;i++)
			cum[i]=cum[i-1]+(q[i-1]-'0');
		cout << "CUMMULATIVE \n";
		for(i=1;i<n;i++)
			cout << cum[i] << '\n';
		int first,second,count,pSec;
		first=1;second=1;count=0;pSec=0;
		cout << "K is " << k << '\n';
		while(second<n){
			while(cum[second]<cum[first]+k)
				second++;
			pSec=second;
			while(cum[second]==cum[first]+k){
				count++;second++;}
			second=pSec;
			first++;
		}
		cout << count << '\n';
	}
}