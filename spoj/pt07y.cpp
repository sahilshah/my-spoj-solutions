#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
bool visit[10010];

bool dfs(int st, vector < vector <int> > &g){
		for( vector<int>::iterator it = g[st].begin(); it != g[st].end(); it++){
		if(!visit[*it]){
			visit[*it] = true;
			// cout << "Visiting: " << *it << '\n';
			dfs(*it,g);			
		}
	}
	return true;
}

void printGraph(vector <vector <int> >& graph, int n){
	int i;
	cout << "Graph:\n";
	for(i=0;i<n;i++){
		cout << "Node:" << i << "\tConnected to:";
		for(vector <int>::iterator it = graph[i].begin(); it!=graph[i].end();it++)
			cout << *it << '\t';
	}
	cout << '\n';
}

int main(){
	bool ans;
	vector < vector <int> > graph;
	int start,n,e,u,v,i;
	cin >> n >> e;
	if(e!=(n-1))
		cout << "NO\n";
	else{
		// vector <int> v;
		for(i=0;i<n;i++){
			graph.push_back(vector<int>(0));
			visit[i]=false;
		}
		for(i=0;i<e;i++){
			cin >> u >> v;
			u--;v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		start = 0;
		visit[start] = true;
		int i;
		ans = dfs(start,graph);
		// cout << "DFS: " << ans << '\n';
		for(i=0;i<n;i++){
			ans = ans && visit[i];
			// cout << ans << '\n';
		}
		if(ans)
			cout << "YES\n";
		else
			cout << "NO\n";
		graph.erase(graph.begin(),graph.end());
	}
}