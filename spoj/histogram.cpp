#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

long long getMaxHistArea(long long* h, int n, int* span){
	long long maxAr=-1;
	int i;
	for(i=0;i<n;i++)
		maxAr=max(maxAr,h[i]*span[i]);	
	return maxAr;
}
			
void updateSpan(long long* h, int n, int* span){
	stack<int> fs;
	int i;
	long long cur;
	for(i=0;i<n;i++){
		if(fs.empty()){
			fs.push(i);
			span[i]+=i;
		}
		else{
			cur=fs.top();
			if(h[cur]<h[i]){
				fs.push(i);
				span[i]+=0;
			}
			else{
				while((!fs.empty()) && (h[fs.top()]>=h[i]))
					fs.pop();
				if(fs.empty())
					span[i]+=i;
				else
					span[i]+=i-fs.top()-1;
				fs.push(i);
			}
		}
	}
	while(!fs.empty())
		fs.pop();


	for(i=n-1;i>=0;i--){
		if(fs.empty()){
			fs.push(i);
			span[i]+=n-1-i;
		}
		else{
			cur=fs.top();
			if(h[cur]<h[i]){
				fs.push(i);
				span[i]+=0;
			}
			else{
				while((!fs.empty()) && (h[fs.top()]>=h[i]))
					fs.pop();
				if(fs.empty())
					span[i]+=n-1-i;
				else
					span[i]+=fs.top()-i-1;
				fs.push(i);
			}
		}
	}
	while(!fs.empty())
		fs.pop();

}


int main(){
	int n;
	long long h[100000];
	int span[100000];
	stack<int> fs;
	int i;
	while(1){
		cin >> n;
		if(n==0)
			break;
		for(i=0;i<n;i++){
			cin >> h[i];
			span[i]=1;
		}
		updateSpan(h,n,span);
		cout << getMaxHistArea(h,n,span) << endl;
	}
	return 0;
}

