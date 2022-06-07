#include <bits/stdc++.h>
using namespace std;

/*
Breadth-first search

Breadth first search is one of the basic and essential searching algorithms on graphs.

Applications of BFS

    1. find the shortest path from a source to other vertices in an unweighted graph. (Classic Application)
    time -> O(n + m)
    n -> number of vertex
    m -> number of Edges

    n : while(!q.empty())
    m : while(E--)

*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int V, E;
    cin >> V >> E;

    vector graph(V, vector<int>());
    int x, y;
    while(E--){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // Find the shotest path for every node from source in un-weighted graphs

    vector<int> dist(V);
    vector<bool> vis(V, false);
    vector<int> parent(V);
    parent[0] = -1;
    vis[0] = true;
    dist[0] = 0;
    queue<int> bfs({0}); // source vertex
    
    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        for(const int &c: graph[node]){
            if(!vis[c]){
                dist[c] = dist[node] + 1;
                parent[c] = node;
                bfs.push(c);
                vis[c] = true;
            }
        }
    }
    int t;
    cin >> t;
    cout << "Shotest Path from 0  is -> " << dist[t] << '\n';
    cout << "Path:" << '\n';
    vector<int> trace;
    for(int i = t ; i != -1 ; i = parent[i]) {
        trace.push_back(i);
    }

    for(auto it = trace.rbegin(); it != trace.rend(); it++){
        cout << *it << " \n"[it == trace.rend()];
    }    

    cout << '\n';
    return 0;
}
