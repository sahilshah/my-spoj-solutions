#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long getMaxPrice(int b, int e, long long* arr, int t){
	if(b==e)
		return (arr[b]*t);
	if(b>e)
		return 0;
	long long mid;
	long long one,two;
	mid=b+floor((e-b+1)/2);
	//chose mid 
	if(mid==e)
	one=(arr[mid]*t)+max(getMaxPrice(b,mid-1,arr,t*2),getMaxPrice(mid+1,e,arr,t*2));
	//chose mid+1
	mid++;
	two=(arr[mid]*t)+max(getMaxPrice(b,mid-1,arr,t*2),getMaxPrice(mid+1,e,arr,t*2));
	return max(one,two);
}


int main(){
	long long tc,b,e,t,ns;
	long long arr[3001]={0};
	cin >> tc;
	while(tc--){
		cin >> ns;
		b=0;e=ns-1;t=1;
		cout << getMaxPrice(b,e,arr,t) << endl;
	}	
}