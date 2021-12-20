#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

void dfs(int v, int p, vector<int> graph[], int par[]){
	par[v] = p;
	for(int child: graph[v]){
		if(child == p)continue;
		dfs(child, v, graph, par);	
	}
}

vector<int> path(int v, int par[]){
	vector<int> ans;
	while(v!=-1){
		ans.push_back(v);
		v = par[v];
	}
	reverse(begin(ans), end(ans));
	return ans;
}


int main(){
	int v;
	cin >> v;
	// Using Ajacency of list
	vector<int> graph[v+1];
	int e = v -1;
	while(e--){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int par[v+1];
	dfs(1, -1, graph, par);
	// Stores all parants of all nodes
	int x;cin >> x;
	int y;cin >> y;

	vector<int> x_path = path(x, par);
	vector<int> y_path = path(y, par);
	
	int ans = -1; // Lowest Common Ansister
	
	int s = (int) min(x_path.size(), y_path.size());
	
	for(int i =0;i<s; ++i){
		if(x_path[i] != y_path[i])
			break;		
		ans = x_path[i];
	}
	cout << ans << nl;
    return 0;
}
