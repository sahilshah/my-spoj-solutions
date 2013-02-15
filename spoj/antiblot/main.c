#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100

int checkMachula(char *temp){
	char *temp2;
	temp2=temp;
	while(*temp2!='\0'){
		if(*temp2=='m')
			return 1;
		temp2++;
	}
		return 0;
}

int main(){
	int t,i;
	long int x[N],y[N],z[N];
	char one[N],two[N],three[N],plus[2],equal[2];
	scanf("%d",&t);

	for(i=0;i<t;i++){
		scanf("\n%s %s %s %s %s\n",one,plus,two,equal,three);

		if(checkMachula(one)){
			y[i]=atoi(two);
			z[i]=atoi(three);
			x[i]=z[i]-y[i];
		}
		else if(checkMachula(two)){
			x[i]=atoi(one);
			z[i]=atoi(three);
			y[i]=z[i]-x[i];
		}
		else{
			x[i]=atoi(one);
			y[i]=atoi(two);
			z[i]=x[i]+y[i];
		}
	}

	for(i=0;i<t;i++)
		printf("%ld + %ld = %ld\n",x[i],y[i],z[i]);
	return 0;
}


