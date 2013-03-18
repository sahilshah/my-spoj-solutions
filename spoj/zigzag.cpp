#include <iostream>
#include <cstdio>
using namespace std;

long long diaStartSum[200020];

long long getVal(long long n, long long p, long long q){
	long long k=p+q-1;
	long long sum;
	if(k<=n){
		if(k%2)
			sum=diaStartSum[k]+k-p;
		else
			sum=diaStartSum[k]+p-1;
	}
	else{
		if(k%2)
			sum=diaStartSum[k]+n-p;
		else
			sum=diaStartSum[k]+n-q;	
	}
	return sum;
}

void initDiaStartSum(long long n){
	long long len,k,sum;
	sum=0;
	for(k=1;k<=n;k++){
		len=k;
		sum++;
		diaStartSum[k]=sum;
		sum=sum+len-1;
	}
	for(k=n+1;k<2*n;k++){
		len=(2*n-k);
		sum++;
		diaStartSum[k]=sum;
		sum=sum+len-1;
	}
}

int main(){
	long long n,k,steps,i,j;
	// scanf("%d %d\n",&n,&steps);
	cin >> n >> steps;
	scanf("\n");
	long long sum=1;
	initDiaStartSum(n);
	char c;
	sum=1;
	i=1;j=1;
	for(k=0;k<steps;k++){
		scanf("%c",&c);
		if(c=='D')
			sum+=getVal(n,++i,j);
		else if(c=='U')
			sum+=getVal(n,--i,j);
		else if(c=='R')
			sum+=getVal(n,i,++j);
		else if(c=='L')
			sum+=getVal(n,i,--j);
		else{
			cout << "ERROR!\n";  return 1;
		}
	}
	cout << sum << '\n';
}