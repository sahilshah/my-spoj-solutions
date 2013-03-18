#include <iostream>
using namespace std;

int main(){
	int num,mult,rn,q,r;
	while(cin >> num){
		if(num==1){
			cout << "0 0\n" ;
			continue;
		}
		num--;
		mult=6;
		rn=1;
		while(num>mult){
			num=num-mult;
			mult=mult+6;
			rn++;
		}
		r=num%rn;
		q=num/rn;
		switch(q){
			case 0:		//corner (rn,0)
				cout << rn-r << " " << r << '\n';
				break;
			case 1:		//corner (0,rn)
				cout << -r << " " << rn << '\n';
				break;
			case 2:		//corner (-rn,rn)
				cout << -rn << " " << rn-r << '\n';
				break;
			case 3:		//corner (-rn,0)
				cout << -rn+r << " " << -r << '\n';
				break;
			case 4:		//corner (0,-rn)
				cout << r << " " << -rn << '\n';
				break;
			case 5:		//corner (rn,-rn)
				cout << rn << " " << -rn+r << '\n';
				break;
			case 6:		//corner (rn,0) (CHECK REPETITION)
				cout << rn-r << " " << r << '\n';
				break;
		}
	}
}