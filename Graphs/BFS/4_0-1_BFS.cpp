/*
    4. BFS to solve the SSSP (single-source shortest path) problem in O(|E|) or O(V + E)
    if the weight of each edge is either 0 or 1.

    when we modify the Dijkstra to accommodate benefits for only 0-1 weight, then it look like what we call it 0-1 BFS

*/

#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 2e9;

int main(){

    int V, E;
    cin >> V >> E;

    vector<pair<int,int>> graph[V];
    while(E--){
        int x, y, wt;
        cin >> x >> y >> wt;
        x--;y--;
        graph[x].push_back({y, wt});
        graph[y].push_back({x, wt});
    }

    vector<int> dist(V, inf);

    function<void(int)> BFS_0_1 = [&](int source) -> void{
        dist[source] = 0;
        deque<int> dq({source});

        while(!dq.empty()){
            int node = dq.front();
            dq.pop_front();
            for(auto &child: graph[node]){
                int cnode = child.first;
                int cwt = child.second;
                if(dist[node] + cwt < dist[cnode]){
                    dist[cnode] = dist[node] + cwt;
                    if(cwt == 1)
                        dq.push_back(cnode);
                    else
                        dq.push_front(cnode);
                }
            }
        }
    };

    BFS_0_1(0);
	cout << dist[V-1] << '\n';
    return 0;
}
