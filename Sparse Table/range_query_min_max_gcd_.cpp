#include "bits/stdc++.h"
using namespace std;

/** Min - Max - GCD **/

/**
 * RMQ : Range Minimum Query
 * Time = O(NlogN)    +    O(1) -> O(NlogN + Q)
 *         ^ PreProcess     ^ query
 **/

/** Key:
 *  Only need to know minimum of every seq. of lenght power of 2 i.e 1, 2, 4, 8, 16 : logN
 *
 *  Brute Force idea : for every index i(0, 1, 2, 3, .... N - 1) store the min of all lenght j(1, 2, 3,... N) i.e m[i][j] : O(N^2) 
 *  
 *  Optimize idea : for every index i(0, 1, 2, 3, .... N - 1) store the min of all lenght 2^j(1, 2, 4, 8, 16... log2N) i.e m[i][j] : O(NlogN)
 **/

/**
 * O(1) query can be supported for "Idempotence Functions" i.e like min/max/gcd in which we have no problem if 
 * segment are overlaping
 *  
 * were as in non "Idempotence Functions" like sum/AND/OR/XOR we can not find if segment are overlap thus we 
 * need O(logn)
 * 
 **/

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;cin >> N;
    vector<int> A(N);
    int LOG = log2(N) + 1;
    vector<vector<int>> m(N, vector<int>(LOG));
    // m[i][j] -> min of seq. starting from i and with lenght 2^j


    for(int i = 0; i < N; ++i){
        cin >> A[i];
        m[i][0] = A[i];
    }

    for(int j = 1; j <= LOG; ++j){
        for(int i = 0; i + (1 << j) - 1 < N; ++i){
            m[i][j] = std::min(m[i][j-1], m[i + (1 << (j-1))][j-1]);
            //m[i][j] = std::max(m[i][j-1], m[i + (1 << (j-1))][j-1]);
            //m[i][j] = std::gcd(m[i][j-1], m[i + (1 << (j-1))][j-1]);
        }
    }

    int Q;
    cin >> Q;

    while(Q--){
        int L, R;
        cin >> L >> R;
        int d = R - L + 1;
        int p = 31 - __builtin_clz(d);
        cout << std::min(m[L][p], m[R - (1 << p) + 1][p]) << '\n';
        //cout << std::max(m[L][p], m[R - (1 << p) + 1][p]) << '\n';
        //cout << std::gcd(m[L][p], m[R - (1 << p) + 1][p]) << '\n';
    }

    return 0;
}