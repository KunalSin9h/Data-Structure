/**
 * 7. Find all the vertices on any shortest path between a given pair of vertices 🅰️ ➡️  🅱️.
 *
 * Description : To do this, run two breadth first searches: one from 🅰️ and one from 🅱️.
 *               Let distA[] be SSSP from a.
 *               Let distB[] be SSSP from b.
 *
 *               now for every vertex(v) check if it is in the shotest path.
 *
 *               Criteria : distA[v] + distB[v] == distA[b]
 *
 *               Explanation : a -> b
 *                             a -> v | v -> b
 *                             distA[v] + distB[v]
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

    for(int i = 0, x, y; i < e; ++i){
        cin >> x >> y;
        x--;y--;
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

    for(int i = 0 ;i < v; ++i){
        if(distA[i] + distB[i] == distA[b]){
            cout << i + 1 << " \n"[i + 1 == v];
        }
    }

    return 0;
}
