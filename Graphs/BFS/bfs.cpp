#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

// BFS is not a recursive function
void bfs(int v, vector<int> graph[], int visited[], int level[]){
    visited[v] = 1;
    level[v] = 0;
    queue<int> bfsq;
    bfsq.push(v);
    while(!bfsq.empty()){
        int curr_node = bfsq.front();
        cout << curr_node << " ";
        bfsq.pop();
        for(int &child: graph[curr_node]){
            if(!visited[child]){
                bfsq.push(child);
                visited[child] = 1;
                level[child] = level[curr_node] + 1;
            }
        }
    }
    cout << endl;
}



int main(){
    int v;cin >> v;
    int e = v - 1;
    // Using Adjacency list to store graph data
    vector<int> graph[v+1];
    while(e--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int visited[v+1] = {0};
    int level[v+1] = {0}; 

    bfs(1, graph, visited, level);

    for(int i  = 1;i<=v; ++i){
        cout << i << ": " << level[i] << endl;
    }

    return 0;
}