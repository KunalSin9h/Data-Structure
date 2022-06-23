#include <bits/stdc++.h>
using namespace std;

/*
    Applications of BFS

    2. Find all connected components in an undirected graph in O(n + m) time

    : To do this, we just run BFS starting from each vertex, except for vertices which have already been visited from previous runs. Thus, we perform normal BFS from each of the 
    vertices, but do not reset the array each and every time we get a new connected component, and the total running time will still be (performing multiple BFS on the graph without 
    zeroing the array is called a series of breadth first searches)

    Time = O(n + m)
    
    n : Bfs
    m = while(E--)

*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int V, E;
    cin >> V >> E;
    vector graph(V, vector<int>(0));

    {
        int x, y;
        while(E--){
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }

    vector<bool> vis(V, false);

    function<void(int)> Bfs = [&](int source) -> void { 
        vis[source] = true;
        queue<int> q({source});

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(const int &c : graph[node]){
                if(!vis[c]){
                    vis[c] = true;
                    q.push(c);
                }
            }
        }
    };

    int con_comp = 0;
    for(int i = 0;i<V; ++i){
        if(!vis[i]){
            con_comp++;
            Bfs(i);
        }
    }
    cout << con_comp << '\n';
    return 0;
}