#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define nl '\n'

void dfs(int vertex, int parant, vector<int> graph[],  vector<int> &depth, vector<int> &height){
    for(int child: graph[vertex]){
        if(child == parant)continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex, graph, depth, height);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}


int main(){
    int v;
    cin >> v;
    // in graph edge = v -1;
    int e = v -1;
    // Using Adjacency of list
    vector<int> graph[v+1];
    while(e--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> depth(v+1),  height(v+1);
    dfs(1, 0 ,  graph, depth, height);
    cout << "S.NO   " << "Depth   " << "Height" << nl;
    for(int i = 1;i<= v; ++i){
        cout << i << "        ";
        cout << depth[i] << "       " << height[i] << endl; 
    }

    return 0;
}