#include <iostream>
using namespace std;

int main(){
	int m,n,o,t;
	while(1){
		cin >> m >> n >> o;
		if(m==0 && n==0 && o==0)
			break;
		if(o<m){
			t=o;
			o=m;
			m=t;
		}
		if(o<n){
			t=o;
			o=n;
			n=t;	
		}
		if((m*m + n*n)== o*o )
			cout << "right\n";
		else
			cout << "wrong\n";	
	}
}