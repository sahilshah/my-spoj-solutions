#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int arr[110],hist[110],maxW,maxV,maxF,i,n,w;
	vector <int> ht(110);
	while(1){
		cin >> n >> w;
		if(n==0 && w==0)
			break;
		for(i=0;i<110;i++){
			arr[i] = 0;
			ht[i] = 0;
		}
		maxV = -1;
		maxF = -1;
		maxW = -1;
		for(i=0;i<n;i++){
			cin >> arr[i];
			maxV = max(maxV,arr[i]);
		}
		maxW = maxV/w;
		for(i=0;i<n;i++){
			int temp = arr[i]/w;
			ht[temp]++;
			maxF=max(maxF,ht[temp]);
		}

		double sum = 0.01;
		for(i=0;i<maxW;i++)
			sum = sum + ((double)ht[i]/maxF) * ((double)(maxW-i)/maxW);
		printf("%.6f\n",sum);
	}
}