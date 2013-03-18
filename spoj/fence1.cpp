#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	int l;
	while(1){
		cin >> l;
		if(!l)
			break;
		float ans;
		ans=(float)((l*l)/(4*acos(0.0)));
		printf("%.2f\n",ans);
	}
}