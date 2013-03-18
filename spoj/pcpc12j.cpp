#include <iostream>
using namespace std;

int main(){
	int freq[101];
	int t,i,n,temp;
	cin >> t;
	// vector<int> iMax;
	while(t--){
		cin >> n;
		for(i=0;i<=100;i++)
			freq[i]=0;
		for(i=0;i<n;i++){
			cin >> temp;
			freq[temp]++;
			// cout << freq[temp] << '\n';
		}
		int ln,max;
		ln=-1;max=-1;
		for(i=0;i<=100;i++){
			if(freq[i]==0)
				continue;
			if(freq[i]%i)
				continue;
			if(freq[i]>max){
				max=freq[i];
				ln=i;
			}
			// else if(freq[i]==max){
			// 	ln=i;
			// }
			else{
				continue;
			}
		}
		cout << ln << '\n';
		// for(vector::interator it=iMax.begin();it!=iMax.end();it++){
			// if()
		// }
	}
}