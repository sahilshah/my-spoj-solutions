#include <stdio.h>
#define INF 65535

void main(){
	int t,n,k,i,j;
	scanf("%d\n",&t);
	while(t--){
		scanf("%d %d\n",&n,&k);
	 	int price[k],sol[k],num[k];
	 	for(i=1;i<=k;i++){
	 		scanf("%d",&price[i]);
	 		//DEBUG
	 		//printf("%d",price[i]);
	 		//printf("\n");
	 	}
	 	for(i=1;i<=k;i++){
	 		sol[i]=(price[i]==-1?-1:price[i]);
	 		num[i]=(price[i]==-1?0:1);
	 		for(j=1;j<i;j++){
	 			if(((sol[i]>sol[j]+sol[i-j]) || sol[i]==-1)&& sol[j]!=-1 && sol[i-j]!=-1){
	 				if(num[j]+num[i-j]<=n){
	 					num[i]=num[j]+num[i-j];
	 					sol[i]=sol[j]+sol[i-j];
	 				}
	 			}
	 		}
	 	}
	 	printf("%d\n",sol[k]);
	}
}