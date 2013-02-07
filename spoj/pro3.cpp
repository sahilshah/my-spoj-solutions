#include <iostream>
#include <sstream>
#include <set>
using namespace std;

struct more {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};

int main(){
	long today,j;
	int days,i;
	long long temp,max,min,sum=0;
	multiset<int> minBox;
	multiset<int,more> maxBox;
	multiset<int>::iterator minIt,maxIt;
	cin >> days;
	for(i=0;i<days;i++){
		cin >> today;
		for(j=0;j<today;j++){
			cin >> temp;
			minBox.insert(temp);
			maxBox.insert(temp);
		}
		minIt=minBox.begin();
		maxIt=maxBox.begin();
		min=*minIt;
		max=*maxIt;
		minBox.erase(minIt);
		minBox.erase(minBox.find(max));
		maxBox.erase(maxIt);
		maxBox.erase(maxBox.find(min));
		sum += (max-min);
	}
	cout << sum << endl;
}