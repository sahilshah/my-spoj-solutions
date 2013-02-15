#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double getDistance(double x1, double y1, double x2, double y2){
	double z;
	z=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
	return z;
}

int main(){
	char c;
	double x1,y1,x2,y2;
	double sum=0;
	int started=0;
	while((c=getchar())!=EOF){
		if(c!='(')
			continue;
		else{
			if(started==0){
				scanf("%lf",&x1);
				c=getchar();
				scanf("%lf",&y1);
				started=1;
				continue;
			}
			else{
				scanf("%lf",&x2);
				c=getchar();
				scanf("%lf",&y2);
				sum=sum+getDistance(x1,y1,x2,y2);
				printf("The salesman has traveled a total of %.3lf kilometers.\n",sum);
				x1=x2;
				y1=y2;
			}
		}
	}

	return 0;
}

