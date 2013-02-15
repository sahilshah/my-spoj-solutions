#include <stdio.h>
#define M 10000
#define N 10000
typedef struct{
	int h1;
	int h2;
	int kick=-1;
	int kicker;
}elem;

int main(){
	elem q[M];
	int hash[N];
	int qp,i,m,n,done,flag,t,nextp,iter;
	scanf("%d\n",&t);
	while(t--){
		scanf("%d %d\n",&m,&n);
		for(i=0;i<m;i++){
			scanf("%d %d\n",&q.h1,&q.h2);
			hash[qp]=-1;
		}
		qp=0;
		flag=0;
		while(1){
			if(q[qp].h1==-1){
				hash[qp.h1]=qp;
				done++;
				qp++;
			}
			else if(q[qp].h2==-1){
				hash[qp.h2]=qp;
				qp++;
				done++;
			}
			else{
				nextp=hash[qp.h2];
				hash[qp.h2]=qp;
				qp=nextp;
				if(flag)
					flag=0;
				else
					flag=1;
			}
			
			
		}
		if(done==m)
			printf("succesful hashing %d\n",done);
		else
			printf("rehash necessary %d\n",done);
	}
	return 0;
}
