#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int t,x,y,n,i,c,k,j,prevx,amt;
	int cost[10],val[10];
	scanf("%d\n",&t);
	while(t--){
		int dp[50000]={0};
		scanf("%d %d\n",&amt,&y);
		scanf("%d\n",&n);
		for(i=0;i<n;i++)
			scanf("%d %d\n",&cost[i],&val[i]);
		// dp[0]=0;
		//for(i=0;i<50000;i++)
		//	dp[i]=0;
		// for(i=0;i<n;i++)
			// cost[i]=cost[i]/1000;
		for(i=0;i<n;i++)
			dp[cost[i]/1000]=val[i];
		prevx=0;
		for(k=0;k<y;k++){
			cout << "Amt is " << amt << endl;
			x=(int)(amt/1000);
			cout << "X is " << x << endl;
			for(c=prevx;c<=x;c++){
				for(j=c;j>0;j--){
					if(dp[c]<dp[c-j]+dp[j])
						dp[c]=dp[c-j]+dp[j];
				}
			}
			amt+=dp[x];
			prevx=x;
		}
		printf("%d\n",amt);
	}
}
