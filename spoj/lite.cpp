#include <iostream>
using namespace std;

int update(int node, int b, int e, int* M, bool* needsUpdate, int i, int j){
	int p1,p2;
	if(e<i || b>j){
		if(needsUpdate[node]){
			M[node]=(e-b+1)-M[node];
			needsUpdate[node]=false;
		}
		return M[node];		
	}

	if((i==b) && (j==e)){
		if(needsUpdate[node])
			needsUpdate[node]=false;
		else
			M[node]=(e-b+1)-M[node];
		needsUpdate[node*2]=1^needsUpdate[node*2];
		needsUpdate[node*2+1]=1^needsUpdate[node*2+1];		
		return M[node];
	}

	if(b<=i && e>=j){	
		p1=update(node*2,b,(b+e)/2,M,needsUpdate,i,j<((b+e)/2)?j:((b+e)/2));
		p2=update(node*2+1,(b+e)/2+1,e,M,needsUpdate,((b+e)/2+1)<i?i:((b+e)/2+1),j);
		M[node]=p1+p2;
		needsUpdate[node]=false;
		return M[node];
	}
}

int query(int node,int b, int e, int* M, bool* needsUpdate, int i, int j){
	int p1,p2;
	if(j<b || i>e)
		return 0;
	
	if(i==b && j==e){
		if(needsUpdate[node]){
			needsUpdate[node]=0;
			M[node]=(e-b+1)-M[node];
		}
		return M[node];
	}

	if(b<=i && e>=j){
		//split interval
		p1=query(node*2,b,(b+e)/2,M,needsUpdate,i,j<((b+e)/2)?j:((b+e)/2));
		p2=query(node*2+1,(b+e)/2+1,e,M,needsUpdate,((b+e)/2+1)<i?i:((b+e)/2+1),j);
		return p1+p2;
	}
}

int main(){
	int cStalls,cOps,opcode,i;
	int stall[70000]={0};		//starts from 1
	bool needsUpdate[70000]={false};		//starts from 1, all false 
	cin >> cStalls;
	cin >> cOps;
	int start,end;
	for(i=0;i<cOps;i++){
		cin >> opcode;
		cin >> start;
		cin >> end;
		int ans;
		if(opcode){
			ans = query(1,1,cStalls,stall,needsUpdate,start,end);
			cout << ans << endl;
		}
		else{
			ans = update(1,1,cStalls,stall,needsUpdate,start,end);
		} 
	}
}