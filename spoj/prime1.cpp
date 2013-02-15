#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long n,m;
		vector <long> pns;
		pns.push_back(2);
		bool flag;
		vector<long>::iterator it;
		cin >> m >> n;
		if(m<=2)
			cout << "2" << endl;
		for(long j=3;j<=n;j++){
			flag=false;
			long sq=(long)sqrt(j);
			for(it=pns.begin(); (*it)<=sq; it++){
				if((j%(*it)) == 0){
					flag=true;
					break;
				}
			}
			if(!flag){
				pns.push_back(j);
				if(j>=m)
					cout << j << endl;
			}
		}
		cout << endl;
	}
	return 0;
}