#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// DFS
bool dfs(int vertex, vector<int> graph[], bool visited[], int parent){
    visited[vertex] = true;
    for(int &conn: graph[vertex]){
        if(visited[conn] == true && conn == parent)continue;
        if(visited[conn]){
            return true;
        }
        visited[conn] = true;
        dfs(conn, graph, visited, vertex);
    }
    return false;
}
int main(){
    int v, e;
    cin >> v >> e;

    vector<int> graph[v+1];
    while(e--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    // Visited array 
    bool visited[v+1] = {false};


    for(int vet = 1;vet<=v; ++vet){
        if(visited[vet])continue;
        if(dfs(vet, graph, visited, 0)){
            cout << true << endl;
            exit(0);
        }
    }
    print(1);
    cout << false << endl;

    return 0;
}