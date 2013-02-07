#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
using namespace std;

struct treeNode{
	int key;
	struct treeNode* right;
	struct treeNode* left;
};

typedef struct treeNode* Link;


int main(){
	long today,j;
	int days,i;
	long long temp,max,min,sum=0;
	priority_queue <long long> maxPQ;
	priority_queue <long long> minPQ;
	cin >> days;
	for(i=0;i<days;i++){
		cin >> today;
		for(j=0;j<today;j++){
			cin >> temp;
			maxPQ.push(temp);
			minPQ.push((temp*(-1)));
		}
		max=maxPQ.top();
		min=minPQ.top()*(-1);
		cout << "Max is " << max << " and Min is " << min << endl;
		sum += (max-min);
		maxPQ.pop();
		minPQ.pop();
		for(priority_queue <long long>::iterator it=maxPQ.begin(); it!=maxPQ.end(); ++it) 
			cout << *it << endl;
	}
	cout << sum << endl;
}

int insert(long long elem){
	for(vector<long long>::iterator it=lis.begin(); it!=lis.end(); ++it){
		if(*it>elem)
			continue;
		else

	}
}