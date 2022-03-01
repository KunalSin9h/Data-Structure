#include <bits/stdc++.h>
using namespace std;

/*
* Given a Permutation of number [1, N]
* find the inversion count
*/ 

struct Fenwick{
std::vector<int> T;
int N;
Fenwick(int n):N{n}{T.assign(N, 0);}
Fenwick(std::vector<int> &A): Fenwick((int) A.size()){
    for(int i = 0; i < N; ++i) add(i, A[i]);
}
void add(int i, int x){
    assert(i < N);
    for(; i < N; i = (i | (i + 1))) T[i] += x;
}
int sum(int r){
    assert(r < N);
    int res = 0;
    for(; r >= 0; r = (r&(r+1)) - 1) res += T[r];
    return res;
}
int sum(int l, int r){
    return sum(r) - sum(l-1);
}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;cin >> N;
    vector<int> P(N);
    for(int &i: P){
        cin >> i;
        i--;
    }
    Fenwick F(N);
    int inv = 0;
    for(auto it = P.crbegin(); it < P.crend(); ++it){ // it -> const_reverse_iterator
        inv += F.sum(*it);
        F.add(*it, 1);
    }
    cout << inv << '\n';
    return 0;
}