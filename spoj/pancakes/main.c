#include <stdio.h>
#include <stdlib.h>
#define N 10000
#define R 10000
#define T 1000

int getMax(int *a, int size){
	int i, maxindex;
	maxindex=0;
	for(i=0;i<size;i++){
		if(a[maxindex]<a[i])
			maxindex=i;
	}
	return maxindex;
}

int getMin(int *a, int size){
	int i, minindex;
	minindex=0;
	for(i=0;i<size;i++){
		if(a[minindex]>a[i])
			minindex=i;
	}
	return minindex;
}

int main(){

	int i,j,n,r,ans,ingqua[R][N],minR[R],ingred[N],ratio[R][N];

	while(1){
		scanf("%d %d",&n,&r);
		if(n==0 && r==0){
			break;
		}
		//if(n==0){
			//printf("0 1");
			//continue;
		//}
		
		for(j=0;j<n;j++)
			scanf("%d",&ingred[j]);

		for(i=0;i<r;i++){
			for(j=0;j<n;j++){
				scanf("%d",&ingqua[i][j]);
				ratio[i][j]=(ingred[j]*10)/ingqua[i][j];			
			}
			minR[i]=getMin(ratio[i],n);
		}

		ans=0;
		for(i=0;i<r;i++){
			if(ratio[i][minR[i]]>ratio[ans][minR[ans]])	
				ans=i;
		}
		printf("%d %d",ans+1,ratio[i][minR[ans]]);
	}
	return 0;	
}
