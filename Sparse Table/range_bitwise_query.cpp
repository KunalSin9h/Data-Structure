#include "bits/stdc++.h"
using namespace std;

// Q : AND[l...r]

// we can also do OR/XOR in the same way

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;cin >> N;
    int LOG = log2(N) + 1;
    vector<vector<int>> st(N, vector<int>(LOG));

    for(int i = 0; i < N; ++i){
        cin >> st[i][0];
    }

    for(int j = 1; j <= LOG; ++j){
        for(int i = 0; i + (1 << j) - 1 < N; ++i){
            st[i][j] = (st[i][j-1]&st[i + (1 << (j-1))][j-1]);
        }
    }

    auto query = [&](int l ,int r)->int{
        int res = INT_MAX;
        while(l <= r){
            int hp = 31 - __builtin_clz((r - l + 1));
            res &= st[l][hp];
            l += (1 << hp);
        }
        return res;
    };

    int Q;
    cin >> Q;
    while(Q--){
        int L, R;
        cin >> L >> R;
        cout << query(L , R) << '\n';
    }

    return 0;
}