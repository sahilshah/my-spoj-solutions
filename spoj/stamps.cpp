#include <iostream>
#include <queue>
using namespace std;

int main(){
	int t,n,m;
	priority_queue<int> q;
	cin >> t;
	for(int j=1;j<=t;j++){
		cin >> n >> m;
		int x=0;
		for(int i=0;i<m;i++){
			cin >> x;
			q.push(x);
		}
		int sum=0;
		int count=0;
		while((sum<n) && (!q.empty())){
			sum+=q.top();
			q.pop();
			count++;
		}
		cout << "Scenario #" << j << ":" << endl;
		if(sum>=n)
			cout << count << endl << endl;
		else
			cout << "impossible" << endl << endl;
		while(!q.empty())
			q.pop();		
	}
	return 0;
}