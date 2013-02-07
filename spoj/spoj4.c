#include <stdio.h>

int main(){
	while(1){
		int n1,n2;
		scanf("%d",&n1);
		if(n1==0)
			return 0;
		else{
			//get input
			int i,j,end1,end2,sum1,sum2,sum;
			int arr1[n1];
			for(i=0;i<n1;i++)
				scanf("%d",&arr1[i]);
			scanf("\n%d",&n2);
			int arr2[n2];
			//DEBUG
			//printf("%d %d\n",n1,n2);
			for(i=0;i<n2;i++)
				scanf("%d",&arr2[i]);
			//end of input
				i=0;j=0;
				end1=0;end2=0;
				sum1=0;sum2=0;sum=0;
			while(1){
				//printf("yes");
				while((arr1[i]<arr2[j]) && !end1){
					sum1+=arr1[i];
					i++;
					if(i==n1)
						end1=1;
					//printf("one");
				}
				while((arr1[i]>arr2[j]) && !end2){
					sum2+=arr2[j];
					j++;
					if(j==n2)
						end2=1;
					//printf("two");
				}
				while(arr1[i]==arr2[j]){
					sum+=arr1[i];
					i++;j++;
					if(sum1>sum2)
						sum+=sum1;
					else
						sum+=sum2;
					sum1=0;sum2=0;
					if(i==n1){
						end1=1;
						break;
					}
					if(j==n2){
						end2=1;
						break;
					}
					//printf("%d\n",sum);
					//printf("three\n");
					//printf("%d %d\n",i,j);
				}
				if(end1){
					while(j<n2){
						sum2+=arr2[j];
						j++;
					}
					if(sum2>sum1)
						sum+=sum2;
					else
						sum+=sum1;
					break;
				}
				if(end2){
					while(i<n1){
						sum1+=arr1[i];
						i++;
					}
					if(sum2>sum1)
						sum+=sum2;
					else
						sum+=sum1;
					break;
				}
			}
			printf("%d\n",sum);
		}
	}
}
