/*
                    Dijkstra's algorithm

        If *not* all edges in graph have the same weight, that we need a more general
        algorithm, like Dijkstra.
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int inf = int(1e9);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> graph[V];
    while(E--){
        int x, y, wt;
        cin >> x >> y >> wt;
        x--;y--;
        graph[x].push_back({y, wt});
        graph[y].push_back({x, wt});
    }

    vector<int> dist(V, inf);

    function<void(int)> Dijkstra_Normal = [&](int source)->void {

        dist[source] = 0;
        set<pair<int, int>> pq;
        pq.insert({0, source});

        while(!pq.empty()){
            int node = pq.begin()->second;
            pq.erase(pq.begin());

            for(auto &child: graph[node]){
                int cnode = child.first;
                int cwt = child.second;

                if(dist[node] + cwt < dist[cnode]){
                    pq.erase({dist[cnode], cnode});
                    dist[cnode] = dist[node] + cwt;
                    pq.insert({dist[cnode], cnode});
                }
            }
        }
    };

    /*
        Modified Dijkstra to enjoy 0-1 type looks like BFS. :)
    */

    function<void(int)> Dijkstra_0_1 = [&](int source)->void {

        dist[source] = 0;
        deque<int> dq;

        dq.push_back(source);

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



    return 0;
}
