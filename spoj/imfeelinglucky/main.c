#include <stdio.h>
#define N 100

typedef struct{
	char name[N+1];
	int relevance;
}website;

int main(){
	int i,t,j,k,max,maxrel[10];
	scanf("%d",&t);
	website data[t][10];
	for(i=0;i<t;i++){
		for(j=0;j<10;j++)
			scanf("%s %d",data[i][j].name,&data[i][j].relevance);
/*		k=0;
		for(j=0;j<10;j++)
			maxrel[j]=0;
		for(j=1;j<10;j++){
			if(data[i][j].relevance==data[i][maxrel[0]].relevance)
				maxrel[k++]=j;
			if(data[i][j].relevance>data[i][maxrel[0]].relevance){
				maxrel[0]=j;
				k=1;
			}
		}
*/
		k=0;
		max=data[i][0].relevance;
		for(j=0;j<10;j++){
			if(data[i][j].relevance>=max)
				max=data[i][j].relevance;
		}

		for(j=0;j<10;j++){
			if(data[i][j].relevance==max){
				maxrel[k]=j;
				k++;
			}
		}
		maxrel[k]=-1;
		printf("Case #%d:\n",i+1);
		for(j=0;maxrel[j]!=-1;j++)
			printf("%s\n",data[i][maxrel[j]].name);
	}

	return 0;
}



