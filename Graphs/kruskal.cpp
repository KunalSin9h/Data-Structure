#include <bits/stdc++.h>
using namespace std;

// Union - Find (Disjoint Set)
struct union_find{
private:
    vector<int> parent, rank;
public:
    union_find(int n){ 
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i = 0;i<n; ++i){parent[i] = i;}
    }
    int find(int x){
        if(parent[x] == x)return x;
        else return  parent[x] =  find(parent[x]);
    }
    void unite(int x, int y){
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
	// Implementing Kruskal's Algo. to find the minimum spanning tree
	int v, m;
	cin >> v >> m;
	vector<array<int, 3>> graph(m);
	for(int i = 0;i<m; ++i)
		cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
	
	sort(begin(graph), end(graph));

	union_find gp(v);
	int minimum_wt = 0;

	for(auto &[wt, a, b]: graph){
		if(!gp.same(a, b)){
			minimum_wt += wt;
			gp.unite(a, b);
		}
	}
	cout << minimum_wt << nl;
	
	return 0;
}

