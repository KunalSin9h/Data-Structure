#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int vertex, int parent, vector<int> graph[], vector<int> &depth){
	for(int child: graph[vertex]){
		if(child == parent)continue;
		depth[child] = depth[vertex] + 1;
		dfs(child, vertex, graph, depth);
	}
}

int main(){
	int v; cin >> v;
	int e = v -1;
	// Using Adjacency of list
	vector<int> graph[v+1];
	while(e--){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	vector<int> depth(v+1);
	// Find Max Diameter  in O(n) 
	/*  =*rule
	*	1. find the max depth of any vertex form any root
	*	2. then find max depth from that founded root
	*/
	dfs(1, -1, graph, depth);
	
	int max_depth_node;
	int max_depth = -1;
	
	for(int i = 1;i<=v; ++i){
		if(depth[i] > max_depth){
			max_depth = depth[i];
			max_depth_node = i;
		}
	}
	
	fill(begin(depth), end(depth), 0);
	dfs(max_depth_node, -1, graph, depth);
	
	max_depth = -1;
	
	for(int i = 1;i<=v; ++i){
		max_depth = max(max_depth, depth[i]);
	}
	
	cout << max_depth << endl;
	
	return 0;
}