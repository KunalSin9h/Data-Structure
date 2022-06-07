#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Cycle Detection Using DFS on directed and Unweighted Graph
// may or may not contains components graph can be weighted!. 
//
// vis_streak[i] -> is `i` is visited in the current streak of nodes

int main(){

    int v, e;cin >> v >> e;

    vector<vector<int>> graph(v);

    while(e--){
        int x, y;
        cin >> x >> y;
        x--;y--;
        graph[x].emplace_back(y);
    }

    vector<bool> vis(v, false);

    function<bool(int)> DFS = [&](int s)->bool{
        static vector<bool> vis_streak(v, false);

        vis[s] = vis_streak[s] = true;

        for(int ch : graph[s]){
                
            if(!vis[ch]){
                if(DFS(ch)) return true;
            }
            else if (vis_streak[ch])return true;
            /**
             * this is called "Back Edge"
             **/
        }

        vis_streak[s] = false;
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

