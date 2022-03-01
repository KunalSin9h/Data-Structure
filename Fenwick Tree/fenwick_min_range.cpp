#include<bits/stdc++.h>
using std::cerr;
using std::string;
using std::pair;
/*
*   Finding minimum of [0, r] in one-dimensional array(Range Minimun Query)
*/

struct FenwickMin{
std::vector<int> T;
int N;
const int inf = int(1e9);
FenwickMin(int n):N{n}{T.assign(N, inf);}
FenwickMin(std::vector<int> &A): FenwickMin((int)A.size()){
    for(int i = 0;i<N; ++i) update(i, A[i]);
}
void update(int i, int x){
    for(; i<N; i = (i | (i + 1))) T[i] = std::min(T[i], x);
}
int getmin(int r){
    int res = inf;
    for(; r >= 0; r = (r&(r+1))-1) res = std::min(res, T[r]);
    return res;
}
};

#ifndef  ONLINE_JUDGE
#include "C:\Debug.h"
#else
#define dbg(x...) 
#endif

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int N;std::cin >> N;
    std::vector<int> A(N);
    for(int &i: A)std::cin >> i;


    FenwickMin F(A);
    dbg(F.T);
    int Q;std::cin >> Q;
    while(Q--){
        int a;std::cin >> a;
        a--;
        std::cout << F.getmin(a) << '\n' << std::flush;
    }
    return 0;
}