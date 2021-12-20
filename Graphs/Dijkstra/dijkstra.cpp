#include <iostream>
#include <queue> // for priority queue
using namespace std;

typedef long long ll;

constexpr int N = 1e5;
constexpr int INF = 1e9 + 10;

vector<pair<int, int>> graph[N]

void dijkstra(int source){
    vector<int> dis(N, INF);
    vector<int> vis(N, 0);

    //std::priority_queue<pair<int, int>> pq;
    set<pair<int, int>> st;

    st.insert({0, source});
    dis[source] = 0;

    while(st.size() > 0){
        auto &[wt, node] = *st.begin();
        st.erase(st.begin());
        if(vis[node])continue;
        vis[node] = 1;
        for(auto &[child_ind, child_wt]: graph[node]){
            if(wt+child_wt < dis[child_ind]){
                dis[child_ind] = wt+child_wt;
                st.insert({child_wt, child_ind});
            }
        }
    }
}



int main(){

    int n, m;
    cin >> n >> m;

    while(m--){
        int x,y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
    }

    dijkstra(1); // Single Source --> find the shortest distance of every node from 1

    return 0;
}