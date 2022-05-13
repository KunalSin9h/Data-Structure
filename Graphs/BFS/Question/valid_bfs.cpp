#include "bits/stdc++.h"
using namespace std;

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges){
	vector<vector<int>> g(n);

	for(int i = 0; i < n - 1; ++i){
		int u = edges[i][0];
		int v = edges[i][1];
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> dist(n, 0);
	vector<bool> vis(n, false);

	queue<int> q({0});
	vis[0] = true;
	int mx = 0;
	while(!q.empty()){
		int a = q.front();
		cout << a << ' ';
		q.pop();
		for(int &c : g[a]){
			if(!vis[c]){
				vis[c] = true;
				dist[c] = dist[a] + 1;
				mx = max(mx, dist[c]);
				q.push(c);
			}
		}
	}
	cout << '\n';

	vector<set<int>> yt(mx+1);

	for(int i = 0; i < n; ++i){
		yt[dist[i]].insert(i);
	}
	dbg(yt);	
	for(int &i : sequence)i--;
	int i = 0;
	for(auto &st : yt){
		int k = st.size();
		set<int> temp;
		while(i < n && k > 0){
			temp.insert(sequence[i]);
			k--;
			i++;
		}
		if(st != temp){
			return false;
		}
	}

	return true;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n = 6;
	vector<int> s{1, 5, 6, 4, 3, 2};
	
	vector<vector<int>> e{{1, 5}, {1, 6}, {5, 4}, {6, 3}, {4, 2}};

	cout << validBfs(n, s, e) << '\n';

	return 0;
}
