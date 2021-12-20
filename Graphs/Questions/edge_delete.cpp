#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

void dfs(int v, int p, vector<int> graph[], ll prefix[], ll wt[]){
	prefix[v] += wt[v];
	for(int child: graph[v]){
		if(child == p)continue;
		dfs(child, v, graph, prefix, wt);
		prefix[v] += prefix[child];
	}

}

constexpr int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	int v;cin >>v;
	int e = v - 1;
	vector<int> graph[v+1];
	while(e--){
		int x, y;
		cin >> x >>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	ll wt[v+1];
	for(int i = 1;i<=v; ++i){
		cin >> wt[i];
	}
	ll prefix[v+1];
	dfs(1, 0, graph, prefix, wt);
	
	ll ans = 0LL;
	ll sum_first = prefix[1];	
	for(int i = 2;i<=v; ++i){
		ll sum_v = prefix[i];
		ll rem = sum_first - sum_v;
		ans = max(ans, ((sum_v%MOD)*(rem%MOD))%MOD);
	}
	
	cout << ans << nl;
	

   return 0;
}

