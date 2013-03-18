#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int count = 0;

bool comparator (int i,int j) {
    if(i<j){
        count++; 
        return true;
    }
    else
        return false;
}

int main () {
    int myints[] = {32,71,12,45,26,80,53,33};
    vector<int> myvector (myints, myints+8);

    // count = 0;
    sort (myvector.begin(), myvector.end(), comparator());     //(12 26 32 33 45 53 71 80)

    // print out content:
    cout << "myvector contains:";
    for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        cout << ' ' << *it;
    cout << "Inversions: " << comparator.count <<'\n';

    return 0;
}