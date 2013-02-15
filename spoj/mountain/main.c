#include <stdio.h>
#include <stdlib.h>
#define N 200
int main(){
	int collumn[N],sum=0;
	int i,line=0,count;
	int up=0,down=0,walk=0;
	char c;
	while ((c=getchar()) != '\n')
	{
		line = line*10 + c-'0';
	}
	//printf ("%d\n",line);
	while((c=getchar())!='\n');
	for(i=0;i<line;i++){
		count=0;
		while((c=getchar())!='\n'){
			if(c==' ');
			else if(c=='\\'){
				collumn[count]=3;
				sum++;
			}
			else if(c=='/'){
				collumn[count]=1;
				sum++;
			}
			else {
				collumn[count]=2;
				sum++;
			}
			count++;
		}	
	}	
	collumn[count]=-1;

	printf("Total Walk Distance = %d\n",sum);
	i=0;

	while(collumn[i]!=-1){
		while(collumn[i]==1){
			up++;
			i++;
		}
		if(up>0)
			printf("Up %d steps\n",up);
		up=0;
		while(collumn[i]==2){
			walk++;
			i++;
		}
		if(walk>0)
			printf("Walk %d steps\n",walk);
		walk=0;
		while(collumn[i]==3){
			down++;
			i++;
		}
		if(down>0)
			printf("Down %d steps\n",down);
		down=0;
	}

	return 0;
}
