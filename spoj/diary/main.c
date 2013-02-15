#include <stdio.h>
#define N 1000
#define T 100
int main(){
	char c,*entry[T];
	int i,j,k,t,max;
	int mind[T];
	int alphabucket[26];
	int poss[T],difference[T],maxindex[T];
	scanf("%d",&t);	
	for(i=0;i<t;i++){
		for(j=0;j<26;j++)
			alphabucket[j]=0;
		poss[i]=1;
		while((c=getchar())!='\n'){
			*entry[i]++=c;
			if(isalpha(c))
				alphabucket[c-'A']++;
		}
		*entry[i]='\0';
		max=alphabucket[0];
		for(j=1;j<26;j++){
			if(alphabucket[j]>max)
				maxindex[i]=j;
			if(alphabucket[j]==max)
				poss[i]=0;
		}
		difference[i]=maxindex[i]-4;		
	}

	for(i=0;i<t;i++){
		if(poss[i]==0)
			printf("NOT POSSIBLE\n");
		else
			while(*entry[i]!='\0'){
				*entry[i]=*entry[i]-difference[i];
				putchar(*entry[i]++);
			}
		printf("\n");
	}

	return 0;
}

