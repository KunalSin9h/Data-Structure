#include <bits/stdc++.h>
using namespace std;

/*
*   # Floyd Warshall Algorithm is used to find shotest path for every pair of node
* Given a directed or an undirected weighted graph with vertices. 
* The task is to find the length of the shortest path between each pair of vertices.
*/

/*
* This algorithm can also be used to detect the presence of negative cycles. 
* The graph has a negative cycle if at the end of the algorithm, the distance from a vertex to itself is negative. d[i][i] = -ive
*/

constexpr int inf = int(1e9);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, E;cin >> N >> E;
    vector<vector<int>> d(N, vector<int>(N, inf));

    while(E--){
        int x, y;
        cin >> x >> y;
        d[x][y] = 1;
        d[y][x] = 1;
    }

    for(int i = 0;i<N; ++i){
        d[i][i] = 0;
    } 

 
   for(int k = 0; k < N; ++k){
        for(int i = 0;i<N; ++i){
            for(int j = 0;j<N; ++j){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    /*
    If There are negative weight are ther
    for(int k = 0; k < N; ++k){
        for(int i = 0;i<N; ++i){
            for(int j = 0;j<N; ++j){
                 if(d[i][k]< inf && d[k][j] < inf)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    */

    return 0;
}