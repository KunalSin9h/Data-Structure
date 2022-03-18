#include <bits/stdc++.h>
using namespace std;

using std::cin;
using std::cout;

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int N;std::cin >> N;
    vector<int> A(N);for(int &i:A)cin >> i;
    vector<int> vis;
    {
        vector<int> compress = A;
        sort(compress.begin(), compress.end());
        compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
        vis.resize((int)compress.size(), -1);
        for(int i = 0;i<N; ++i){
            A[i] = int(lower_bound(compress.begin(), compress.end(), A[i]) - compress.begin());
        }
    }
    
    vector<int> T(N, 0);

    auto update = [&](int i, int x)->void{
        for(; i < N; i = i|(i+1)) T[i] += x;
    };

    auto sum = [&](int i)->int{
        int res = 0;
        for(; i >= 0; i = (i&(i+1)) - 1) res += T[i];
        return res;
    };
    auto range_sum = [&](int l, int r)->int{
        return (sum(r) - sum(l-1));
    };
    int Q;cin >> Q;
    vector<array<int, 3>> query(Q);
    for(int i = 0;i<Q; ++i){
        int l, r;
        cin >> l >> r;
        l--;r--;
        query[i][0] = l;
        query[i][1] = r;
        query[i][2] = i;
    }
    sort(query.begin(), query.end(), [&](array<int, 3> p, array<int, 3> q)->bool{
        return p[1] < q[1];
    });
    int q_cnt = 0;
    vector<int> Ans(Q);
    for(int i = 0;i<N; ++i){
        if(vis[A[i]] != -1){
            update(vis[A[i]], -1);
        } 
        vis[A[i]] = i;
        update(i, 1);
        while(query[q_cnt][1] == i){
            int l = query[q_cnt][0];
            int r = query[q_cnt][1];
            int ind = query[q_cnt][2];
            Ans[ind] = range_sum(l, r);
            q_cnt++;
        }
    }
    for(int i = 0;i<Q; ++i){
        cout << Ans[i] <<  '\n';
    }
    return 0;
}
