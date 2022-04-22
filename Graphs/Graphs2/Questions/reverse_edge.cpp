#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    int v, e;
    cin >> v >> e;
    // Directed Graph
    vector<pair<int, int>> graph[v+1];  
    while(e--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back({y, 0});
        graph[y].push_back({x, 1});
    }

    
    
    return 0;
}