#include <iostream>
using namespace std;
int main(){
	long long t,n,a;
	cin >> t;
	while(t--){
		cin >> n;
		a=(3*n*(n+1))/2 - n;
		a=a%1000007;
		cout << a << endl;
	}
}