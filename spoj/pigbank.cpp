#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;
int dp[10010];
int main(){
	int t;
	scanf("%d\n",&t);
	while(t--){
		int wepb,wpb,W;
		scanf("%d %d\n",&wepb,&wpb);
		W=wpb-wepb;
		int coins;
		scanf("%d\n",&coins);
		int i,j;
		int wt[510],val[510];
		// cout << "weight " << W << "coins " << coins << '\n';
		for(i=1;i<=W;i++)
			dp[i]=9999999;
		dp[0]=0;
		for(i=0;i<coins;i++){
			scanf("%d %d\n",&val[i],&wt[i]);
			dp[wt[i]]=val[i];
			// cout << wt[i] << '\t' << val[i] <<'\n';
		}
		int changed;
		for(i=0;i<=W;i++){
			// changed=0;
			for(j=0;j<coins;j++){
				if(i-wt[j]>=0){
				// printf("%d %d %d\n",i,j,i-j);
				// cout << "DP[i] " << dp[i] << "\tDP[j] " << dp[j] << 
					// "\tDP[i-j]" << dp[i-j] << '\n';
					if(dp[i]>dp[i-wt[j]]+val[j]){
						dp[i]=dp[i-wt[j]]+val[j];
						//changed=1;
					}
					// dp[i]=min(dp[i],dp[i-wt[j]]+val[j]);
				}
			}
			// if(changed==0)
				// dp[i]=5000000;
		}

		if(dp[W]<9999999)
			cout << "The minimum amount of money" 
				<< " in the piggy-bank is " << dp[W] << ".\n";
		else
			cout << "This is impossible." << '\n';
	}
}