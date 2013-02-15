#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 450

int getAnswer(int,int,int**);

int getAnswer(int cur, int n, int** boolArr){
	int i,count;
	count=0;
	if(cur<0){
		printf("SOME ERROR! CHECK CODE!!\n");
		return 1;
	}
	for(i=0;i<n;i++){
		if(boolArr[i][cur]==1)
			count++;
	}
	if(n%2){
		if((count==ceil((float)n/2)) || (count==floor((float)n/2))){
			printf("Answer is : %d and %d\n",cur,count);
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		if(count==n/2){
			printf("Answer is : %d and %d\n",cur,count);
			return 1;
		}
		else{
			return 0;
		}
	}
}

int main(){
	int t,sum,ahead,mid,ahd,bk,n,i,j,k,gotA;
	int **boolArr,*aux,*a;
	scanf("%d\n\n",&t);
	while(t--){
		scanf("%d\n",&n);
		sum=0;
		a=malloc(n*sizeof(int));
		for(i=0;i<n;i++){
			scanf("%d\n",&a[i]);
			sum+=a[i];
		}
		boolArr=malloc(n*sizeof(int));
		aux=malloc((sum+1)*sizeof(int));
      	for (i=0; i<n; i++){
        	boolArr[i] = malloc((sum+1)*sizeof(boolArr[i]));
      	}
		aux[0]=1;
		for(i=0;i<n;i++){
			for(j=sum;j>=a[i];j--){
				if(aux[j-a[i]]==1){
					//printf("here %d %d\n",j,a[i]);
					boolArr[i][j]=1;
					aux[j]=1;
					for(k=0;k<i;k++){
						boolArr[k][j]=boolArr[k][j-a[i]];
					}
				}
			}
		}
		for(j=20;j<=30;j++)
			printf("%d ",j);
		printf("\n");
		for(i=0;i<n;i++){
			for(j=20;j<=30;j++){
				printf("%d ",boolArr[i][j]);
			}
			printf("\n");
		}
		mid=ceil((float)sum/2);
		printf("mid is %d\n",mid);
		ahead=1;
		ahd=0;
		bk=1;
		while(1){
			if(ahead){
				gotA = getAnswer(mid+ahd,n,boolArr);
				ahd++;
				ahead=0;
			}
			else{
				gotA = getAnswer(mid-bk,n,boolArr);
				bk++;
				ahead=1;
			}
			if(gotA){
				printf("Ye! Got the answer!\n");
				break;
			}
		}
	}
}

