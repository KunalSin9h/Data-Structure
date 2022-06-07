#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

#include <bits/debug.h>

using namespace std;

int main(){

    int T;cin >> T;
    while(T--){

        int N, E, M;
        cin >> N >> E >> M;

        vector<vector<int>> G(N);
        while(E--){
            int x, y;
            cin >> x >> y;
            x--;y--;
            G[x].emplace_back(y);
            G[y].emplace_back(x);
        }
        
        vector<array<int, 2>> a(M);
        for(int i = 0; i < M; ++i){
            cin >> a[i][0] >> a[i][1];
            a[i][0]--;
        }
        
        vector<bool> vis(N, false);
        vector<int> d(N);

        auto Bfs = [&](int src, int pow)->bool{

            if(vis[src])return false;
            queue<array<int, 2>> q;
            q.push({src, -1});

            vis[src] = true;
            while(!q.empty()){
                int node = q.front()[0];
                int par = q.front()[1];
                q.pop();
                for(int ch : G[node]){
                    if(!vis[ch]){
                        vis[ch] = true;
                        d[ch] = d[node] + 1;
                        if(d[ch] > pow){
                            vis[ch] = false;
                            d[ch] = 0;

                        }
                    }
                    else if (ch != par) return false;
                }
            }
            return true;
        };
    
        for(int i = 0; i < M; ++i){

            if(Bfs(a[i][0], a[i][1]) == false){
                cout << "NO" << '\n';
                goto end;
            }

        }
        if(count(vis.begin(), vis.end(), true) != N){
            cout << "NO\n";
            goto end;
        }
        cout << "YES" << '\n';
        end:;
    }
    return 0;
}

