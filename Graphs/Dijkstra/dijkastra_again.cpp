#include <iostream>
using namespace std;

constexpr int INF = INT_MAX;

typedef long long ll;

void Dijkstra(int source, int N){
    vector<int> Cost(N, INF);
    vector<int> Visit(N, 0);

    set<pair<int, int>> st;
    st.insert({0, source});
    Cost[source] = 0;
    while(st.size() > 0){
        auto &[wt, ind] = *st.begin();
        if(visit[ind])continue;
        visit[ind] = 1;
        st.erase(st.begin());
        for(auto &[child_ind, child_wt] : graph[ind]){
            if(wt + child_wt < Cost[child_ind]){
                Cost[child_ind] = wt+child_wt;
                st.insert({child_wt, child_ind});
            }
        }
    }
}

int main(){
    
    return 0;
}