#include <stdio.h>
#include <string.h>
#define N
#define T
typedef struct{
	char name[20];
	char liking;
	int delay;
	int status;
}guy;

int compareSpeed(guy *x, guy *y){
	if (x->delay<y->delay)
		return -1;
	if(x->delay==y->delay)
		return 0;
	if(x->delay>y->delay)
		return 1;
}

int compareLex(guy *x, guy *y){
	return strcmp(y->name, x->name);
}

void sortSpeed(guy *grooms, int *speed, int size){
	qsort(grooms,size,sizeof(guy),compareSpeed);
}

void sortLex(guy *grooms, int *order, int size){
	qsort(grooms,size,sizeof(guy),compareLex);
}

int main(){
	guy groom[N];
	int t,n,i,liked;
	int order[N],speed[N],result[T];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%s %d %c\n",groom[j].name,&groom[j].delay,&groom[j].liking);
			groom[j].status=1;
			if(groom[j].liking=='Y')
				liked=j;
		}
		sortLex(grooms,order, n);
		sortSpeed(grooms,speed,n);
		for(j=0;j<n;j++){
			
		}	
	
	}

	for(i=0;i<n;i++)
		printf("%d",result[i]);
	return 0;
}
