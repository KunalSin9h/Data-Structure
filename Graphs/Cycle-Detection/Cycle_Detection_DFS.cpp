#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Cycle Detection Using DFS on Undirected and Unweighted Graph
// may or may not contains components

int main(){
    
    int vertices, edges;
    cin >> vertices >> edges;
        
    std::vector<std::vector<int>> graph(vertices);    

    while(edges--){
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    std::vector<bool> vis(vertices, false);

    function<bool(int , int)> DFS = [&](int s, int p)->bool{
        vis[s] = true;
        for(int ch : graph[s]){
            if(!vis[ch]){
                if(DFS(ch, s)) return true;
            }
            else if (ch != p){
                return true;
            }
        }
        return false;
    };

    for(int i = 0; i < vertices; ++i){
        if(!vis[i]){
            if(DFS(i, -1)){
                cout << "YES" << '\n';
                goto end;
            }
        }

    }

    cout << "NO" << '\n'; 
    end:;    
    return 0;
}
