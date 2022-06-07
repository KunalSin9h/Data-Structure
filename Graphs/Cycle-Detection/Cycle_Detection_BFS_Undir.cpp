/**
 * Cycle Detection using BFS on undirected graph
 * Time : O(v + e)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <array>

#include <bits/debug.h>
    
using namespace std;

int main(){

    int v, e;
    cin >> v >> e;
    vector<vector<int>> G(v);

    while(e--){
        int x, y;
        cin >> x >> y;
        x--;y--;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    vector<bool> vis(v, false);
    
    auto Bfs = [&](int src)->bool{

        static queue<array<int, 2>> q;
        q.push({src, -1});
        vis[src] = true;

        while(!q.empty()){

            auto [node, par] = q.front();
            q.pop();

            for(int ch : G[node]){
                if(!vis[ch]){
                    vis[ch] = true;
                    q.push({ch, node});
                }
                else if (ch != par){
                    return true;
                }
            }

        } 
        return false;
    };

    for(int i = 0; i < v; ++i){
        if(!vis[i]){
            if(Bfs(i)){
                cout << "YES-Cycle Found!" << '\n';
                goto end;
            }
        }
    }

    cout << "NO-Cycle not Found!" << '\n';
    end:;

    return 0;
}

