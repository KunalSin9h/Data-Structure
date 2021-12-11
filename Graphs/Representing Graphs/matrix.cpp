#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e3 + 10;
int graph[N][N];

int main(){
    int v, e, q;// q- for queries to find is there connecion between i and 
    cin >> v >> e;
    while(e--){
        int i, j;
        cin >> i >> j;
        graph[i][j] = 1;
        graph[j][i] = 1;// becouse it is undirected graph
        // and if wt is also given put wt in place of 1
    } 
    for(int i = 0;i<v; ++i){
        for(int j = 0;j<v; ++j)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    cin >> q;
    while(q--){
        // O(1) -> Merit of Matrix representation
        int x, y; cin >> x >>y;
        if(graph[x][y] != 0)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}