#include <stdio.h>
#include <stdlib.h>
#define N 10000

int main(){
	int i,j,l,n,m,n1,n2,k,t=0,sum,sumequal;
	int a[N]={0},b[N]={0},c[N]={0},d[N]={0},equal[N]={0},result[N]={0};

	while(1){
		scanf("%d",&n1);
		if(n1==0)
			break;
		t++;
		for(j=0;j<n1;j++){
			scanf("%d",&a[j]);
			printf("%d",a[j]);
		}
		scanf("%d",&n2);
		for(j=0;j<n2;j++){
			scanf("%d",&b[j]);
			printf("%d",b[j]);
		}
		sum=0;sumequal=0;
		i=0;j=0;k=0;l=0;n=0;

		while(i<n1 && j<n2){
			if(a[i]==b[j]){
				if(i==0)
					c[0]=0;
				if(j==0)
					d[0]=0;
				equal[n]=a[i];
				i++;
				j++;
				n++;
				k++;
				l++;
			}
			else if(a[i]>b[j]){
				d[l]=d[l]+b[j];
				j++;
			}
			else{
				c[k]=c[k]+a[i];
				i++;
			}
		}
		
		while(i<n1){
			c[k]=c[k]+a[i];
			i++;
		}
		
		while(j<n2){
			d[l]=d[l]+b[j];
			j++;
		}
		
		for(i=0;i<=n;i++)
			sumequal=sumequal+equal[i];

		i=0;
		j=0;
		
		while(i<=k && j<=l){
			if(c[i]>=d[j]){
				sum=sum+c[i];
				i++;
				j++;
			}
			else
				sum=sum+d[j];
		}

		if(i<=k)
			sum=sum+c[i];
		if(j<=l)
			sum=sum+d[j];

		result[m]=sum+sumequal;
	}

	for(m=0;m<t;m++)
		printf("%d\n",result[m]);

	return 0;
}


