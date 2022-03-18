#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T;cin >> T;
    while(T--){
        int N;cin >> N;
        vector<vector<int>> Fenwick(N, vector<int>(N));

        auto update = [&](int x, int y, int val)->void{
            for(int i = x;i < N; i = (i|(i+1)))for(int j = y; j<N; j = (j|(j+1))) Fenwick[i][j] += val;
        };

        auto sum = [&](int x, int y)->int{
            int res = 0;
            for(int i = x; i>=0; i = (i&(i+1)) - 1)for(int j = y; j>=0; j=(j&(j+1)) -1) res += Fenwick[i][j];
            return res;
        };

        auto range_sum = [&](int x1, int y1, int x2, int y2)->int{
            return (sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1));
        };

        auto get_element = [&](int x, int y)->int{
            return range_sum(x, y, x, y);    
        };

        string q;
        int a, b, v, x1, y1, x2, y2;
        while(true){
            cin >> q;
            if(q == "SET"){
                cin >> a >> b >> v;
                int el = get_element(a, b);
                update(a, b, -el);
                update(a, b, v);
            }
            else if (q == "SUM"){
                cin >> x1 >> y1 >> x2 >> y2;
                cout << range_sum(x1, y1, x2, y2) << '\n';
            }
            if(q == "END")break;
        }
    }
    return 0;
}
