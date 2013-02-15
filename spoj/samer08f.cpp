#include <iostream>
using namespace std;
int main(){
	int n,i,sum;
	while(1){
		cin >> n;
		if(n==0)
			break;
		sum=0;
		for(i=n;i>0;i--)
			sum+=((n-i+1)*(n-i+1));
		cout << sum << endl;
	}
	return 0;
}