#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000

void reverse(char s[]){
	int i, j;
	char c;
 
   for(i=0, j=strlen(s)-1;i<j;i++,j--){
      c = s[i];
      s[i] = s[j];
      s[j] = c;
   }
}

long int revInt(long int x){
	long int y=0,t;
	do{
		t=x%10;
		x=x/10;	
		y=(y*10)+t;
	}while(x!=0);
	return y;
}

long int remLeadZ(long int x){
	while(!(x%10))
		x=x/10;
	return x;
}

int main(){
	char first[100],second[100];
	long int result[N];
	long int fint,sint,rint;
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s",first);
		scanf("%s",second);
		reverse(first);
		reverse(second);		
		fint=atoi(first);
		sint=atoi(second);
		fint=remLeadZ(fint);
		sint=remLeadZ(sint);
		rint=fint+sint;
		result[i]=revInt(rint);
	}

	for(i=0;i<t;i++)
		printf("%ld\n",result[i]);
	return 0;
}

