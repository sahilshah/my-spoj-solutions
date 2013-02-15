#include <math.h>
#include <stdio.h>
#define T 2000
int main(){
	int i,t;
	double s,a,b,c,d;
	double temp,result[T];
	scanf("%d",&t);
	
	for(i=0;i<t;i++){
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		s=(a+b+c+d)/2;
		temp=((s-a)*(s-b)*(s-c)*(s-d));
		result[i]=sqrt(temp);
	}

	for(i=0;i<t;i++)
		printf("%.2lf\n",result[i]);
	return 0;
}
