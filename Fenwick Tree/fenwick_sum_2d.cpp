#include <bits/stdc++.h>
/*
*  f(r): Finding sum in two-dimensional array
*/

struct Fenwick2D{
std::vector<std::vector<int>> T;
int N, M;
Fenwick2D(int r, int c): N{r}, M{c}{
    T.resize(N);
    for(int i = 0;i<N; ++i)T[i].resize(M, 0);
}
Fenwick2D(std::vector<std::vector<int>> &A): Fenwick2D((int)A.size(), (int)A[0].size()){
    for(int i = 0;i<N; ++i) for(int j = 0;j<M; ++j)  add(i, j, A[i][j]);
}
void add(int r, int c, int x){
    for(; r < N; r = (r | (r+1))) for(; c < M; c = (c | (c +1))) T[r][c] += x;
}
int sum(int r, int c){
    int res = 0;
    for(; r >= 0; r = (r&(r+1)) - 1) for(; c >= 0; c = (c&(c+1)) - 1) res += T[r][c];
    return res;
}
};

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    return 0;
}