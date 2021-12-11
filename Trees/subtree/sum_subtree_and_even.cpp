#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

void dfs(int vertex, int parant, vector<int> graph[], int subTree[], int even[]){

    if(vertex % 2 == 0)even[vertex]++; // When Entering the vertex
    subTree[vertex] += vertex;
    for(int child: graph[vertex]){
        if(child == parant)continue;
        dfs(child, vertex, graph, subTree, even);

        subTree[vertex] += subTree[child];// When exiting the child
        even[vertex] += even[child];
    }
}

int main(){
    int v;
    cin >> v;
    // in graph edge = v -1;
    int e = v - 1;
    // Using Adjacency of list
    vector<int> graph[v+1];
    while(e--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    int subTree[v+1] = {0}; // SubTree[i] C~ the sum of subTree of take i as root
    int even[v+1] = {0}; 
    // Art of DFS 
    dfs(1, 0, graph, subTree, even);
    for(int i = 1;i<=v; ++i){
        cout <<  subTree[i] << " " << even[i] << '\n';
    }
    cout << endl;

    return 0;
}