#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
	int a,cur,count,expect;
	stack<int> st;
	while(1){
		cin >> a;
		if(a==0)
			break;
		expect=1;
		count=0;
		//clear stack
		while(!st.empty()){
			st.pop();
		}
		while(1){
			//check stack till equality
			while(!st.empty() && st.top()==expect){
				expect++;
				st.pop();
			}
			//read new
			if(count<a){
				cin >> cur;
				count++;
			}
			else{
				if(st.empty())
					cout << "yes" << endl;
				else
					cout << "no" << endl;
				break;
			}
			//check to consume cur
			if(cur==expect)
				expect++;
			else
				st.push(cur);
		}
	}
}