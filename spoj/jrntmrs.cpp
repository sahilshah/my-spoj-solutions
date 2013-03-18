#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long diff[1000020]={0};
bool ans[1000020]={false};
int main(){
	long long n,st,j,i,f,d,sum;
	bool flag;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> f >> d;
		diff[i] = f-d;
		// cout << diff[i] << '\n';
	}
	st = 0;
	while (st<n){
		flag = false;
		i = st;
		sum = 0;
		while (sum + diff[i] >= 0) {
			sum += diff[i];
			i++;
			if (i%n == st){
				flag = true;
				break;
			}
		}
		if (flag){
			ans[st] = true;
			st++;
		}
		else{
			for (j=st;j<=i;j++)
				ans[j] = false;
			st = i+1;		
		}
	}

	for (i=0;i<n;i++)
		if(ans[i])
			cout << "TAK\n";
		else
			cout << "NIE\n";
}