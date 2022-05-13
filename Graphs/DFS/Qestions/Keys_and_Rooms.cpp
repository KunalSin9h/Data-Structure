#include <iostream>
#include <vector>
using namespace std;

void dfs(int s, vector<vector<int>> &rooms, vector<bool> &vis){
    vis[s] = true;
    for(int i : rooms[s]){
        if(!vis[i]){
            dfs(i, rooms, vis);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>> rooms) {
    int n = rooms.size();
    vector<bool> vis(n, false);
    
    dfs(0, rooms, vis);

    for(int i = 0; i < n; ++i){
        if(!vis[i])return false;
    }
    return true;
}

int main(){
    
    vector<vector<int>> rooms{{}}

    return 0;
}

