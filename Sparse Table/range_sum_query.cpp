#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;cin >> N;
    vector<int> A(N);
    int LOG = log2(N) + 1;
    vector<vector<int>> st(N, vector<int>(LOG));

    for(int i = 0; i < N; ++i){
        cin >> A[i];
        st[i][0] = A[i];
    }

    for(int j = 1; j <= LOG; ++j){
        for(int i = 0; i + (1 << j) - 1 < N; ++i){
            st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j-1];
        } 
    }

    auto query = [&](int l,int r)->int{
        int sum = 0;
        while(l <= r){
            int hp = 31 - __builtin_clz((r - l + 1));
            sum += st[l][hp];
            l += (1 << hp);
        }
        return sum;
    };

    int Q;cin >> Q;
    while(Q--){
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << '\n';
    }
    return 0;
}