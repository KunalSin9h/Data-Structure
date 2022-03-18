#include <bits/stdc++.h>
using namespace std;

struct Fenwick{
std::vector<int> T;
int N;
Fenwick(int n):N{n+1}{T.assign(N, 0);}
Fenwick(std::vector<int> &A): Fenwick((int) A.size()){
    for(int i = 0; i < N-1; ++i) point_update(i, A[i]);
}
void update(int i, int x){ // Not Point Update
    for(++i; i < N; i += (i&(-i))) T.at(i) += x;
}
void range_update(int l, int r, int x){
    update(l, x);
    update(r+1, -x);
}
void point_update(int i, int x){
    range_update(i, i, x);
}
int point_query(int i){
    int res = 0;
    for(++i; i > 0; i -= (i&(-i))) res += T.at(i);
    return res;
}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<int> A{1, 1, 1, 1, 1};
    Fenwick F(A);

    F.range_update(0, 2, 500);

    cout << F.point_query(0) << '\n';
    cout << F.point_query(1) << '\n';
    cout << F.point_query(2) << '\n';
    cout << F.point_query(3) << '\n';
    cout << F.point_query(4) << '\n';

    return 0;
}