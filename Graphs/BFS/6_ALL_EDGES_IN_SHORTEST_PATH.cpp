/**
 * 6. Find all the edges that lie on any shortest path between a given pair of vertices 🅰️ ➡️  🅱️.
 *
 * Description :  To do this, run two breadth first searches: one from 🅰️. and another from 🅱️.
 *
 *                Let distA[] be the SSSP dist array from a.
 *                Let distB[] be the SSSP dist array from b.
 *
 *                now for each edges(x, y) find which is coming in shortest path from a b.
 *
 *                Criteria : distA[x] + 1 + distB[y] == distA[b]
 *
 *                Explanation : a -> b so.. distA[b]
 *                              a -> x | x -> y | y -> b
 *                              distA[x] + 1 + distB[y]
 *
 *
 * Time : O(v + e)
 **/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    
    int v, e, a, b;
    cin >> v >> e >> a >> b;
    a--;b--;

    vector<vector<int>> G(v);
    vector<pair<int, int>> edges;

    for(int i = 0, x, y; i < e; ++i){
        cin >> x >> y;
        x--;y--;
        edges.emplace_back(make_pair(x, y));
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    vector<bool> vis(v, false);
    vector<int> distA(v), distB(v);

    auto Bfs = [&](int src, auto& distT)->void{
        static queue<int> q({src});
        distT[src] = 0;
        vis[src] = true;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(int ch : G[node]){
                if(!vis[ch]){
                    vis[ch] = true;
                    distT[ch] = distT[node] + 1;
                    q.push(ch);
                }
            }
        }
    };

    Bfs(a, distA);
    fill(vis.begin(), vis.end(), false);
    Bfs(b, distB);

    for(auto &[x, y] : edges){
        if(distA[x] + 1 + distB[y] == distA[b] || distA[y] + 1 + distB[x] == distA[b]){
            cout << x + 1 << ' ' << y + 1 << '\n';
        }
    }

    return 0;
}
