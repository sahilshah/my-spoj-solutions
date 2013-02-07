#include <iostream>
using namespace std;
 
int main(){
	int a,b,c;
	while(1){
		cin >> a >> b >> c;
		if(a | b | c){
			if((a+c)==(2*b)){
				cout << "AP " << c+(b-a) << endl;
			}
			else{
				cout << "GP " << c*(b/a)  << endl;
			}
		}
		else
			break;
	}
} 