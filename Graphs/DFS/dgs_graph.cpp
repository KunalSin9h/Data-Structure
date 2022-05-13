#include <iostream>
#include <vector>
using namespace std;

/**
 * Dfs : Depth First Search
 * Time : O(v + e)
 **/

void dfs(int source, auto &gr, auto &vis){
    cout << source << '\n';
    vis[source] = true;

    for(int child : gr[source]){
        if(!vis[child]){
            dfs(child, gr, vis);
        }
    }
    return;
}

int main(){

    int v, e;
    cin >> v >> e;

    vector<vector<int>> gr(v);

    while(e--){
        int x, y;
        cin >> x >> y;
        x--;y--;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    vector<bool> vis(v, false);

    dfs(0, gr, vis);

    // Do dfs and print each node
    
    return 0;
}