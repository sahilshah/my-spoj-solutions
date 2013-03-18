#include <iostream>
#include <cstdio>
#include <cmath>
#define MAXNUM 10000005
using namespace std;

long long diaStartSum[200020];
pair<long long,long long> getTerm(long long num){
	long long k=1;
	long long off,x,y;
	pair<long long,long long> xy;
	while(diaStartSum[k]<num)
		k++;

	if(diaStartSum[k]==num){
		if(k%2){
			x=k;
			y=1;
		}
		else{
			y=k;x=1;
		}
		xy.first=x;
		xy.second=y;
		return xy;
	}

	k--;
	
	off=num-diaStartSum[k];
	if(k%2)
		x=k-off;
	else
		x=off+1;
	y=k-x+1;
	xy.first=x;
	xy.second=y;
	return xy;
}

void initDiaStartSum(){
	long long len,k,sum;
	sum=0;
	k=1;
	while(sum<(MAXNUM+k+50)){
		len=k;
		sum++;
		diaStartSum[k]=sum;
		sum=sum+len-1;
		k++;
	}
}

int main(){
	long long t;
	cin >> t;
	long long sum,root;
	pair<long long,long long> res(0,0);
	initDiaStartSum();
	while(t--){
		cin >> sum;
		res=getTerm(sum);
		cout << "TERM " << sum << " IS " << res.first <<
		  "/" << res.second <<'\n';		
	}
}