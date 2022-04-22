#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void dfs(int i, int j, int initColor, int newColor, vector<vector<int>> &image){
    int n = image.size();
    int m = image[0].size();
    if(i < 0 || j < 0) return ;
    if(i >= n || j >= m) return ;
    if(image[i][j] != initColor)return ;

    image[i][j] = newColor;
    dfs(i-1, j, initColor, newColor, image);
    dfs(i+1, j, initColor, newColor, image);
    dfs(i, j-1, initColor, newColor, image);
    dfs(i, j+1, initColor, newColor, image);

}

vector<vector<int>> floodfill(vector<vector<int>> image, int sr, int sc, int newColor){
    int initColor = image[sr][sc];
    if(initColor != newColor)
        dfs(sr, sc, initColor, newColor, image);
    return image;
}

int main(){
    int n, m;
    // n -> row
    // m -> col
    cin >> n >> m;
    vector<vector<int>> image(n+1);
    for(int i = 1;i<=n; ++i){
        vector<int> temp(m + 1);
        for(int j = 1;j<=m; ++j){
            int x; cin >> x;
            temp[j] =  x;
        }
        image.push_back(temp);
    }
         
    return 0;
}