#include <iostream>
using namespace std;

typedef long long ll;

// Disjoint Set Data-Structure
struct union_find{
private:
    vector<int> parent, rank;
public:
    union_find(int n){ // Constructor to make n seperate elements
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i = 0;i<n; ++i){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x)return x;
        else return  parent[x] =  find(parent[x]);
    }

    void union(int x, int y){
        x = find(x), y = find(y);
        if(x == y)return;
        if(rank[x] < rank[y]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            if(rank[x] == rank[y])rank[x]++;
        }
    }
    bool same(int x, int y){
        return find(x) == find(y);
    } 
};

int main(){
    int n, m;
    cin >> n>> m;
    union_find u(n);
    vector<int> cnt(n);
    while(m--){
        int a, b;
        cin >> a >> b;a--;b--; // 0-based indixing
        cnt[a]++;cnt[b]++;
        if(u.same(a, b)){
            cout << "No" << nl;
            exit(0);
        }
        u.union(a, b);
    }

    for(int i = 0;i<n; ++i){
        if(cnt[i] > 2){
            cout << "No" << nl;
            exit(0);
        }
    }

    cout << "Yes" << nl;
    return 0;
}