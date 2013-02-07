#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main(){
	long today,j;
	int days,i;
	long long temp,max,min,sum=0;
	multiset<int> box;
	multiset<int>::iterator it;
	cin >> days;
	for(i=0;i<days;i++){
		cin >> today;
		for(j=0;j<today;j++){
			cin >> temp;
			box.insert(temp);
		}
		it=box.begin();
		min=*it;
		box.erase(it);
		it=box.begin();
		int size = box.size();
		for(int i=0;i<size-1;i++,it++);
		max=*it;
		box.erase(it);
		sum += (max-min);
	}
	cout << sum << endl;
}