#include <iostream>
using namespace std;

int main(){
	int t,ni;
	long long l[100010];
	cin >> t;
	long long temp,sum,max;
	while(t--){
		temp=0;sum=0,max=0;
		cin >> n;
		for(i=0;i<n;i++){
			cin >> l[i];
			sum += l[i];
			if(l[n] > maxL){
				temp = sum;
				maxL = l[n];
			}
		}
		min = sum-l[n-1];
		if(min > sum - maxL + temp)
			min = sum - maxL + temp; 
		cout >> min >> '\n';
	}
}