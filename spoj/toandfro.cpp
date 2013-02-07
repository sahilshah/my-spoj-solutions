#include <iostream>
#include <string>
using namespace std;

int main(){
	int t,i,j,numcols,numrows;
	string encS,decS;	
	while(1){
		cin >> numcols;
		if(!numcols)
			break;
		cin >> encS;
		numrows=(encS.length()/numcols);
		for(i=0;i<numcols;i++){
			for(j=0;j<numrows;j++){
				if(j%2)
					decS.push_back(encS[(numcols*(j+1))-i-1]);
				else
					decS.push_back(encS[(numcols*j)+i]);
			}
		}
		cout << decS << endl;
		encS.clear();
		decS.clear();
	}	
}