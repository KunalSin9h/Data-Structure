#include <iostream>
using namespace std;
typedef long long ll;

constexpr int N = 510;
constexpr int INF = 1e9;

int  dist[N][N];

int main(){
    for(int i = 0;i<N; ++i){
        for(int j = 0;j<N; ++j){
            if(i==j)continue;
            dist[i][j] = INF;
        }
    }
    int v, e;
    cin >> v >> e;
    // Using Adjacency of Matrix to store graph data
    while(e--){
        int x, y, wt;
        cin >> x >> y >> wt;
        // this case is similar to [k == 0]
        dist[x][y] = wt;
    }
    /*
    for(int i = 1;i<=v; ++i){
        for(int j = 1;j<=v; ++j){
            if(dist[i][j] == INF)cout<< "#" << " " ;
            else  cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    */

    // k -->> Level allowed 1->v(all vertex)
    for(int k = 1;k <= v; ++k){
        for(int i = 1;i<=v; ++i){
            for(int j  = 1;j<=v ;++j){
                if(dist[i][k] != INF && dist[k][j] != INF) // to handel -ive values
                    dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j])); // ha ha ha...
            }
        }
    }
    for(int i = 1;i<=v; ++i){
        for(int j = 1;j<=v; ++j){
            if(dist[i][j] == INF)cout<< "#" << " " ;
            else  cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}