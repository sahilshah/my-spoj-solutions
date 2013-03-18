#include <iostream>
#include <algorithm>
#define MAX 100009
using namespace std;
int INF = 0x7f7f7f7f;

int L[MAX];
int main() {
	int t, i, n, sum, mn, res, x, y;
	cin >> t;
	while(t--) {
	    cin >> n;
	    for(i = 0; i < n; i++) {
	        cin >> L[i];
	    }
	    sum=0;
	    for(i = 0; i < n; i++) 
	    	sum += L[i];
	    x=0;
	    res = 1000000002;
	    for(i = 0; i < n; i++) {
            y = sum - x - L[i];
            mn = 2*min(x,y) + max(x,y);
            res = min(res, mn);
            x += L[i];
	    }
	    cout << res << endl;
	}
	return 0;
}