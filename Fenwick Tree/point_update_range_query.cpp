#include <bits/stdc++.h>
using namespace std;

/*
 * A Binary Indexed (Fenwick) Tree is a data structure that 
 * provides efficient methods for implementing dynamic cumulative frequency tables
 */

struct Fenwick{
std::vector<int> T;
int N;
Fenwick(int n):N{n}{T.assign(N, 0);}
Fenwick(std::vector<int> &A): Fenwick((int) A.size()){
    for(int i = 0; i < N; ++i) add(i, A[i]);
}
void add(int i, int x){
    for(; i < N; i = (i | (i + 1))) T.at(i) += x;
}
int sum(int r){
    int res = 0;
    for(; r >= 0; r = (r&(r+1)) - 1) res += T.at(r);
    return res;
}
int sum(int l, int r){
    return sum(r) - sum(l-1);
}
int get_element(int i){
    return sum(i, i);
}
};


int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<int> A{1, 2, 3, 4, 5};

    Fenwick F(A);

    return 0;
}
