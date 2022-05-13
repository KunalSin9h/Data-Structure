#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Cycle Detection Using DFS on directed and Unweighted Graph
// may or may not contains components
//
// vis_family[i] -> is `i` is visited in the current streak of nodes(...family)

int main(){

    int v, e;cin >> v >> e;

    vector<vector<int>> graph(v);

    while(e--){
        int x, y;
        cin >> x >> y;
        x--;y--;
        graph[x].push_back(y);
    }

    vector<bool> vis(v, false);

    function<bool(int)> DFS = [&](int s)->bool{
        static vector<bool> vis_family(v, false);
        vis[s] = vis_family[s] = true;
        
        for(int ch : graph[s]){
                
            if(!vis[ch]){
                if(DFS(ch)) return true;
            }
            else if (vis_family[ch])return true;
             
        }

        vis_family[s] = false;
        return false;

    };

    for(int i = 0; i < v; ++i){
        if(!vis[i]){
            if(DFS(i)){
                cout << "YES! Cycle Exist.." << endl;
                goto end;
            }
        }
    }
    cout << "NO" << endl;
    end:;
    return 0;
}

