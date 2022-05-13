#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvt;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;

void dfs(int i, int j ,const vvt &grid, vector<vector<bool>> &vis, int &temp /*⚠️ */){
    temp++;
    vis[i][j] = true;
    
    for(int a = 0; a < 4; ++a){
        if(i + dx[a] >= 0 && i + dx[a] < n && j + dy[a] >= 0 && j + dy[a] < m){
            if(!vis[i+dx[a]][j+dy[a]] && grid[i+dx[a]][j+dy[a]] == 1){
                dfs(i + dx[a], j + dy[a], grid, vis, temp);
            }
        }
    } 
       
}

int maxAreaOfIsland(vvt grid){
    n = grid.size();
    m = grid[0].size(); 

    vector<vector<bool>> vis(n, vector<bool>(m));

    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0;j < m; ++j){
            if(!vis[i][j] && grid[i][j] == 1){ // ⛔️
                int temp = 0;
                dfs(i, j, grid, vis, temp);
                ans = max(temp, ans);
            }
        }
    }

    return ans; 
}

int main(){
    
    vvt grid = {
        {1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 1, 0}
    };

    cout << maxAreaOfIsland(grid) << '\n';

    return 0;
}

