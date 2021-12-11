#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// DFS
void dfs(int vertex, vector<int> graph[], bool visited[], vector<int> &curr_component){
    visited[vertex] = true;
    curr_component.push_back(vertex);
    for(int &conn: graph[vertex]){
        if(visited[conn])continue;
        visited[conn] = true;
        dfs(conn, graph, visited, curr_component);
    }

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
 
    vector<vector<int>> connected_component;
    vector<int> curr_component;
    int count = 0; // How many connected components in given graph
    for(int vet = 1;vet<=v; ++vet){
        if(visited[vet])continue;
        curr_component.clear();
        dfs(vet, graph, visited, curr_component);
        connected_component.push_back(curr_component);
    }

    cout << connected_component.size() << endl;
    for(auto &vec: connected_component){
        for(int &i: vec){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}