#include <stdio.h>
#define N 2005
int array[2005][2005];
int p=0,q=0;
int main(){
	int t,i,j,k,a,n;
	int value[N];
	int result;
	
	scanf("%d\n",&n);
	for(j=0;j<n;j++)
		scanf("%d",&value[j]);
	j=0;
	k=n-1;
	a=1;
	result=getResult(value, j, k, a);
	printf("%d\n",result);
	return 0;
}

int getResult(int *value, int j, int k, int a){
	int result=0;
	if (array[j][k])
		return array[j][k]	;
		int one,two;
	if(j<=k){
		one=getResult(value,j+1,k,a+1)+(value[j]*a);
		two=getResult(value,j,k-1,a+1)+(value[k]*a);
		if(one>=two){
			result+=one;
		}
		else{
			result+=two;
		}
	}
	array[j][k] = result;
	return result;
}
