#include <stdio.h>
#include <math.h>

int main(){
	int t,x,i,sum=0;
	scanf("%d",&t);
	while(t){
		x=sqrt(t);
		for(i=1;i<=x;i++){
			if(!(t%i))
				sum++;
		}
		t--;
	}
	
	printf("%d",sum);

	return 0;
}
