#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree one based indexing

struct Fenwick{
std::vector<int> T;
int N;
Fenwick(int n): N{n+1}{T.assign(N, 0);};
Fenwick(std::vector<int> &A): Fenwick((int) A.size()){
    for(int i = 0;i<N-1; ++i)update(i, A.at(i));
}
void update(int i, int x){
    for(++i; i < N; i += (i&(-i))) T.at(i) += x;
}
int query(int i){
    int res = 0;
    for(++i; i > 0; i -= (i&(-i))) res += T.at(i);
    return res;
}
int query(int l, int r){
    return (query(r) - query(l-1));
}
int get_element(int i){
    return query(i, i);
}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}