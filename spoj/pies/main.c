#include <stdio.h>

int main(){
	int a,d,t,i;
	float x,n;
	scanf("%d",&t);
	float result[t];
	for(i=0;i<t;i++){
		scanf("%f %d %d",&n,&a,&d);
		result[i]=((n/2)*((2*a)+((n-1)*d)));
	}
	for(i=0;i<t;i++)
		printf("%.0f\n",result[i]);
	return 0;
}
