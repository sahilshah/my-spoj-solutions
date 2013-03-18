#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<int> v;
	int n,last,rem,i;
	bool flag;
	while(1){
		cin >> n;
		if(!n)
			break;
		flag = true;
		v.resize(n);
		for(i=0;i<n;i++){
			cin >> v[i];
		}
		sort(v.begin(),v.end());
		int last = -200;
		for(i=0;i<n;i++){
			if(v[i] - last <= 200){
				last=v[i];
			}
			else{
				flag=false;
				break;
			}
		}
		if(!flag){
			cout << "IMPOSSIBLE\n";
		}
		else{
			int rem = 1422 - last;
			if(rem <=100)
				cout << "POSSIBLE\n";
			else
				cout << "IMPOSSIBLE\n";
		}
	}
}