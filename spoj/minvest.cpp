#include <stdio.h>
//#include <iostream>
//using namespace std;
int main(){
	long long dp[90100];
	int t=0,x=0,y=0,n=0,i=0,c=0,k=0,j=0,prevx=0;
	long long amt=0;
	int cost[20]={0},val[20]={0};
	scanf("%d\n",&t);
	while(t--){
		scanf("%d %d\n",&amt,&y);
		scanf("%d\n",&n);
		int cb=0,vb=0;
		for(i=0;i<n;i++){
			scanf("%d %d",&cb,&vb);
			cost[i]=cb/1000;
			val[i]=vb;
		}
		// dp[0]=0;
		for(i=0;i<90100;i++)
			dp[i]=0;
		// for(i=0;i<n;i++)
			// cost[i]=cost[i]/1000;
		for(i=0;i<n;i++)
			dp[cost[i]]=val[i];
		prevx=0;
		for(k=0;k<y;k++){
			// cout << "Amt is " << amt << endl;
			x=(int)(amt/1000);
			// cout << "X and PrevX is " << x << "\t" << prevx << endl;
			for(c=prevx;c<=x;c++){
				for(j=0;j<n;j++){
					if((c-cost[j])>=0){
						if(dp[c] < (dp[c-cost[j]]+val[j]))
							dp[c] = dp[c-cost[j]]+val[j];
					}
				}
			}
			amt += dp[x];
			prevx = x;
		}
		printf("%d\n",amt);
	}
}