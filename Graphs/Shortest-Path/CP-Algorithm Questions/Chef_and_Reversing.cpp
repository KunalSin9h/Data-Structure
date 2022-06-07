#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 2e9;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> graph[N];
    {
        int x, y;
        while(M--){
            cin >> x >> y;
            x--;y--;
            graph[x].push_back({y, 0});
            graph[y].push_back({x, 1});
        }
    }
    vector<int> dist(N, inf);
    function<void(int)> Bfs = [&](int source)->void{
        dist[source] = 0;
        deque<int> dq;
        dq.push_back(source);

        while(!dq.empty()){
            int node = dq.front();
            dq.pop_front();
            for(auto &child: graph[node]){
                int cn = child.first;
                int cwt = child.second;
                if(dist[node] + cwt < dist[cn]){
                    dist[cn] = dist[node] + cwt;
                    if(cwt == 1)
                        dq.push_back(cn);
                    else 
                        dq.push_front(cn);
                }
            }
        }
    };
    Bfs(0);
    cout << (dist[N-1]==inf?-1:dist[N-1]) << '\n';
    return 0;
}
