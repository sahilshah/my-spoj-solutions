#include <stdio.h>
#include <math.h>
#define N 100000
int main(){

	int i,t;
	long int num[N],denom,temp,sum[N];
	scanf("%d",&t);

	for(i=0;i<t;i++){
		scanf("%ld",&num[i]);
		sum[i]=0;
		temp=0;
		denom=5;
		do{
			temp=num[i]/denom;
			sum[i]=sum[i]+temp;
			denom=denom*5;
		}while(temp>0);
	}
	for(i=0;i<t;i++)
		printf("%ld\n",sum[i]);
	return 0;	
}
