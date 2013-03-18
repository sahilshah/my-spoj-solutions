#include <iostream>
#include <cstdio>
using namespace std;

// GOOD IMPLEMENTATION OF SEGMENT TREES BUT 
	// USELESS TO SOLVE THIS PARTICULAR PROBLEM :(

int getAns(int* tree, int treeSize, int k){
	int i,count=0;
	for(i=0;i<treeSize;i++){
		if(tree[i]==k){
			count++;
		}
	}
	return count;
}

void initialize(int node, int b, int e, int* tree, char* q)
{
	// tree starts from 1
	if (b == e){
		// cout << "node here " << node << " val here " << q[b-1] << '\n';
		tree[node] = (int)q[b-1]-'0';
		// cout << "node val here " << q[b-1] << '\n';

	}
	else{
		//compute the values in the left and right subtrees
		initialize(2 * node, b, (b + e) / 2, tree, q);
		initialize(2 * node + 1, (b + e) / 2 + 1, e, tree, q);
		tree[node] = tree[2*node]+tree[2*node+1];
		// cout << tree[2*node] << " and " << tree[node*2+1] << '\n';
		// cout << "node here " << node << " second val here " << tree[node] << '\n';
	}
}


int main(){
	int t,treeSize,count,n,k,i;
	static char q[1000010];
	static int tree[2000010];
	scanf("%d\n",&t);
	while(t--){
		scanf("%d %d\n",&n,&k);
		if(k>n){
			cout << "0\n";
			continue; 
		}
		scanf("%s\n",q);
		// cout << q << endl;
		count=0;
		treeSize=n*2;
		for(i=0;i<=treeSize;i++)
			tree[i]=0;
		initialize(1,1,n,tree,q);
		count=getAns(tree,treeSize,k);
		cout << count << '\n';
	}
}