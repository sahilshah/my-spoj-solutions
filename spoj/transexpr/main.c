#include <stdio.h>
#define N 400
#define T 100
int main(){
	int i,j,k,l,m,t,brackets;
	char operators[N], operandq[N];
	char expression[N], result[T][N];
	char c;
	scanf("%d\n",&t);

	for(i=0;i<t;i++){
		j=0;k=0;l=0;m=0;brackets=0;
		while((c=getchar())!='\n'){
			if(c>='a' && c<='z')
				operandq[j++]=c;
			else if(c=='(')
				brackets++;
			else if(c==')'){
				for(l=0;l<j;l++)
					result[i][m++]=operandq[l];
				result[i][m++]=operators[--k];
				brackets--;
				j=0;
			}
			else
				operators[k++]=c;
		}
		result[i][m]='\0';
	} 

	for(i=0;i<t;i++)
		printf("%s\n",result[i]);

	return 0;
}
