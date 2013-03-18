#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[2002][2002];
int main(){
	char s1[2002],s2[2002];	//edit distance: s1 to s2
	int t,i,j,val,temp1,temp2;
	cin >> t;
	while(t--){
		scanf("%s\n",s1);
		scanf("%s\n",s2);
		//cout << s1 << endl;
		//cout << s2 << endl;
		int n1=strlen(s1),n2=strlen(s2);
		dp[0][0]=0;
		//cout << n1 << "\t" << n2 << endl;
		for(i=1;i<n1;i++)dp[i][0]=i;		//cost of any i to 0 len is i
		for(j=1;j<n2;j++)dp[0][j]=j;		//cost of 0 to any j len is j

		for(i=1;i<=n1;i++){
			for(j=1;j<=n2;j++){		//index of ith char of string is i-1
				val=(s1[i-1]==s2[j-1]) ? 0:1;			//to replace or not to replace
		        temp1=min(dp[i-1][j]+1,dp[i][j-1]+1);	//delete, insert ops
	        	temp2=dp[i-1][j-1]+val;					
	        	dp[i][j]=min(temp1,temp2);				//min of all 3
			}
		}
		cout << dp[n1][n2] << endl;
	}
}