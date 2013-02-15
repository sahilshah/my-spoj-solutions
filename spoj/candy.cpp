#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int n;
	long long sum=0;
	while(1){
		scanf("%d\n",&n);
		if(n==-1)
			break;
		sum=0;
		int cc=0;
		priority_queue<int> q;
		int cur;
		for(int i=0;i<n;i++){
			cin >> cur;
			sum+=cur;
			q.push(cur);
		}
		int ans=0;
		if(sum==0)
			cout << "0" << endl;
		else if(sum%n)
			cout << "-1" << endl;
		else{
			cc=sum/n;
			while((!q.empty()) && (q.top()>cc)){
				ans+=(q.top()-cc);
				q.pop();
			}
			cout << ans << endl;
		}
		while(!q.empty())
			q.pop();
	}
	return 0;
}