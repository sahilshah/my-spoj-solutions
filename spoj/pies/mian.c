#include <stdio.h>

int main(){
	int n,a,d,t,i;
	scanf("%d",&t);
	int result[t];
	for(i=0;i<t;i++){
		scanf("%d %d %d",&n,&a,&d);
		result[i]=(n/2)*((2*a)+((n-1)*d));
	}
	for(i=0;i<t;i++)
		printf("%d",result[i]);
}
