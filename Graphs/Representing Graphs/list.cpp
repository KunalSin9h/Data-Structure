// List means vectors
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int N = 1e3 + 10;
vector<int> graph[N];
// if have to store wt also then insted of takeing vector of int take vector of pairs

int main(){
    int v, e, q;
    cin >> v >> e;
    while(e--){
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    for(int i = 0;i<v; ++i){
        cout << i << " -> ";
        for(int &el: graph[i])
            cout << el << " ";
        cout << endl;
    }
    
    // Finding the answer to "It there a connecion between i and " is expensive
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        string ans;
        for(int &i: graph[x]){
            if(i == y){
                ans = "YES";
                break;
            }
            ans = "NO";
        }
        cout << ans << endl;
    }
   
    
    return 0;
}