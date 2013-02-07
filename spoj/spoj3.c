#include <stdio.h>
#define MAX_LEN 1000001
char string[MAX_LEN];
int main(){
	int m;
	while(1){
		scanf("%d\n",&m);
		if(m==0)
			return 0;
		else{
			char c;
			int max=0,cols=0,i=0,a=0,b=0,uni=0;		//a and b: front and back pointers
			int hash[128]={0};
			int countArr[128]={0};
			while((c=getchar())!='\n'){
				string[i]=c;
				i++;
				if(countArr[(int)c%128]){
					cols++;
				}
				else{
					uni++;
				}
				countArr[(int)c%128]++;
				while((b-a)==m+cols){
					if(countArr[(int)string[a]%128]>1){
						cols--;
						countArr[(int)string[a]%128]--;
						a++;
					}
					else{
						countArr[(int)string[a]%128]--;
						a++;	
						uni--;
					}
				}
				if((uni+cols)>max)
					max=uni+cols;
				b++;
			}
			printf("%d\n",max);
		}
	}
}