#include <stdio.h>
#define MAX_SUM 10000
void main(){
	int totNums;
	int num[totNums];
	int sumPos[MAX_SUM];
	sumPos[0]=1;
	rMost = 0;	//avoid checking 0 entries, so start with rightmost 1
	for(i=0;i<totNums;i++){
		for(j=rMost;j>0;j--){		//test all possible sums which can be highest sum - cureElem
			if(sumPos[j]==1)
				sumPos[j+num[i]]=1;
			if(MAX_SUM/2 > rMost+num[i])
				rMost = rMost + num[i];
		}
	}
	return sumPos[MAX_SUM/2];
}